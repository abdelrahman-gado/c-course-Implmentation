#include <iostream>
#include <string>


using namespace std;


int main() 
{
    cout << "Enter the word: ";
    string letter {};
    cin >> letter;
    int n {letter.length()};
    
    for (int i {0}; i < n; i++)
    {
        for (int j = i-(n-1); j < (i*2 + 1); j++)
        {
            if (j < 0)
            {
                cout << " ";
            }
            else if (j > i)
            {   
                int x = (i*2)-j;
                cout << letter.at(x);
            }
            else
            {
                cout << letter.at(j);
            }
            
        }
        cout << endl;
    }
    
    return 0;
}