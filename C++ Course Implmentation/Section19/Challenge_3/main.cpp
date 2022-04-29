#include <iostream>
#include <fstream>
#include <string>


int main() 
{
    
    std::ifstream in_file {"romeoandjuliet.txt"};
    
    if (!in_file)
    {
        std::cerr << "Problem Opening File" << std::endl;
        return 1;
    }
    
    std::string wanted_substr {};
    std::cout << "Enter the substring to search for: ";
    std::cin >> wanted_substr;
    
    int count_words {};
    int count_found_substr {};
    std::string word {};
    
    while (in_file >> word)
    {
        count_words++;
        if (word.find(wanted_substr) != std::string::npos)
        {
            count_found_substr++;
        }
        
    }
    
    std::cout << count_words << " words were searched..." << std::endl;
    std::cout << "The substring " << wanted_substr << " was found " << count_found_substr << " times" << std::endl;
    
    in_file.close();
    
    return 0;
}