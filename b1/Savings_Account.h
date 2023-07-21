#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include"Account.h"
#include"declaration.h"
class Savings_Account : public Account {
private:
    int savings_ac_no;
    float savings_bal;
    static int count;


public:
    DebitCard* obj_card;
    Savings_Account(Branch* br, string name, string dob, string address, float open_bal);

    Savings_Account(Branch* br, int cust_id1, string type, float open_bal);

    int withdraw(int amount);

    int deposit(int amount);

    void display();
};
#endif