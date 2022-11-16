#include <chocan.h>

// initialize
member::member() : status_mem("false"), member_ID(000), fee_mem(000), overdue_fee(000), validity_mem(false)
{
}

// copy constructor for member class
member::member(const member &copy) : model(copy), status_mem(copy.status_mem), member_ID(copy.member_ID), fee_mem(copy.fee_mem), overdue_fee(copy.overdue_fee)
{
}

member::~member()
{
    // since we dont allocate memory of any variables, nothing here
}

void member::input()
{
    cout << "\n\t\t[ADDING A NEW MEMBER]"; // testing
    // call the model input to ask an user to enter personal data
    // model::input();

    cout << "\n\tEnter the ID of the membership:  ";
    cin >> member_ID;

    cout << "\n\t The status of the membership: Valid ";
    status_mem = true;

    cout << "\n\tEnter the fee of the membership:  ";
    cin >> fee_mem;

    cout << "\n\tDoes the membership have overdue fee? if yes, please enter:  ";
    cin >> overdue_fee;
}

void member::display() const
{
    // same input () we need to call the function from the model to display some info
    // model::display();
}

// verify ID number
bool member::verify_ID(int ID_check)
{
    if (this->member_ID == ID_check)
        return true;
    return false;
}

bool member::update_status()
{
    int choice = 0;
    do
    {
        cout << "\n\t The status of the membership: \n\t(1) Valid  \n\t(2) Invalid \n\tEnter: ";
        cin >> choice;
        if (choice == 1)
        {
            this->status_mem = true;
            cout << "\n\t The updated status of the membership: VALID! ";
        }
        else if (choice == 2)
        {
            this->status_mem = false;
            cout << "\n\t The updated status of the membership: VALID! ";
        }
        while (choice != 1 && choice != 2)
            ;
    }
