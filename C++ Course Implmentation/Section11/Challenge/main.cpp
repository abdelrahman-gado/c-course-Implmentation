#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>

using namespace std;

void display();
char get_selection();
void print_list(const vector<int> &list);
bool exists(const vector<int> &list, int element);
void add_element(vector<int> &list, int element);
void clear_list(vector<int> &list);
void number_occurance(const vector<int> &list, int target);
double mean(const vector<int> &list);
int smallest(const vector<int> &list);
int largest(const vector<int> &list);


int main() 
{
    vector<int> list {21, -1, 22, 24};
    
    char selected {};
    
    do
    {   
        display();
        cout << "Enter your choice: ";
        selected = get_selection();
        
        switch (selected)
        {
            case 'P':
                print_list(list);
                break;
            
            
            case 'E':
            {   
                int target {0};
                cout << "Enter an integer that you want its occurance: ";
                cin >> target;
                number_occurance(list, target);
                break;
            }
            case 'A':
            {   
                int added_int {0};
                cout << "Enter an integer to add to the list: ";
                cin >> added_int;
                add_element(list, added_int);
                break;
            }
            case 'C':
            {
                clear_list(list);
                cout << "The list is cleared" << endl;
                break;
            }
            case 'M':
            {   
                if (list.size() > 0)
                {
                    cout << fixed << setprecision(1);
                    cout << "The mean is : " << mean(list) << endl;
                }
                else
                {
                    cout << "Unable to calculate the mean - no data" << endl;
                }
                
                break;
            }
            case 'S':
            {   
                if (list.size() > 0)
                {
                    cout << "The smallest number is " << smallest(list) << endl;
                }
                else
                {
                    cout << "Unable to determine the smallest number - list empty" << endl;
                }
                break;
            }
            case 'L':
            {
                if (list.size() > 0)
                {
                    cout << "The largest number is " << largest(list) << endl;
                }
                else
                {
                    cout << "Unable to determine the largest number - list empty" << endl;
                }
                break;
                
            }
            case 'Q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown selection, please try again" << endl;
        }
        
        
    }
    while (selected != 'Q');
    
    
    
    return 0;
}


void display()
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
    
}

char get_selection()
{
    char character {};
    cin >> character;
    return toupper(character);
}

void print_list(const vector<int> &list)
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
    
}


bool exists(const vector<int> &list, int element)
{
    for (auto var : list)
    {
        if (var == element)
        {
            return true;
        }
    }
    return false;
    
}

void add_element(vector<int> &list, int element)
{
    
    bool flag = exists(list, element);
    if (!flag)
    {                
        list.push_back(element);
        cout << element << " added" << endl;
    }
    else
    {
        cout << "Can't add the number " << element << " , the number exists in the list" << endl;
    }
    
}

void clear_list(vector<int> &list)
{
    list.clear();
}

void number_occurance(const vector<int> &list, int target)
{
    bool found = exists(list, target);
    if (found)
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
    
}

double mean(const vector<int> &list)
{
    
    int total {0};
    for (auto var : list)
    {
        total += var;
    }
    
    return static_cast<double>(total) / list.size();
}

int smallest(const vector<int> &list)
{
    int smallest {list.at(0)};
    for (auto var : list)
    {
        if (var < smallest)
        {
            smallest = var;
        }
    }
    
    return smallest;
}

int largest(const vector<int> &list)
{
    
    int largest {list.at(0)};
    for (auto var : list)
    {
        if (var > largest)
        {
            largest = var;
        }
    }
    return largest;
}