#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


int main() 
{
    std::ifstream in_file {"romeoandjuliet.txt"};
    std::ofstream out_file {"romeoandjuliet_out.txt"};
    
    if (!in_file)
    {
        std::cerr << "Problem opening input file" << std::endl;
        return 1;
    }
    
    if (!out_file)
    {
        std::cerr << "Problem opening output file" << std::endl;
        return 1;
    }
    
    int i {0};
    std::string line {};
    while (std::getline(in_file, line))
    {
        if (line.length() > 0)
        {   
            i++;
            out_file << std::setw(10) << std::left << i << line << std::endl;
        }
        else
        {
            out_file << std::endl;
        }
    }
    
    std::cout << "File Copied" << std::endl;
    
    in_file.close();
    out_file.close();
    
    
    return 0;
}