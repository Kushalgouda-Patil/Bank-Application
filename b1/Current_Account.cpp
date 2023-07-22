#include "Current_Account.h"


// Initialize the static member count
int Current_Account::count = 1890;

Current_Account::Current_Account(Branch* br, string name, string dob, string address, float open_bal)
    : current_bal(open_bal), Account(br, name, dob, address, "CD")
{
    current_acc_no = count++;
    overdraft_limit = 1500;
}

Current_Account::Current_Account(Branch* br, int cust_id1, float open_bal)
    : current_bal(open_bal), Account(br, cust_id1, "CD")
{
    current_acc_no = count++;
    overdraft_limit = 1500;
}

int Current_Account::withdraw(int amount)
{
    overdraft_limit = overdraft_limit - (2 * overdraft_limit);
    if ((current_bal - amount) >= overdraft_limit)
    {
        current_bal = current_bal - amount;
        return current_bal;
    }
    else
    {
        throw("Overdraft limit is exceeded " );
    }
}

int Current_Account::deposit(int amount)
{
    current_bal += amount;
    return current_bal;
}

void Current_Account::applyOverdraft(float limit)
{
    overdraft_limit = limit;
    cout << "Overdraft limit applied: " << overdraft_limit << endl;
}

void Current_Account::display()
{
    cout << "---------------------------------------" << endl;
    cout << "Current Account" << endl;
    cout << "Account Number: " << current_acc_no << endl
    << "Customer ID: " << cust_id << endl;
    cout << "Balance: " << current_bal << endl;
    cout << "Overdraft Limit: " << overdraft_limit << endl;
    cout << "---------------------------------------" << endl;
}

void Current_Account::calculateInterest()
{
    cout << "No interest earned on current account." << endl;
}
