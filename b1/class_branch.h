#ifndef CLASS_BRANCH_H
#define CLASS_BRANCH_H
#include"declaration.h"
#include<map>
class Branch{
    string branch_name;
    string IFSC;
    string branch_address;
    public:
    map<int,vector<Account*>> Accounts;
    friend int add_branch(Bank *a,Branch *b);
    Branch(string br_name,string ifsc,string br_address,Bank* obj);
    void display() const;
};

#endif