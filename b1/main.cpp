#include"class_bank.h"
#include"class_branch.h"
#include"declaration.h"
#include"add_func.h"
#include"Savings_Account.h"
#include"DebitCard.h"
#include"FixedDeposit_Account.h"
#include"Current_Account.h"
#include"Loan_Account.h"
#include"PPF_Account.h"
Bank ICICI("ICICI bank","Delhi");
Branch DWD("Dharwad","ICICI000124","Jubilee Circle",&ICICI);
void new_cust()
{
    cout<<"Press 1 to open Savings account"<<endl;
    cout<<"Press 2 to open FD account"<<endl;
    cout<<"Press 3 to open PPF account"<<endl;
    cout<<"Press 4 to open Loan account"<<endl;
    int num;
    cin>>num;
    Account* baseptr;
    string name;
    string dob;
    string address;
    if(num==1)
    {
        float open_bal;
        cout<<"Enter Name,DOB,Address and Opening Balance"<<endl;
        cin>>name>>dob>>address>>open_bal;
        baseptr=new Savings_Account(&DWD,name,dob,address,open_bal);
        cout<<"Account Successfully created!"<<endl;
        baseptr->display();

    }
    else if(num==2)
    {
        float fd_amt;int dur;
        cout<<"Enter Name,DOB,Address ,Amount and Duration"<<endl;
        cin>>name>>dob>>address>>fd_amt>>dur;
        baseptr=new FixedDeposit_Account(&DWD,name,dob,address,fd_amt,dur);
        cout<<"Account Successfully created!"<<endl;
        baseptr->display();

    }
    else if(num==3)
    {
        float open_bal;
        cout<<"Enter Name,DOB,Address and Opening Balance"<<endl;
        cin>>name>>dob>>address>>open_bal;
        baseptr=new PPF_Account(&DWD,name,dob,address,open_bal);
        baseptr->display();
    }
    else if(num==4)
    {
        float loan_amount;
        float interest_rate;
        cout<<"Enter Name,DOB,Address,Amount and Interest rate"<<endl;
        cin>>name>>dob>>address>>loan_amount>>interest_rate;
        baseptr=new Loan_Account(&DWD,name,dob,address,loan_amount,interest_rate);
        baseptr->display();
    }
    else
    {
        throw "Invalid Selection";
    }
}
int existing_cust()
{   
    int num,cid,choice,amount;
    cout<<"Enter cust id "<<endl;
    cin>>cid;
    cout<<"Press 1 to for Savings account"<<endl;
    cout<<"Press 2 to for FD account"<<endl;
    cout<<"Press 3 to for PPF account"<<endl;
    cout<<"Press 4 to for Loan account"<<endl;
    cout<<"Press 5 to for Current account"<<endl;
    cout<<"Press 6 to generate Debit Card"<<endl;
    cin>>num;
    Account* baseptr;
    if(num==1)
    {
        while (true) {
        cout << "\nMenu\n";
        cout << "1. Withdraw\n";
        cout << "2. Deposit\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                int bal = DWD.Accounts[cid][0]->withdraw(amount);
                cout << "Balance " << bal << endl;
                break;
            }
            case 2:
            {
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                int bal = DWD.Accounts[cid][0]->deposit(amount);
                cout << "Balance " << bal << endl;
                break;
            }
            case 3:
            {
                DWD.Accounts[cid][0]->display();
                break;
            }
            case 4:
            {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default:
            {
                cout << "Invalid choice. Please try again." << endl;
            }
            }
        }
    }
    else if(num==2)
    {
        while (true) 
        {
            cout << "\nMenu\n";
            cout << "1. Display\n";
            cout << "2. CalculateInterest\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                {
                    DWD.Accounts[cid][1]->display();
                    break;
                    
                }
                case 2:
                {
                    DWD.Accounts[cid][1]->calculateInterest();
                    break;
                }
                case 3:
                {
                    cout << "Exiting the program." << endl;
                    return 0;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
        }

    }
    else if(num==3)
    {
        while (true) {
        cout << "\nMenu\n";
        cout << "1. Deposit\n";
        cout << "2. Display\n";
        cout <<"3. CalculateInterest\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                int bal = DWD.Accounts[cid][3]->deposit(amount);
                cout << "bal" << bal << endl;
                break;
            }
            case 2:
            {
                DWD.Accounts[cid][3]->display();
                break;
                
            }
            case 3:
            {
                DWD.Accounts[cid][3]->calculateInterest();
                break;
            }
            case 4:
            {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default:
            {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            }
        }
        
    }
    else if(num==4)
    {
        while (true) {
        cout << "\nMenu\n";
        cout << "1. Deposit\n";
        cout << "2. Display\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                int bal = DWD.Accounts[cid][4]->deposit(amount);
                cout << "bal" << bal << endl;
                break;
            }
            case 2:
            {
                DWD.Accounts[cid][4]->display();
                break;
                
            }
            
            case 3:
            {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default:
            {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            }
        }
    }
    else if(num==5)
    {
        while (true) {
            cout << "\nMenu\n";
            cout << "1. Deposit\n";
            cout << "2. Display\n";
            cout << "3. CalculateInterest\n";
            cout << "4. Withdraw\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                {
                    cout << "Enter the amount to deposit: ";
                    cin >> amount;
                    int bal = DWD.Accounts[cid][2]->deposit(amount);
                    cout << "bal" << bal << endl;
                    break;
                }
                case 2:
                {
                    DWD.Accounts[cid][2]->display();
                    break;
                    
                }
                case 3:
                {
                    DWD.Accounts[cid][2]->calculateInterest();
                    break;
                }
                case 4:
                {
                    cout << "Enter the amount to withdraw: ";
                    cin >> amount;
                    int bal = DWD.Accounts[cid][2]->withdraw(amount);
                    cout << "Balance " << bal << endl;
                    break;

                }
                case 5:
                {
                    cout << "Exiting the program." << endl;
                    return 0;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
        }
    }
    else
    {
        throw "Invalid Selection";
    }
}

int main()
{
    
    while(1)
    {
        cout<<"Welcome to ICICI BANK"<<endl;
        cout<<"Press 1 for new customer"<<endl;
        cout<<"Press 2 for existing customer"<<endl;
        int in;
        cin>>in;
        if(in==1)
        {
            try
            {
                new_cust();
            }
            catch(char const* str)
            {
                cerr << str<< endl;
            }
            
        }
        else
        {
            try
            {
                existing_cust();
            }
            catch(char const* str)
            {
                cerr << str<< endl;
            }
        }
    }
    return 0;
}

//g++ .\Account.cpp -c && g++ .\add_func.cpp -c && g++ .\class_bank.cpp -c && g++ .\class_branch.cpp -c && g++ .\Current_Account.cpp -c && g++ .\DebitCard.cpp -c && g++ .\FixedDeposit_Account.cpp -c && g++ .\Loan_Account.cpp -c && g++ .\main.cpp -c && g++ .\PPF_Account.cpp -c && g++ .\Savings_Account.cpp -c

// g++ .\Account.o .\add_func.o .\class_bank.o .\class_branch.o .\Current_Account.o .\DebitCard.o .\FixedDeposit_Account.o .\Loan_Account.o .\main.o .\PPF_Account.o .\Savings_Account.o -o main && .\main.exe