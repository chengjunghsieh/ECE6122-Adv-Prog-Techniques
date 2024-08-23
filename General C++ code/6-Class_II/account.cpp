/*
Author:  Jeff Hurley
Date last modified: 1/18/2019
Organization: ECE2036 Class

Description:

Implemenation of Simple class to hold bank account information
    
*/
#include <iostream>
#include <cmath>
#include "account.h"
/******************************************************************/
// Default Constructor
/******************************************************************/
Account::Account():
m_strAccountName("NewAccount"), 
m_strAddress(""), 
m_lNumberofTransactions(0), 
m_fBalance(0.0f)
{
    addDeposit(0.0f);
}
/******************************************************************/
// Constructor with account name
/******************************************************************/
Account::Account(const string &strName):
m_strAccountName(strName), 
m_strAddress(""), 
m_lNumberofTransactions(0), 
m_fBalance(0.0f)
{
    addDeposit(0.0f);
}
/******************************************************************/
// Constructor with account name, address
/******************************************************************/
Account::Account(const string &strName, const string &strAddress):
m_strAccountName(strName),
m_strAddress(strAddress), 
m_lNumberofTransactions(0), 
m_fBalance(0.0f)
{
    addDeposit(0.0f);
}
/******************************************************************/
// Constructor with account name, address, beginning balance
/******************************************************************/
Account::Account(const string &strName, const string &strAddress, const float &fInitialValue):
m_strAccountName(strName),
m_strAddress(strAddress), 
m_lNumberofTransactions(0), 
m_fBalance(0.0f)
{
    addDeposit(fInitialValue);
}
/******************************************************************/
// Adds a deposit to the account
/******************************************************************/
bool Account::addDeposit(const float &fDeposit)
{
    bool bRC = true;
    if (m_lNumberofTransactions+1 < m_MAX_NUMBER_DEPOSITS)
    {
        m_fBalance += fDeposit;
        m_fActivity[m_lNumberofTransactions++] = fDeposit;        
    }
    else
    {
        bRC = false;
        cout << "Error: Exceeded maximum number of transactions!!!" << endl;
    }

    return bRC;
}
/******************************************************************/
// Attempts to make a withdrawal from the account
/******************************************************************/
bool Account::makeWithdrawal(const float &fWithdrawal)
{
    bool bRC = false;

    // First check to see if we have room to store the transaction
    // Make sure the withdrawal is a negative number
    float fNegativeAmount = (fWithdrawal >= 0.0f) ? -fWithdrawal:fWithdrawal;

    // Make sure there is enough money to cover the withdrawal
    if (m_fBalance + fNegativeAmount >= 0.0f )
    {
        bRC = true;
        m_fBalance += fNegativeAmount;
        m_fActivity[m_lNumberofTransactions++] = fNegativeAmount;
    }
    else
    {
        cout << "Error: Insufficient Funds for withdrawal!!\nOnly $" << m_fBalance << " remains in account." << endl;
    }
    return bRC;
 
}
/******************************************************************/
// Prints all the transactions
/******************************************************************/
void Account::PrintTransactionHistory()
{
    cout << "Transactions for Account: " << m_strAccountName << endl;
    for (int kk = 0 ; kk < m_lNumberofTransactions ; kk++)
    {
        if (m_fActivity[kk] < 0.0)
        {
            cout << "Withdrawal of: $" << abs(m_fActivity[kk]) << endl;
        }
        else
        {
            cout << "Deposit of: $" << m_fActivity[kk] << endl;
        }
    }
    cout << "End of Transactions" << endl;
}