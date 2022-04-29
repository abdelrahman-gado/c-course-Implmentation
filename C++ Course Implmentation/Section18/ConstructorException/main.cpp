#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include <memory>
#include "IllegalBalanceExecption.h"


using namespace std;

int main() 
{
    try
    {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
        std::cout << *moes_account << std::endl;
    }
    catch (const IllegalBalanceExecption &ex)
    {
        std::cout << "Sorry, couldn't create moes object - Negative balance" << std::endl;
    }
    
    std::cout << "program finishes successfully" << std::endl;
    
    return 0;
}