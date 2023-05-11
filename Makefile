SRCS = src/gui.cpp src/rnt_data_table.cpp src/RNT.cpp src/decomp.cpp
ICOSRC = src/gui/icon.rc
ICOOBJ = src/gui/icon.res
EXE = "divecalculator-win.exe"
LINEXE = "divecalculator-all"

CXX = g++

# TARGET = all

CXXFLAGS = -std=c++17 -Wall `pkg-config gtkmm-3.0 --cflags --libs`

# $(EXE): $(OBJS)
# 	$(CXX) -o $(EXE) $(OBJS) $(LDFLAGS) $(LIBS)

$(EXE): $(ICOOBJ)
	$(CXX) -o $(EXE) $(SRCS) $(ICOOBJ) $(CXXFLAGS) -mwindows

$(LINEXE):
	$(CXX) -o $(LINEXE) $(SRCS) $(CXXFLAGS)

$(ICOOBJ):
	windres $(ICOSRC) -O coff -o $(ICOOBJ)

others : $(LINEXE)
windows : $(EXE)

all : $(LINEXE)

clean:
	-rm -f $(ICOOBJ)
	-rm -f $(EXE)
	-rm -f $(LINEXE)
	