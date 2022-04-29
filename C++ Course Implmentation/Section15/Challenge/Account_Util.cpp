#include "Account_Util.h"
#include <iostream>


// Display Account objects in a vector of Account Objects
void display (const std::vector<Account> &accounts)
{
    std::cout << "\n=== Accounts ==========================" << std::endl;
    for (const auto &acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Account in the vector
void deposit(std::vector<Account> &accounts, double amount)
{
    std::cout << "\n=== Depositing to Accounts ================" << std::endl;
    for (auto &acc : accounts)
    {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl; 
    }
    
}

// Withdraw amount from each Account object in the vector
void withdraw (std::vector<Account> &accounts, double amount)
{
    std::cout << "\n=== Withdrawing from Accounts ===================" << std::endl;
    for (auto &acc : accounts)
    {
        if (acc.withdraw(amount))
            std::cout << "Withdraw " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
    
}

// Helper functions for Savings Account class

// Display Savings_Account objects in a vector of Saving_Account objects
void display (const std::vector<Savings_Account> &accounts)
{
    std::cout << "\n=== Savings Accounts===================================" << std::endl;
    for (const auto &acc : accounts)
        std::cout << acc << std::endl;
}

// Display supplied amount to each Savings Account object in the vector
void deposit (std::vector<Savings_Account> &accounts, double amount)
{
    std::cout << "\n=== Depositing to Savings Accounts =========================" << std::endl;
    for (auto &acc : accounts)
    {
        if (acc.deposit(amount))
            std::cout << "Deposited" << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl;
    }
    
}


// Display supplied amount from each Savings Account object in the vector
void withdraw (std::vector<Savings_Account> &accounts, double amount)
{
    std::cout << "\n=== Withdrawing from Savings_Account ===============================" << std::endl;
    for (auto &acc : accounts)
    {
        if (acc.withdraw(amount))
        {
            std::cout << "Withdrew " << amount << " from " << acc << std::endl;
        }
        else
        {
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
        }
        
    }
    
}

// Display Checking_Account objects in a vector of Checking_Account Objects
void display (const std::vector<Checking_Account> &accounts)
{
    std::cout << "\n=== Checking_Accounts ==========================" << std::endl;
    for (const auto &acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Checking_Account in the vector
void deposit(std::vector<Checking_Account> &accounts, double amount)
{
    std::cout << "\n=== Depositing to Checking_Accounts ================" << std::endl;
    for (auto &acc : accounts)
    {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl; 
    }
    
}

// Withdraw amount from each Checking_Account object in the vector
void withdraw (std::vector<Checking_Account> &accounts, double amount)
{
    std::cout << "\n=== Withdrawing from Checking_Accounts ===================" << std::endl;
    for (auto &acc : accounts)
    {
        if (acc.withdraw(amount))
            std::cout << "Withdraw " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
    
}


// Display Checking_Account objects in a vector of Checking_Account Objects
void display (const std::vector<Trust_Account> &accounts)
{
    std::cout << "\n=== Trust_Accounts ==========================" << std::endl;
    for (const auto &acc : accounts)
        std::cout << acc << std::endl;
}

// Deposits supplied amount to each Trust_Account in the vector
void deposit(std::vector<Trust_Account> &accounts, double amount)
{
    std::cout << "\n=== Depositing to Trust_Accounts ================" << std::endl;
    for (auto &acc : accounts)
    {
        if (acc.deposit(amount))
            std::cout << "Deposited " << amount << " to " << acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << acc << std::endl; 
    }
    
}

// Withdraw amount from each Trsut_Account object in the vector
void withdraw (std::vector<Trust_Account> &accounts, double amount)
{
    std::cout << "\n=== Withdrawing from Trust_Accounts ===================" << std::endl;
    for (auto &acc : accounts)
    {
        if (acc.withdraw(amount))
            std::cout << "Withdraw " << amount << " from " << acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
    }
    
}