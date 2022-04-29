#include <iostream>

using namespace std;

int main() 
{
    char selection {};
    
    do
    {
        cout << "\n---------------------" << endl;
        cout << "1. DO this " << endl;
        cout << "2. DO that " << endl;
        cout << "3. DO something else " << endl;
        cout << "Q. Quit" << endl;
        cout << "\nEnter your selction: ";
        cin >> selection;
        
//        if (selection == '1')
//        {
//            cout << "your chose 1 - doing this" << endl;
//        }
//        else if (selection == '2')
//        {
//            cout << "your chose 2 - doing that" << endl;
//        }
//        else if (selection == '3')
//        {
//            cout << "your chose 3 - doing something else" << endl;
//        }
//        else if (selection == 'Q' || selection == 'q')
//        {
//            cout << "Goodbye..." << endl;
//        }
//        else
//        {
//            cout << "Unknown option---try again" << endl;
//        }

        switch (selection)
        {
            case '1':
                cout << "your chose 1 - doing this" << endl;
                break;
            case '2':
                cout << "your chose 2 - doing that" << endl;
                break;
            case '3':
                cout << "your chose 3 - doing something else" << endl;
                break;
            case 'q':
            case 'Q':
                cout << "Goodbye..." << endl;
                break;
            default:
                cout << "Unknown option---try again" << endl;
        }


    }while (selection != 'q' && selection != 'Q');
    
    return 0;
}