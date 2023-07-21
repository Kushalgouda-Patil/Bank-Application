#include "PPF_Account.h"

int PPF_Account::count = 1890;

PPF_Account::PPF_Account(Branch* br, std::string name, std::string dob, std::string address, float open_bal)
    : ppf_balance(open_bal), Account(br, name, dob, address, "PPF")
{
    ppf_acc_no = count++;
}

PPF_Account::PPF_Account(Branch* br, int cust_id1, float open_bal)
    : ppf_balance(open_bal), Account(br, cust_id1, "PPF")
{
    ppf_acc_no = count++;
}

int PPF_Account::deposit(int amount)
{
    if (c >= 12)
    {
        ppf_balance += amount;
        c++;
        return ppf_balance;
    }
    else
    {
        throw "Exceeded 12 deposits";
    }
}

void PPF_Account::display()
{
    std::cout << "PPF Account" << std::endl;
    std::cout << "Account Number: " << ppf_acc_no << std::endl;
    std::cout << "Balance: " << ppf_balance << std::endl;
}

void PPF_Account::calculateInterest()
{
    float interest = ppf_balance * 0.08; // 8% interest rate
    std::cout << "Interest earned: " << interest << std::endl;
}
