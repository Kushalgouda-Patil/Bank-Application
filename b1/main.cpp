#include"class_bank.h"
#include"class_branch.h"
#include"declaration.h"
#include"add_branch.h"

int main()
{
    Bank ICICI("icici bank","Delhi");
    Branch dwd("dwd","ICICI000124","Jubilee Circle",&ICICI);
    ICICI.branches["ICICI000124"]->display();
    return 0;
}