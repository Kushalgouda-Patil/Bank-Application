#ifndef LOAN_ACCOUNT_H
#define LOAN_ACCOUNT_H

#include "Account.h" 
#include"declaration.h"
class Loan_Account : public Account
{
private:
    int loan_number;
    float loan_amount;
    float interest_rate;
    float monthly_payment;
    static int count;

public:
    Loan_Account(Branch* br, string name, string dob, string address, float amt, float ir);
    Loan_Account(Branch* br, int cust_id1, float amt, float ir);
    void display();
    int deposit(float amount);
};

#endif // LOAN_ACCOUNT_H
