#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
        std::cout << "Problem opening output file" << std::endl;
        return 1;
    }
    
    int i {0};
    std::string line {};
    while (std::getline(in_file, line))
    {
        i++;
        out_file << std::setw(10) << std::left << i << line << std::endl;
    }
    
    std::cout << "File Copied" << std::endl;
    
    in_file.close();
    out_file.close();
    
    return 0;
}