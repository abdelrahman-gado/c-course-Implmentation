#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() 
{
    vector<int> list {21, -1, 22, 24};
    
    char selected {};
    
    do
    {   
        cout << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "C - clear the list" << endl;
        cout << "E - Display number of occurance of a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl << endl;
        
        cout << "Enter your choice: ";
        cin >> selected;
        
        switch (selected)
        {
            case 'p':
            case 'P':
            {
                if (list.size() > 0)
                {
                    cout << "[ ";
                    
                    for (auto var : list)
                    {
                        cout << var << ' ';
                    }
                    cout << "]" << endl;
                }
                else
                {
                    cout << "[] - the list is empty" << endl;
                }
                break;
            }
            case 'e':
            case 'E':
            {   
                int target {0};
                cout << "Enter an integer that you want its occurance: ";
                cin >> target;
                bool found {false};
                for (auto var : list)
                {
                    if (var == target)
                    {
                        found = true;
                        break;
                    }
                }
                
                if (found == true)
                {   
                    cout << "the number is found in the list..." << endl;
                    int count {0};
                    for (auto var : list)
                    {
                        if (var == target)
                        {
                            count++;
                        }
                    }
                    cout << "the count of " << target << " is " << count << endl;
                }
                else
                {
                    cout << "Sorry, that number does not exist in the list" << endl;
                }
                break;
            }
            case 'A':
            case 'a':
            {   
                int added_int {0};
                cout << "Enter an integer to add to the list: ";
                cin >> added_int;
                bool exists {false};
                
                for (auto var : list)
                {
                    if (added_int == var)
                    {
                        exists = true;
                        break;
                    }
                }
                
                if (!exists)
                {                
                    list.push_back(added_int);
                    cout << added_int << " added" << endl;
                }
                else
                {
                    cout << "Can't add the number " << added_int << " , the number exists in the list" << endl;
                }
                break;
            }
            case 'c':
            case 'C':
            {
                list.clear();
                cout << "The list is cleared" << endl;
                break;
            }
            case 'M':
            case 'm':
            {   
                if (list.size() > 0)
                {
                    int total {0};
                    for (auto var : list)
                    {
                        total += var;
                    }
                    
                    cout << fixed << setprecision(1);
                    cout << "The mean is : " << static_cast<double>(total) / list.size() << endl;
                }
                else
                {
                    cout << "Unable to calculate the mean - no data" << endl;
                }
                
                break;
            }
            case 'S':
            case 's':
            {   
                if (list.size() > 0)
                {
                    int smallest {list.at(0)};
                    for (auto var : list)
                    {
                        if (var < smallest)
                        {
                            smallest = var;
                        }
                    }
                    cout << "The smallest number is " << smallest << endl;
                }
                else
                {
                    cout << "Unable to determine the smallest number - list empty" << endl;
                }
                break;
            }
            case 'L':
            case 'l':
            {
                if (list.size() > 0)
                {
                    int largest {list.at(0)};
                    for (auto var : list)
                    {
                        if (var > largest)
                        {
                            largest = var;
                        }
                    }
                    cout << "The largest number is " << largest << endl;
                }
                else
                {
                    cout << "Unable to determine the largest number - list empty" << endl;
                }
                break;
                
            }
            case 'Q':
            case 'q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
        }
        
        
    }
    while (selected != 'q' && selected != 'Q');
    
    
    
    return 0;
}