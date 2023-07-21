#include"declaration.h"
#include"Account.h"
#include"add_func.h"
#include"class_branch.h"

Account::Account(Branch *br,string n,string db,string ad,string ty):name(n),dob(db),address(ad),type(ty) {
    cust_id=count++;
    add_account(br,cust_id,this,type);
}
Account::Account(Branch *br,int cust_id1,string ty)
{
    name=br->Accounts[cust_id1][0]->get_name();
    cust_id=br->Accounts[cust_id1][0]->get_cust_id();
    dob=br->Accounts[cust_id1][0]->get_dob();
    address=br->Accounts[cust_id1][0]->get_address();
    type=ty;
    add_account(br,cust_id,this,type);
}
string Account::get_name()
{
    return name;
}

string Account::get_dob()
{
    return dob;
}

string Account::get_address()
{
    return address;
}
int Account::get_cust_id() const 
{
    return cust_id;
}
void Account::calculateInterest()
{
    cout<<"Not available"<<endl;
}
int Account::withdraw(int amt)
{
    cout<<"Not available"<<endl;
    return 0;
}
int Account::deposit(int amt)
{
    cout<<"Not available"<<endl;
    return 0;
}
int Account::count = 1;