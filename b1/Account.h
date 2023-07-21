#ifndef ACCOUNT_H
#define ACCOUNT_H
#include"declaration.h"
class Account{
    protected:
    string name;
    int cust_id;
    string dob;
    string address;
    string type;
    static int count;
    public:
    virtual void display()=0;
    virtual int withdraw(int amt);
    virtual int deposit(int amt);
    virtual void calculateInterest();
    Account(Branch *br,string n,string db,string ad,string ty);
    Account(Branch *br,int cust_id1,string ty);
    string get_name();
    string get_dob();
    string get_address();
    int get_cust_id() const;
};
#endif