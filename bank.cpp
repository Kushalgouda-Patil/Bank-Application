/*
Title-Applicatn Name
TEam Members
Classes-Concept
Design Pattern-> name*/
#include<iostream>
#include<bits/stdc++.h>
#include <map>
#include <ctime>

using namespace std;

class Bank;
class Branch;
class Account;
int add_branch(Bank a,Branch b);

class Branch{
    string branch_name;
    string IFSC;
    string branch_address;
    public:
    friend int add_branch(Bank *a,Branch *b);
    map<int,vector<Account*>> Accounts;
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
int add_branch(Bank* a,Branch* b)
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
    else if(type=="PPF")
        br->Accounts[cust_id][4]=ptr;
    else
        br->Accounts[cust_id][5]=ptr;

}
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
    Account(Branch *br,string n,string db,string ad,string ty):name(n),dob(db),address(ad),type(ty) {
        cust_id=count++;
        add_account(br,cust_id,this,type);
    }
    Account(Branch *br,int cust_id1,string ty)
    {
        name=br->Accounts[cust_id1][0]->get_name();
        cust_id=br->Accounts[cust_id1][0]->get_cust_id();
        dob=br->Accounts[cust_id1][0]->get_dob();
        address=br->Accounts[cust_id1][0]->get_address();
        type=ty;
        add_account(br,cust_id,this,type);
    }
    string get_name()
    {
        return name;
    }
    string get_dob()
    {
        return dob;
    }
    string get_address()
    {
        return address;
    }
    int get_cust_id() const 
    {
        return cust_id;
    }

};
int Account::count = 1;
class DebitCard;
class Savings_Account : public Account {
private:
    int savings_ac_no;
    float savings_bal;
    static int count;
    

public:
    DebitCard* obj_card;
    Savings_Account(Branch* br, string name, string dob, string address, float open_bal)
        : Account(br, name, dob, address, "SB"), savings_bal(open_bal) {
        savings_ac_no = count++;
        obj_card=nullptr;
    }

    Savings_Account(Branch* br, int cust_id1, string type, float open_bal)
        : savings_bal(open_bal), Account(br, cust_id1, type) {
        savings_ac_no = count++;
    }

    int withdraw(int amount) {
        if (savings_bal - amount >= 0) {
            savings_bal -= amount;
            return savings_bal;
        } else {
            throw "Insufficient balance";
        }
    }

    int deposit(int amount) {
        savings_bal += amount;
        return savings_bal;
    }

    void display() {
        cout << "Name: " << name << endl
             << "Date of Birth: " << dob << endl
             << "Customer ID: " << cust_id << endl
             << "Savings Account Number: " << savings_ac_no << endl;
    }
};

// Initialize the static member variable count
int Savings_Account::count = 1000;

