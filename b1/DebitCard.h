#ifndef DEBIT_CARD_H
#define DEBIT_CARD_H
#include"declaration.h"
#include "Savings_Account.h" 

class DebitCard
{
private:
    int Card_no;
    std::string issue_date;
    std::string expiry_date;
    Savings_Account* linked_sb;
    int cvv;
    static int count;

public:
    DebitCard(Savings_Account& sb);
    void withdraw(int cvv1, int amt);
    void display_card();
};

#endif 
