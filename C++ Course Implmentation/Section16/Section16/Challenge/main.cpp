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
    
    Checking_Account frank {"Frank", 5000};
    cout << frank << endl;
    
    Account *trust = new Trust_Account("James");
    cout << *trust << endl;
    
    Account *p1 = new Checking_Account("Larry", 10000);
    Account *p2 = new Savings_Account("Moe", 1000);
    Account *p3 = new Trust_Account("Curly");
    std::vector<Account *> accounts {p1, p2, p3};
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    display(accounts);
    
    

    Savings_Account s {"Frank", 5000, 2.6};
    cout << s << endl;
    s.deposit(10000);
    cout << s << endl;
    s.withdraw(10000);
    cout << s << endl;

    Account *ptr = new Trust_Account("Leo", 10000, 2.6);
    cout << *ptr << endl;
    
    // Savings
    
    vector<Account *> sav_accounts;
    sav_accounts.push_back(new Savings_Account {});
    sav_accounts.push_back(new Savings_Account {"Superman"});
    sav_accounts.push_back(new Savings_Account {"Batman", 2000});
    sav_accounts.push_back(new Savings_Account {"Wonderwoman", 5000, 5.0});
    
    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    
    
    // Checking_Accounts
    vector<Account  *> check_accounts;
    check_accounts.push_back(new Checking_Account {});
    check_accounts.push_back(new Checking_Account {"Kirk"});
    check_accounts.push_back(new Checking_Account {"Spock", 2000});
    check_accounts.push_back(new Checking_Account {"Bones", 5000});
    
    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);
    
    
    // Trust_Account
    vector<Account *> trust_accounts;
    trust_accounts.push_back(new Trust_Account {});
    trust_accounts.push_back(new Trust_Account {"Athos", 10000, 5.0});
    trust_accounts.push_back(new Trust_Account {"Porthos", 20000, 4.0});
    trust_accounts.push_back(new Trust_Account {"Aramis", 30000});
    
    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);
    
    
    for (int i {}; i <= 5; i++)
        withdraw(trust_accounts, 1000);
        
    
    
    return 0;
}