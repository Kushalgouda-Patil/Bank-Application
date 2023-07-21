#include "DebitCard.h"

int DebitCard::count = 1456789;

DebitCard::DebitCard(Savings_Account& sb)
{
    srand(time(0));
    cvv = rand() % 1000;
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", localTime);
    issue_date = buffer;
    expiry_date = "08/12/2030";
    Card_no = count++;
    linked_sb = &sb;
    sb.obj_card = this;
}

void DebitCard::withdraw(int cvv1, int amt)
{
    if (cvv == cvv1)
    {
        linked_sb->withdraw(amt);
    }
    else
    {
        std::cout << "Invalid Card Details";
    }
}

void DebitCard::display_card()
{
    std::cout << "Card_no " << Card_no << std::endl;
    std::cout << "CVV " << cvv << std::endl;
}
