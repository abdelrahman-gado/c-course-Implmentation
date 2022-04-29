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

void func(std::shared_ptr<Test> p)
{
    std::cout << "Use count: " << p.use_count() << std::endl;
}


int main() 
{
    // use_count - the number of shared_ptr objects
    // managing the heap object
//    std::shared_ptr<int> p1 {new int {100}};
//    std::cout << "Use count: " << p1.use_count() << std::endl;  // 1
//    
//    std::shared_ptr<int> p2 {p1}; // copy constructor
//    std::cout << "Use count: " << p1.use_count() << std::endl; // 2
//    std::cout << "Use count: " << p2.use_count() << std::endl; // 2
//    
//    p1.reset();
//    std::cout << "Use count: " << p1.use_count() << std::endl;  // 0
//    std::cout << "Use count: " << p2.use_count() << std::endl; // 1


//    cout << "\n =============================================================" << endl;
//    
//    std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
//    func(ptr);  // Copying is allowed
//    std::cout << "Use count: " << ptr.use_count() << std::endl; // 1
//    {
//        std::shared_ptr<Test> ptr1 = ptr;
//        std::cout << "Use count: " << ptr.use_count() << std::endl;  // 2
//        std::cout << "Use count: " << ptr1.use_count() << std::endl; // 2
//        {
//            std::shared_ptr<Test> ptr2 = ptr;
//            std::cout << "Use count: " << ptr.use_count() << std::endl; // 3
//            std::cout << "Use count: " << ptr1.use_count() << std::endl; // 3
//            std::cout << "Use count: " << ptr2.use_count() << std::endl; // 3
//            ptr.reset();
//        }
//        std::cout << "Use count: " << ptr.use_count() << std::endl;  // 0
//        std::cout << "Use count: " << ptr1.use_count() << std::endl; // 1
//    }
//    std::cout << "Use count: " << ptr.use_count() << std::endl; // 0
    
    // ptr1 will be responsible for cleaning the heap storage beacuse it is the last pointer referencing the object.
    
    cout << "\n =============================================================" << endl;
    
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account> ("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account> ("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account> ("Curly", 6000);
    
    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    
    for (const auto &acc : accounts)
    {
        std::cout << *acc << std::endl;
        std::cout << "Use count: " << acc.use_count() << std::endl; // 2
    }
    
    
    return 0;
}