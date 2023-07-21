#ifndef PPF_ACCOUNT_H
#define PPF_ACCOUNT_H

#include "Account.h" 
#include"declaration.h"

class PPF_Account : public Account
{
private:
    int ppf_acc_no;
    float ppf_balance;
    int c = 0;
    static int count;

public:
    PPF_Account(Branch* br, std::string name, std::string dob, std::string address, float open_bal);
    PPF_Account(Branch* br, int cust_id1, float open_bal);
    int deposit(int amount);
    void display();
    void calculateInterest();
};

#endif // PPF_ACCOUNT_H
