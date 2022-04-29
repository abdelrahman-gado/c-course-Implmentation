#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int n {};
    cin >> n;
    string s {};
    cin >> s;
    int s_len = s.length();
    
    int score {};
    
    for (int i {}; i < s_len; i++)
    {
        char ch = s[i];
        if (ch == 'V')
        {
            score += 5;
        }
        else if (ch == 'W')
        {
            score += 2;
        }
        else if (ch == 'X' && i != s_len-1)
        {
            i++;
        }
        else if (ch == 'Y' && i != s_len-1)
        {
            s.push_back(s[i+1]);
            i++;
            s_len++;
        }
        else if (ch == 'Z' && i != s_len-1)
        {
            if (s[i+1] == 'V')
            {
                score /= 5;
                i++;
            }
            else if (s[i+1] == 'W')
            {
                score /= 2;
                i++;
            }
        }
        
        
    }
    
    cout << score << endl;
    
    
    return 0;
}