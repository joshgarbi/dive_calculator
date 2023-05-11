/* foo.cpp
 * To compile and run:
 *  - Install gtkmm-3.0 and pkg-config
 *  - windres src/gui/icon.rc -O coff -o src/gui/icon.res; g++ -Wall -mwindows -o divecalculator-win.exe src/gui.cpp src/rnt_data_table.cpp src/RNT.cpp src/decomp.cpp src/gui/icon.res `pkg-config gtkmm-3.0 --cflags --libs`; ./gui
 *  - Alternatively, run make windows
 * 
 * Written by Paul Hartman (code review by [name] on [date])
 * 
 */
// GTK includes
#include <gtkmm.h>

// stdlib includes
#include <iostream>
#include <string>
#include <regex>

// local module includes
#include "rnt_data_table.h"
#include "RNT.h"
#include "decomp.h"

class DiveCalculator {
	public:
	int sizex, sizey;
	Gtk::Window* mainwindow = nullptr;
	repetgroup::data* repet_group_handler = new repetgroup::data();
	Residual_time* rnt_handler = new Residual_time();
	

	DiveCalculator(int argc, char** argv, int sizex, int sizey) {
		app = Gtk::Application::create(argc, argv);
		auto builder = Gtk::Builder::create_from_file("src/gui/main_gui.glade");

		this->sizex = sizex;
		this->sizey = sizey;

		// Initialize widgets
		builder->get_widget("MainWindow", mainwindow);
		builder->get_widget("dive1_timeEntry", diveOneTimeEntry);
		builder->get_widget("dive2_timeEntry", diveTwoTimeEntry);
		builder->get_widget("dive2_timeDiffHourEntry", diveTwoTimeDiffHourEntry);
		builder->get_widget("dive2_timeDiffMinuteEntry", diveTwoTimeDiffMinuteEntry);
		builder->get_widget("dive1_depthEntry", diveOneDepthEntry);
		builder->get_widget("dive2_depthEntry", diveTwoDepthEntry);
		builder->get_widget("dive1_resultsRepet", diveOneResultsRepet);
		builder->get_widget("dive2_resultsRepet", diveTwoResultsRepet);
		builder->get_widget("dive2_resultsRNT", diveTwoResultsRNT);
		builder->get_widget("dive1_resultsDecompStops", diveOneResultsDecompStops);
		builder->get_widget("dive2_resultsDecompStops", diveTwoResultsDecompStops);
		builder->get_widget("dive2_timeEntryRNTLabel", diveTwoTimeEntryRNTLabel);

		// Attach handlers
		diveOneTimeEntry->signal_changed().connect(sigc::mem_fun(this, &DiveCalculator::diveOneTimeEntryChanged));
		diveTwoTimeEntry->signal_changed().connect(sigc::mem_fun(this, &DiveCalculator::diveTwoTimeEntryChanged));
		diveTwoTimeDiffHourEntry->signal_changed().connect(sigc::mem_fun(this, &DiveCalculator::diveTwoTimeDiffHourEntryChanged));
		diveTwoTimeDiffMinuteEntry->signal_changed().connect(sigc::mem_fun(this, &DiveCalculator::diveTwoTimeDiffMinuteEntryChanged));
		diveOneDepthEntry->signal_changed().connect(sigc::mem_fun(this, &DiveCalculator::diveOneDepthEntryChanged));
		diveTwoDepthEntry->signal_changed().connect(sigc::mem_fun(this, &DiveCalculator::diveTwoDepthEntryChanged));
	}

	int show() {
		mainwindow->set_default_size(sizex, sizey);
		return app->run(*mainwindow);
	}

	private:
	std::string err_msg = "";
	bool diveOneTimeEntryValid = false;
	bool diveTwoTimeEntryValid = false;
	bool diveTwoDiffTimeEntryValid = false;
	bool diveOneDepthEntryValid = false;
	bool diveTwoDepthEntryValid = false;
	std::string diveOneTimeEntryCurrent = "";
	std::string diveTwoTimeEntryCurrent = "";
	std::string diveTwoTimeDiffHourEntryCurrent = "";
	std::string diveTwoTimeDiffMinuteEntryCurrent = "";
	std::string diveOneDepthEntryCurrent = "";
	std::string diveTwoDepthEntryCurrent = "";
	std::regex only_numbers = std::regex("[0-9]*");

