#ifndef FIXEDDEPOSIT_ACCOUNT_H
#define FIXEDDEPOSIT_ACCOUNT_H

#include "Account.h" 
#include"declaration.h"
class FixedDeposit_Account : public Account
{
private:
    int fd_acc_no;
    float fd_amount;
    int fd_duration;
    static int count;

public:
    FixedDeposit_Account(Branch* br, string name, string dob, string address, float fd_amt, int dur);
    FixedDeposit_Account(Branch* br, int cust_id1, float fd_amt, int dur);
    void display() override;
    void calculateInterest();
};

#endif 
