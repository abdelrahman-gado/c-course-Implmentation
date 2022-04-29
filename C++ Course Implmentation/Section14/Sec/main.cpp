#include <iostream>
#include <bitset>


using namespace std;

bool is_prime (int num)
{
    if (num == 1)
    {
        return true;
    }
   
    for (int i {2}; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
        else if (i == num/2)
        {
            return true;
        }
    }
    
    return true;
}

int main() 
{
    int num_tests {};
    cin >> num_tests;
    
    for (int i {0}; i < num_tests; i++)
    {
        int n {};
        cin >> n;
        if (is_prime(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    


    return 0;
}