class FixedDeposit_Account:public Account
{
    private:
    int fd_acc_no;
    float fd_amount;
    int fd_duration;
    static int count;
    public:
    FixedDeposit_Account(Branch *br,string name,string dob,string address,float fd_amt,int dur):Account(br,name,dob,address,"FD"),fd_amount(fd_amt),fd_duration(dur)
    {
        fd_acc_no=count++;
    }
    FixedDeposit_Account(Branch *br,int cust_id1,float fd_amt,int dur):Account(br,cust_id1,"FD"),fd_amount(fd_amt),fd_duration(dur)
    {
        fd_acc_no=count++;
    }
    void display() override
    {
        cout<<"Fixed Deposit Account"<<endl;
        cout<<"Account Number: "<< fd_acc_no<<endl;
        cout<<"Deposit Amount: "<< fd_amount<<endl;
        cout<<"Duration: " << fd_duration<<"months"<<endl;
    }
    void calculateInterest()
    {
        float interest=fd_amount*0.08;//8%interest rate
        cout<<"Interest earned: "<<interest<<endl;
    }
    
};
int FixedDeposit_Account::count = 1560;
class Current_Account:public Account
{
private:
    int current_acc_no;
    float current_bal;
    float overdraft_limit;
    static int count;
public:
    Current_Account(Branch* br, string name, string dob, string address, float open_bal):current_bal(open_bal),Account(br,name,dob,address,"CD")
    {
        current_acc_no=count++;
        overdraft_limit=1500;
    }
    Current_Account(Branch* br,int cust_id1, float open_bal):current_bal(open_bal),Account(br,cust_id1,"CD")
    {
        current_acc_no=count++;
        overdraft_limit=1500;
    }
    int withdraw(int amount)
    {
        overdraft_limit=overdraft_limit-(2*overdraft_limit);
        if((current_bal-amount)>=overdraft_limit)
        {
            current_bal=current_bal-amount;
        }
        else
        {
            cout<<"Overdraft limit is exceeded "<<endl;
        }
    }
    int deposit(int amount)
    {
        current_bal+=amount;
        return current_bal;
    }
    void applyOverdraft(float limit)
    {
        overdraft_limit = limit;
        cout<<"Overdraft limit applied: " <<overdraft_limit<<endl;
    }
    void display()
    {
        
        cout<<"---------------------------------------"<<endl;
        cout<<"Current Account"<<endl;
        cout<<"Account Number: " <<current_acc_no<<endl;
        cout<<"Balance: "<<current_bal<<endl;
        cout<<"Overdraft Limit: "<<overdraft_limit<<endl;
        cout<<"---------------------------------------"<<endl;
    }
    void calculateInterest()
    {
        cout<<"No interest earned on current account."<<endl;
    }
};
int Current_Account::count = 1890;
class PPF_Account : public Account {
private:
    int ppf_acc_no;
    float ppf_balance;
    int c=0;
    static int count;
public:
    PPF_Account(Branch *br,string name,string dob,string address,float open_bal):Account(br,name,dob,address,"PPF"),ppf_balance(open_bal)
    {
        ppf_acc_no=count++;
    }
    PPF_Account(Branch* br,int cust_id1, float open_bal):ppf_balance(open_bal),Account(br,cust_id1,"PPF")
    {
        ppf_acc_no=count++;
    }
    int deposit(int amount)
    {
        if(c>=12)
        {
            ppf_balance += amount;
            c++;
            return ppf_balance;
        }
        else
        {
            cout<<"Exceeded 12 deposits"<<endl;
        }
    }
    void display() 
    {
        cout<<"PPF Account"<< endl;
        cout<<"Account Number: " << ppf_acc_no<<endl;
        cout<<"Balance: "<<ppf_balance<< endl;
    }
    void calculateInterest()
    {
            float interest=ppf_balance*0.08;//8% interest rate
            cout<<"Interest earned: "<<interest<<endl;
    }
};
int PPF_Account::count = 1890;
class Loan_Account:Account {
private:
    int loan_number;
    float loan_amount;
    float interest_rate;
    float monthly_payment;
    static int count;

public:
    Loan_Account(Branch *br,string name,string dob,string address,float amt,float ir):Account(br,name,dob,address,"LA"),loan_amount(amt),interest_rate(ir)
    {
        loan_number=count++;
    }
    Loan_Account(Branch* br,int cust_id1, float amt,float ir):loan_amount(amt),interest_rate(ir),Account(br,cust_id1,"LA")
    {
        loan_number=count++;
    }
    void display() {
        cout << "Loan" << endl;
        cout << "Loan Number: " << loan_number << endl;
        cout << "Loan Amount: " << loan_amount << endl;
        cout << "Interest Rate: " << interest_rate << "%" << endl;
        cout << "Monthly Payment: " << monthly_payment << endl;
    }
    void makePayment(float amount) {
        if (amount >= monthly_payment) {
            amount -= monthly_payment;
            cout << "Payment of " << monthly_payment << " made. Remaining balance: " << amount << endl;
        } else {
            cout << "Insufficient payment. Minimum payment required: " << monthly_payment << endl;
        }
    }
};
int Loan_Account::count = 16703;


class DebitCard {
private:
    int Card_no;
    string issue_date;
    string expiry_date;
    Savings_Account* linked_sb;
    int cvv;
    static int count;
public:
    DebitCard(Savings_Account& sb)
    {
        srand(time(0));
        cvv=rand()%1000;
        time_t currentTime = time(nullptr);
        tm* localTime = localtime(&currentTime);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%d-%m-%Y", localTime);
        issue_date=buffer;
        expiry_date="08/12/2030";
        Card_no=count++;
        sb.obj_card=this;
    }
    void withdraw(int cvv1,int amt)
    {
        if(cvv=cvv1)
        {
            linked_sb->withdraw(amt);
        }
        else
        {
            cout<<"Invalid Card Details";
        }
    }
    void display_card()
    {
        cout<<"Card_no "<<Card_no<<endl;
        cout<<"CVV "<<cvv<<endl;
    }
};
int DebitCard::count = 156078904567;
int main(int argc, char const *argv[])
{
    Bank ICICI("icici bank","Delhi");
    Branch dwd("dwd","ICICI000124","Jubilee Circle",&ICICI);
    ICICI.branches["ICICI000124"]->display();
    Savings_Account s1(&dwd,"Kushal","26/07/2003","DHarwad",4500);
    //s1.display();
    //cout<<"Maps"<<endl;
    //dwd.Accounts[1][0]->get_name();
    //FixedDeposit_Account f1(&dwd,"kush","26","dwdagshg",150000,2);
    //FixedDeposit_Account f1(&dwd,1,150000,2);*/
    Current_Account f1(&dwd,"Kusha","36","dwd",34500);
    dwd.Accounts[f1.get_cust_id()][2]->display();
    return 0;
}