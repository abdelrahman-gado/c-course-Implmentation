#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <iomanip>

// Display the word and count from the
// std::map<std::string, int>
void display_words (const std::map<std::string, int> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord"
        << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "==========================================" << std::endl;
    for (auto pair : words)
    {
        std::cout << std::setw(12) << std::left << pair.first
            << std::setw(7) << std::right << pair.second << std::endl;
    }
}


// Used for part2
// Display the word and occurances from tyhe
// std::map<std::string, std::set<int>>
void display_words (const std::map<std::string, std::set<int>> &words)
{
    std::cout << std::setw(12) << std::left << "\nWord"
        << "Occurrences" << std::endl;
    std::cout << "=============================================================" << std::endl;
    for (auto pair : words)
    {
        std::cout << std::setw(12) << std::left << pair.first << std::left << "[ ";
        for (auto i : pair.second)
        {
            std::cout << i << " ";
        }
        std::cout << "]" << std::endl;
    }
}

// This function removes periodsm commas, semicolons and colon in
// a string and return the clean version
std::string clean_string (const std::string &s)
{
    std::string result;
    for (char c : s)
    {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += c;
    }
    return result;
}



// Part1 process the file and builds a map of words and the
// number of times they occur in the file
void part1()
{
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream in_file {"words.txt"};
    if (in_file)
    {
        while (std::getline(in_file, line))
        {
            std::stringstream sstream {line};
            while (sstream >> word)
            {
                std::string cleaned_word = clean_string(word);
                words[cleaned_word] += 1;
            }
            
        }
        
        in_file.close();
        display_words(words);
    }
    else
    {
        std::cerr << "Error opening input file" << std::endl;
    }
}




// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2()
{
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream in_file {"words.txt"};
    int line_number {0};
    if (in_file)
    {
        
        while (std::getline(in_file, line))
        {
            line_number++;
            std::stringstream sstream {line};
            while (sstream >> word)
            {
                std::string cleaned_word = clean_string(word);
                words[cleaned_word].insert(line_number);
            }
            
        }
        
        in_file.close();
        display_words(words);
    }
    else
    {
        std::cerr << "Error opening input file" << std::endl;
    }
    
    
}


int main() 
{
    part1();
    part2();
    return 0;
}