#include"add_branch.h"
#include"class_bank.h"
#include"class_branch.h"
int add_branch(Bank *a,Branch* b)
{
    a->branches[b->IFSC]=b;
    return 0;
}