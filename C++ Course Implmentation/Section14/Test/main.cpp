#include <iostream>
#include <iomanip>

using namespace std;

void concat (int A[], int B[], int arr[], int n)
{
    for (int i {}; i < n+n; i++)
    {
        if (i >= n)
        {
            arr[i] = A[i-n];
        }
        else
        {
            arr[i] = B[i];
        }
        
    }
    
}


int main() 
{
    int n {};
    cin >> n;
    
    int A[n];
    int B[n];
    
    int n_n_size = n+n;
    int arr[n_n_size];
    
    for (int i {}; i < n; i++)
    {
        cin >> A[i];
    }
    
    for (int i {}; i < n; i++)
    {
        cin >> B[i];
    }
    
    concat(A, B, arr, n);
    
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}