	// Declare pointers for GUI components
	Glib::RefPtr<Gtk::Application> app;
	Gtk::Entry* diveOneTimeEntry = nullptr;
	Gtk::Entry* diveTwoTimeEntry = nullptr;
	Gtk::Entry* diveTwoTimeDiffHourEntry = nullptr;
	Gtk::Entry* diveTwoTimeDiffMinuteEntry = nullptr;
	Gtk::Entry* diveOneDepthEntry = nullptr;
	Gtk::Entry* diveTwoDepthEntry = nullptr;
	Gtk::Label* diveOneResultsRepet = nullptr;
	Gtk::Label* diveTwoResultsRepet = nullptr;
	Gtk::Label* diveTwoResultsRNT = nullptr;
	Gtk::Label* diveOneResultsDecompStops = nullptr;
	Gtk::Label* diveTwoResultsDecompStops = nullptr;
	Gtk::Label* diveTwoTimeEntryRNTLabel = nullptr;

	// "Calculate" button event handlers
	// TODO checking to see if RNT groups and decompression stops are needed
	void diveOneUpdated() {
		try {
			int time, depth;
			time = std::stoi(diveOneTimeEntry->get_text());
			depth = std::stoi(diveOneDepthEntry->get_text());
		
			// Calculate REPET group, RNT, and decompression stops
			char repet_group;
			std::vector<std::vector<int>> decompression_stops;
			performDiveOneCalculations(time, depth, repet_group, decompression_stops);

			diveOneResultsRepet->set_text(std::string(1,repet_group));
			if (repet_group_handler->getDEC()) {
				std::string decomp_stops_str;
				for (unsigned int i=0; i < decompression_stops.at(0).size(); i++) {
					decomp_stops_str += ("Stop at " + std::to_string(decompression_stops.at(0).at(i)) + " feet for " + std::to_string(decompression_stops.at(1).at(i)) + " minutes. ");
				}

				diveOneResultsDecompStops->set_text(decomp_stops_str);
			} else {
				diveOneResultsDecompStops->set_text("No decompression stops");
			}
		} catch(const std::exception& err) {
			diveOneResultsRepet->set_text(err_msg);
			diveOneResultsDecompStops->set_text(err_msg);
		}
	}
	void diveTwoUpdated() {
		try {
			int difftimehour = std::stoi(diveTwoTimeDiffHourEntry->get_text());
			int difftimemin = std::stoi(diveTwoTimeDiffMinuteEntry->get_text());
			double difftime = difftimehour + (difftimemin / 100.0);
			int time = std::stoi(diveTwoTimeEntry->get_text());
			int depth = std::stoi(diveTwoDepthEntry->get_text());
		
			// Calculate REPET group, RNT, and decompression stops
			char repet_group;
			int rnt;
			std::vector<std::vector<int>> decompression_stops; // Don't have his code yet
			performDiveTwoCalculations(difftime, time, depth, repet_group, rnt, decompression_stops);

			diveTwoResultsRepet->set_text(std::string(1,repet_group));
			diveTwoResultsRNT->set_text(std::to_string(time) + " + " + std::to_string(rnt) + " = " + std::to_string(time + rnt) + "min");
			diveTwoTimeEntryRNTLabel->set_text("+" + std::to_string(rnt) + "min RNT");
			diveTwoResultsRepet->set_text(std::string(1,repet_group));

			if (repet_group_handler->getDEC()) {
				std::string decomp_stops_str;
				for (unsigned int i=0; i < decompression_stops.at(0).size(); i++) {
					decomp_stops_str += ("Stop at " + std::to_string(decompression_stops.at(0).at(i)) + " feet for " + std::to_string(decompression_stops.at(1).at(i)) + " minutes. ");
				}

				diveTwoResultsDecompStops->set_text(decomp_stops_str);
			} else {
				diveTwoResultsDecompStops->set_text("No decompression stops");
			}
		} catch(const std::exception& err) {
			diveTwoResultsRepet->set_text(err_msg);
			diveTwoResultsRNT->set_text(err_msg);
			diveTwoResultsDecompStops->set_text(err_msg);
		}
	}

