#ifndef CLASS_BANK_H
#define CLASS_BANK_H
#include<map>
#include"declaration.h"
using namespace std;
class Bank {
    private:
    string bank_name;
    string headquarters;
    public:
    map<string,Branch*> branches;
    Bank(string n,string h);
    Bank();
    friend int add_branch(Bank *a,Branch *b);
};
#endif