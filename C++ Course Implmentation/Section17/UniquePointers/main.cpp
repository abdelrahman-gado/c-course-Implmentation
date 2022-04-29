// Unique Pointers

#include <memory>
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

class Test
{
private:
    int data;
    
public:
    Test() : data {0} { cout << "Test Constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { cout << "Test Constructor (" << data << ")" << std::endl; }
    int get_data() const {return data;}
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
    
};

int main() 
{
//    Test *t1 = new Test(1000);
//    delete t1;

//    std::unique_ptr<Test> t1 {new Test {100}};
//    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);
//    
//    std::unique_ptr<Test> t3;
//    //t3 = t1;       // assign is not allowed
//    t3 = std::move(t1);   // t1 will be nullptr
//    
//    if(!t1)
//    {
//        cout << "t1 is nullptr" << endl;
//    }
//    

//    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account> ("Moe", 5000);   // Base Class Pointer
//    std::cout << *a1 << endl;
//    a1->deposit(5000);
//    std::cout << *a1 << std::endl;
//    
//    
//    std::vector<std::unique_ptr<Account>> accounts;
//    
//    accounts.push_back(std::make_unique<Checking_Account>("James", 1000));
//    accounts.push_back(std::make_unique<Savings_Account> ("Billy", 4000, 5.2));
//    accounts.push_back(std::make_unique<Trust_Account> ("Bobby", 5000, 4.5));
//    
//    for (const std::unique_ptr<Account> &acc : accounts)
//    {
//        cout << *acc << endl;
//    }
    
    std::unique_ptr<int> up = std::make_unique<int>(10);
    cout << *up << endl;    // 10
    
    int *ptr = up.get();
    *ptr += 1;
    
    cout << *up << endl;  // 11
    cout << *ptr << endl; // 1
    

    return 0;
}