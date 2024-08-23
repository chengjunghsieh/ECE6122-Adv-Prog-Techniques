/*
Author:  Jeff Hurley
Date last modified: 1/22/2019
Organization: ECE2036 Class

Description:

Simple application to monitor back accounts
    
*/
#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

int main()
{
    Account myAccount;
    Account myChecking("Checking");   
    Account mySavings("Savings", "100 Main St., MyCity, 12345");   
    Account myCollegeFund{"College", "100 Main St., MyCity, 12345", 100.0f};   

    myChecking.addDeposit(100.0f);
    myChecking.makeWithdrawal(-50.0);
    myChecking.PrintTransactionHistory();
    return 0;
}