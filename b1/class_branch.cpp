#include"class_branch.h"

Branch::Branch(string br_name,string ifsc,string br_address,Bank* obj):
    branch_name(br_name),IFSC(ifsc),branch_address(br_address){
        add_branch(obj,this);
    }
void Branch::display() const
{
    cout<<branch_name<<endl<<
    IFSC<<endl<<branch_address<<endl;
}
