#ifndef CURRENT_ACCOUNT_H
#define CURRENT_ACCOUNT_H

#include "Account.h" 
#include"declaration.h"
class Current_Account : public Account
{
private:
    int current_acc_no;
    float current_bal;
    float overdraft_limit;
    static int count;

public:
    Current_Account(Branch* br, std::string name, std::string dob, std::string address, float open_bal);
    Current_Account(Branch* br, int cust_id1, float open_bal);
    int withdraw(int amount);
    int deposit(int amount);
    void applyOverdraft(float limit);
    void display();
    void calculateInterest();
};

#endif 
