#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

int main() 
{
    cout.precision(2);
    cout << fixed;
    
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000});
    accounts.push_back(Account {"Curly", 5000});
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    
    // Savings
    
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {});
    sav_accounts.push_back(Savings_Account {"Superman"});
    sav_accounts.push_back(Savings_Account {"Batman", 2000});
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0});
    
    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    
    
    // Checking_Accounts
    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account {});
    check_accounts.push_back(Checking_Account {"Kirk"});
    check_accounts.push_back(Checking_Account {"Spock", 2000});
    check_accounts.push_back(Checking_Account {"Bones", 5000});
    
    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);
    
    
    // Trust_Account
    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {});
    trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0});
    trust_accounts.push_back(Trust_Account {"Porthos", 20000, 4.0});
    trust_accounts.push_back(Trust_Account {"Aramis", 30000});
    
    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    
    for (int i {}; i <= 5; i++)
        withdraw(trust_accounts, 1000);
    
    
//    Savings_Account hello {"Abdo", 20000, 0.0};
//    hello += 5000;
//    cout << hello.get_balance() << endl;
    
//    hello -= 2000;
//    cout << hello.get_balance() << endl;
//    
//    
//    cout << endl;
//    Trust_Account hi {"Magdy", 10000};
//    hi -= 1000;
//    cout << hi.get_balance() << endl;
//    
//    hi += 2000; 
//    cout << hi.get_balance() << endl;
//    
//    cout << endl;
//    Checking_Account check {"Muhammed", 30000};
//    check += 2000;
//    
//    check -= 2000;
//    cout << check.get_balance() << endl;
//    
//    cout << endl;
//    Account Gado {"Gado", 3000};
//    Gado += 3000;
//    
//    Gado -= 3000;
//    cout << Gado.get_balance() << endl;
    
    return 0;
}