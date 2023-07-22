#include "FixedDeposit_Account.h"



int FixedDeposit_Account::count = 1;

FixedDeposit_Account::FixedDeposit_Account(Branch* br, string name, string dob, string address, float fd_amt, int dur)
    : Account(br, name, dob, address, "FD"), fd_amount(fd_amt), fd_duration(dur)
{
    fd_acc_no = count++;
}

FixedDeposit_Account::FixedDeposit_Account(Branch* br, int cust_id1, float fd_amt, int dur)
    : Account(br, cust_id1, "FD"), fd_amount(fd_amt), fd_duration(dur)
{
    fd_acc_no = count++;
}

void FixedDeposit_Account::display()
{
    cout << "---------------------------------------" << endl;
    cout << "Fixed Deposit Account" << endl;
    cout << "Account Number: " << fd_acc_no << endl
    << "Customer ID: " << cust_id << endl;
    cout << "Deposit Amount: " << fd_amount << endl;
    cout << "Duration: " << fd_duration << " months" << endl;
    cout << "---------------------------------------" << endl;
}

void FixedDeposit_Account::calculateInterest()
{
    float interest = fd_amount * 0.08; // 8% interest rate
    cout << "Interest earned: " << interest << endl;
}
