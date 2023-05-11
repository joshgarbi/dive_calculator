#include "rnt_data_table.h"
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <sstream>

namespace repetgroup {
    char data::get_Nrnt_grp(int depth, int time)
    {
        std::vector<std::vector<int>> Nrnt_grp = getData();
        this->Dec = false;
        // round depth to nearest multiple of 5
        if (depth < 10)
        {
            depth = 10;
        }
        // round to nearest multiple of 5 for depths less than 60
        if ((depth < 60) && (depth >= 10))
        {
            while (depth % 5 != 0)
            {
                depth += 1;
            }
        }
        // round to the nearest multiple of 10 for numbers greater than 60
        if (depth >= 60)
        {
            while (depth % 10 != 0)
            {
                depth += 1;
            }
        }
        // convert depth to index
        for (unsigned int i = 0; i < depths.size(); i++)
        {
            if ((depths.at(i)) == depth)
            {
                depth = i;
                break;
            }
        }

        int grp = 0;
        bool cont = true;
        // find group time - round to next if greater
        for (unsigned int i = 0; i < Nrnt_grp.at(depth).size(); i++)
        {
            // check if time is already in list
            if (Nrnt_grp.at(depth).at(i) == time)
            {
                grp = i;
                cont = false;
                break;
            }
        }
        for (unsigned int i = 0; i < Nrnt_grp.at(depth).size() - 1; i++)
        {
            // find times that input is between and round greater
            if ((Nrnt_grp.at(depth).at(i) < time) && (time < Nrnt_grp.at(depth).at(i + 1)))
            {
                grp = i + 1;
                cont = false;
                break;
            }
        }
        if (cont)
        {
            // account for time lower than 'A' group
            if (time < Nrnt_grp.at(depth).at(0))
            {
                grp = 0;
            }
            // round depths after first 3 marked with "*"
            if ((time > Nrnt_grp.at(depth).at(Nrnt_grp.at(depth).size() - 1)) && (depth > 2))
            {
                this->Dec = true;
                return Grps.at(15);
            }
            // round times marked with "*"
            if ((time > Nrnt_grp.at(depth).at(Nrnt_grp.at(depth).size() - 1)) && (depth <= 2))
            {
                // ask ethan about "*" rounding
                grp = Nrnt_grp.at(depth).size();
            }
        }
        return Grps.at(grp);
    }

    bool data::getDEC(){
        return this->Dec;
    }



    std::vector<std::vector<int>> getData(){
        std::string fname = "src/rnt_data.csv";
        std::vector<std::vector<int>> content;
        std::vector<int> row;
        std::string line, word;
    
        std::fstream file (fname, std::ios::in);
        if(file.is_open())
        {
            while(getline(file, line))
            {
                row.clear();
    
                std::stringstream str;
                str << line;

                std::stringstream wrd;
        

                while(getline(str, word, ',')) {
                    wrd << word;
                    long int tempword;
                    wrd >> tempword; 
                    wrd.clear();
                    row.push_back(tempword);
                }  
                content.push_back(row);
            }
        }
        else
            std::cout<<"Could not open the file\n";
    
        // for(int i=0;i<content.size();i++)
        // {
        // 	for(int j=0;j<content[i].size();j++)
        // 	{
        // 		std::cout<<content[i][j]<<" ";
        // 	}
        // 	std::cout<<"\n";
        // }
    
        return content;
    }
}