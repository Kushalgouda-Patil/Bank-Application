/*#ifndef BANK_H
#define BANK_H
#endif */
#include<iostream>
#include <map>

using namespace std;

class Bank;
class Branch;
int add_branch(Bank *a,Branch* b);

class Branch{
    string branch_name;
    string IFSC;
    string branch_address;
    public:
    friend int add_branch(Bank *a,Branch *b);
    Branch(string br_name,string ifsc,string br_address,Bank* obj): 
    branch_name(br_name),IFSC(ifsc),branch_address(br_address){   
        add_branch(obj,this);  
    }
    void display()
    {
        cout<<branch_name<<endl<<
        IFSC<<endl<<branch_address<<endl;
    }
};
class Bank {
    private:
    string bank_name;
    string headquarters;
    public:
    map<string,Branch*> branches;
    Bank(string n,string h):bank_name(n),headquarters(h){};
    friend int add_branch(Bank *a,Branch *b);
    
};
int add_branch(Bank *a,Branch* b)
{
    a->branches[b->IFSC]=b;
    return 0;
}
int main(int argc, char const *argv[])
{
    Bank ICICI("icici bank","Delhi");
    Branch dwd("dwd","ICICI000124","Jubilee Circle",&ICICI);
    ICICI.branches["ICICI000124"]->display();

    return 0;
}
