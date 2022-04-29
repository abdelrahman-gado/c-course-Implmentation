#include "Saving_Account.h"
#include <iostream>

Saving_Account::Saving_Account()
    : int_rate {3.0}
{
    
}

Saving_Account::~Saving_Account()
{
    
}


void Saving_Account::deposit (double amount)
{
    std::cout << "Saving Account deposit called with " << amount << std::endl;
}


void Saving_Account::withdraw (double amount)
{
    std::cout << "Saving Account withdraw called with " << amount << std::endl;
}