	// Num Only Entry changed handlers
	// These handlers are for text validation (numbers only) and
	// are called *after* the text is changed.
	void diveOneTimeEntryChanged() {
		std::string current = diveOneTimeEntry->get_text();
		if (std::regex_match(current, only_numbers)) {
			diveOneTimeEntryCurrent = current;
		} else {
			diveOneTimeEntry->set_text(diveOneTimeEntryCurrent);
		}

		diveOneUpdated();
		diveTwoUpdated();
	}
	void diveTwoTimeEntryChanged() {
		std::string current = diveTwoTimeEntry->get_text();
		if (std::regex_match(current, only_numbers)) {
			diveTwoTimeEntryCurrent = current;
		} else {
			diveTwoTimeEntry->set_text(diveTwoTimeEntryCurrent);
		}
		diveOneUpdated();
		diveTwoUpdated();
	}
	void diveTwoTimeDiffHourEntryChanged() {
		std::string current = diveTwoTimeDiffHourEntry->get_text();
		if (std::regex_match(current, only_numbers)) {
			diveTwoTimeDiffHourEntryCurrent = current;
		} else {
			diveTwoTimeDiffHourEntry->set_text(diveTwoTimeDiffHourEntryCurrent);
		}
		diveOneUpdated();
		diveTwoUpdated();
	}
	void diveTwoTimeDiffMinuteEntryChanged() {
		std::string current = diveTwoTimeDiffMinuteEntry->get_text();
		if (std::regex_match(current, only_numbers)) {
			diveTwoTimeDiffMinuteEntryCurrent = current;
		} else {
			diveTwoTimeDiffMinuteEntry->set_text(diveTwoTimeDiffMinuteEntryCurrent);
		}
		diveOneUpdated();
		diveTwoUpdated();
	}
	void diveOneDepthEntryChanged() {
		std::string current = diveOneDepthEntry->get_text();
		if (std::regex_match(current, only_numbers)) {
			diveOneDepthEntryCurrent = current;
		} else {
			diveOneDepthEntry->set_text(diveOneDepthEntryCurrent);
		}
		diveOneUpdated();
		diveTwoUpdated();
	}
	void diveTwoDepthEntryChanged() {
		std::string current = diveTwoDepthEntry->get_text();
		if (std::regex_match(current, only_numbers)) {
			diveTwoDepthEntryCurrent = current;
		} else {
			diveTwoDepthEntry->set_text(diveTwoDepthEntryCurrent);
		}
		diveOneUpdated();
		diveTwoUpdated();
	}

	// FIXME figure out type of decompression_stops. need his code anyways, wait til it's ready
	void performDiveOneCalculations(int time, int depth, char& repet_group, std::vector<std::vector<int>>& decompression_stops) {
		repet_group = repet_group_handler->get_Nrnt_grp(depth, time);
		
		if (repet_group_handler->getDEC()) {
			// Need to calculate decompression stops
			decompression_stops = calculateStops(time, depth);
		}
	}
	void performDiveTwoCalculations(double difftime, int time, int depth, char& second_repet_group, int& rnt, std::vector<std::vector<int>>& decompression_stops) {
		char first_repet_group = diveOneResultsRepet->get_text().at(0); // Repet group of first dive

		rnt = rnt_handler->RNT(first_repet_group, difftime, depth);
		
		int new_time = time + rnt;

		second_repet_group = repet_group_handler->get_Nrnt_grp(depth, new_time);

		if (repet_group_handler->getDEC()) {
			// Need to calculate decompression stops
			decompression_stops = calculateStops(new_time, depth);
		}
	}
};

int main(int argc, char** argv)
{
	auto calc = DiveCalculator(argc, argv, 600, 400);
	return calc.show();
}