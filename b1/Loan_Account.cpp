#include "Loan_Account.h"


// Initialize the static member count
int Loan_Account::count = 16703;

Loan_Account::Loan_Account(Branch* br, string name, string dob, string address, float amt, float ir)
    : loan_amount(amt), interest_rate(ir), Account(br, name, dob, address, "LA")
{
    loan_number = count++;
}

Loan_Account::Loan_Account(Branch* br, int cust_id1, float amt, float ir)
    : loan_amount(amt), interest_rate(ir), Account(br, cust_id1, "LA")
{
    loan_number = count++;
}

void Loan_Account::display()
{
    cout << "Loan" << endl;
    cout << "Loan Number: " << loan_number << endl;
    cout << "Loan Amount: " << loan_amount << endl;
    cout << "Interest Rate: " << interest_rate << "%" << endl;
    cout << "Monthly Payment: " << monthly_payment << endl;
}

int Loan_Account::deposit(float amount)
{
    if (amount >= monthly_payment)
    {
        amount -= monthly_payment;
        cout << "Payment of " << monthly_payment << " made. Remaining balance: " << amount << endl;
        return amount;
    }
    else
    {
        cout << "Insufficient payment. Minimum payment required: " << monthly_payment << endl;
        return -1;
    }
}
