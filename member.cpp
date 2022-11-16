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

void member::input()
{
    cout << "\n\t\t[MEMBER TERMIAL]"; // testing 
    // call the model input to ask an user to enter data
    // model::input(); 

    cout << "\n\tWhat is the ID of the membership?  ";
    cin >> member_ID;

    cout << "\n\tWhat is the status of the membership?  ";
    getline(cin, status_mem);
    cin.clear();
    cin.ignore(1000,'\n');

    cout << "\n\tWhat is the fee of the membership?  ";
    cin >> fee_mem;

    cout << "\n\tDoes the membership have overdue fee? if yes, please enter:  ";
    cin >> overdue_fee;
}


void member::display() const
{
    // same input () we need to call the function from the model to display some info
    // model::display();
    

}