#include <iostream>
#include <cctype>
#include <stack>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>

std::string clean_string (std::string str)
{
    std::string cleaned_str {};
    for (char c : str)
    {
        if (std::isalpha(c))
        {
            c = std::toupper(c);
            cleaned_str.push_back(c);
        }
    }
    return cleaned_str;
}


bool is_palindrome (const std::string& s)
{
    std::string str = clean_string(s);
    std::stack<char> st;
    std::queue<char> qu;
    std::for_each(str.begin(), str.end(), 
        [&st, &qu](char c) 
        { st.push(c);
          qu.push(c); });
    
    

    while (!st.empty() && !qu.empty())
    {
        if (st.top() != qu.front())
        {
            return false;
        }
        
        st.pop();
        qu.pop();
        
    }
    
    return true;
}



int main() 
{
    std::vector<std::string> test_strings { "a", "aa", "aba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"
    };
    
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto &s : test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    
    return 0;
}