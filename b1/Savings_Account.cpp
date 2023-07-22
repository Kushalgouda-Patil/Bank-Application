#include"declaration.h"
#include"Account.h"
#include"add_func.h"
#include"class_branch.h"
#include"Savings_Account.h"


Savings_Account::Savings_Account(Branch* br, string name, string dob, string address, float open_bal)
    : Account(br, name, dob, address, "SB"), savings_bal(open_bal) {
    savings_ac_no = count++;
    obj_card=nullptr;
}
Savings_Account::Savings_Account(Branch* br, int cust_id1, string type, float open_bal)
    : savings_bal(open_bal), Account(br, cust_id1, type) {
    savings_ac_no = count++;
}

int Savings_Account::withdraw(int amount) {
    if (savings_bal - amount >= 0) {
            savings_bal -= amount;
            return savings_bal;
    } else {
            throw "Insufficient balance";
    }
}
int Savings_Account::deposit(int amount) {
    savings_bal += amount;
    return savings_bal;
}

void Savings_Account::display() {
    cout << "---------------------------------------" << endl;
    cout << "Name: " << name << endl
        << "Date of Birth: " << dob << endl
        << "Customer ID: " << cust_id << endl
        << "Savings Account Number: " << savings_ac_no << endl
        <<"Balance: "<<savings_bal<<endl;
    cout << "---------------------------------------" << endl;
}
int Savings_Account::count = 1000;