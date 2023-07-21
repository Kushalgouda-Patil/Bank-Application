#include "FixedDeposit_Account.h"



int FixedDeposit_Account::count = 1;

FixedDeposit_Account::FixedDeposit_Account(Branch* br, std::string name, std::string dob, std::string address, float fd_amt, int dur)
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
    std::cout << "Fixed Deposit Account" << std::endl;
    std::cout << "Account Number: " << fd_acc_no << std::endl;
    std::cout << "Deposit Amount: " << fd_amount << std::endl;
    std::cout << "Duration: " << fd_duration << " months" << std::endl;
}

void FixedDeposit_Account::calculateInterest()
{
    float interest = fd_amount * 0.08; // 8% interest rate
    std::cout << "Interest earned: " << interest << std::endl;
}
