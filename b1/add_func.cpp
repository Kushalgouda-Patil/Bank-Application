#include"add_func.h"
#include"class_bank.h"
#include"class_branch.h"
int add_branch(Bank *a,Branch* b)
{
    a->branches[b->IFSC]=b;
    return 0;
}

void add_account(Branch *br,int cust_id,Account* ptr,string type)
{
    if(br->Accounts.count(cust_id)==0)
    {
        vector<Account*> arr(7);
    
        br->Accounts[cust_id]=arr;
    }
    if(type=="SB")
        br->Accounts[cust_id][0]=ptr;
    else if(type=="FD")
        br->Accounts[cust_id][1]=ptr;
    else if(type=="CD")
        br->Accounts[cust_id][2]=ptr;
    else if(type=="PPF")
        br->Accounts[cust_id][3]=ptr;
    else if(type=="LA")
        br->Accounts[cust_id][4]=ptr;
    else
        br->Accounts[cust_id][5]=ptr;

}