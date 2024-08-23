/*
Author:  Jeff Hurley
Date last modified: 1/18/2019
Organization: ECE2036 Class

Description:

Simple class to hold bank account information
    
*/
#pragma once  // This statement should be at the top of every header file.
              // This statement causes a check to occur that will keep the code in this file from being inserted more than once 
              // when compiling a single cpp file.

#include <string>


#define MAX_NUMBER_ACTIVITY 10000 // Preprocessor directive: MAX_NUMBER_ACTIVITY is replaced with 10000 before compiling
const int m_MAX_NUMBER_DEPOSITS = 10000; // Normal convention
int const m_MAX_NUMBER_DEPOSITS2 = 10000; // Still works but not as common   

using namespace std;

class Account
{
public:
    Account(); // Default constructor
    // The keyword constant here will cause a compile error if the function tries to change the value of the input parameter.
    explicit Account(const string &strName);
    Account(const string &strName, const string &strAddress);
    Account(const string &strName, const string &strAddress, const float &fInitialValue);

    void setAccountName(const string &strName) {m_strAccountName = strName;}
    const string& getAccountName() const {return m_strAccountName;}

    void setAddress(const string &strAddress) {m_strAddress = strAddress;}
    const string& getAddress() const {return m_strAddress;}

    const float& getBalance() const {return m_fBalance;}
    const long& getNumTransactions() const {return m_lNumberofTransactions;}

    bool addDeposit(const float &fDeposit);
    bool makeWithdrawal(const float &fWithdrawal);

    void PrintTransactionHistory();

private:
    float m_fActivity[m_MAX_NUMBER_DEPOSITS];
    long m_lNumberofTransactions;
    string m_strAccountName;
    string m_strAddress;
    float m_fBalance;

};