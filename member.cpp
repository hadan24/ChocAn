#include <chocan.h>

//initialize 
member::member(): 
    status_mem("none"), member_ID(000), fee_mem(000), overdue_fee(000)
{} 

//copy constructor for member class
member::member(const member & copy):model(copy)
    , status_mem(copy.status_mem), member_ID(copy.member_ID)
    , fee_mem(copy.fee_mem), overdue_fee(copy.overdue_fee)
{}

member::~member()
{
    // since we dont allocate memory of any variables, nothing here
}

void member::input(){
    cout << "\n\t\t[MEMBER TERMIAL]"; // testing 
    // call the model input to ask an user to enter data
    // model::input(); 
    cout << "\n\tWhat is the status of the membership?  " << member_ID;
    cout << "\n\tWhat is the status of the membership?  " << status_mem;
    cout << "\n\tWhat is the status of the membership?  " << status_mem;
    cout << "\n\tWhat is the status of the membership?  " << status_mem;
}