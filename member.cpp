#include "chocan.h"

// initialize
member::member() : status_mem("false"), member_ID(000), fee_mem(000), overdue_fee(000)
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
    model::input();

    cout << "\n\tEnter the ID of the membership:  ";
    cin >> member_ID;

    // first time adding a new member. it should be valid as i think
    cout << "\n\tThe status of the membership: Valid ";
    status_mem = true;

    cout << "\n\tEnter the fee of the membership:  ";
    cin >> fee_mem;

    cout << "\n\tDoes the membership have overdue fee? if yes, please enter:  ";
    cin >> overdue_fee;
}

void member::display() const
{

    cout << "\n\t testing - Display from member class! ";
    // same input () we need to call the function from the model to display some info
    // model::display();
    cout << "\n\tThe ID of the membership:  " << member_ID;

    cout << "\n\tThe status of the membership: ";
    if (status_mem)
        cout << " VALID!";
    else
        cout << "INVALID!";

    cout << "\n\tThe fee of the membership:  " << fee_mem;

    cout << "\n\tThe overdue fee of this membership:  " << overdue_fee;
    cout << "\n\n";
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
    bool check = false; // doing exceptional handling. if users enter choice as a letter, this may cause an issue
    do
    {
        do
        {
            try
            {
                cout << "\n\tThe status of the membership: \n\t(1) Valid  \n\t(2) Invalid \n\tEnter: ";
                cin >> choice;
                cin.clear();
                if (choice == (int)choice && choice > 0)
                {
                    check = true;
                }
                else
                {
                    throw "Your input is not accepted!\n";
                    check = false;
                }
            }
            catch (const char *exp)
            {
                cout << "***ERROR: " << exp;
                cout << "\n\t****Please re-enter choice with a number!****";
            }
            cin.ignore(1000, '\n');
            cin.clear();
        } while (check != true);

        if (choice == 1)
        {
            this->status_mem = true;
            cout << "\n\t The updated status of the membership: VALID! ";
            return true;
        }
        else if (choice == 2)
        {
            this->status_mem = false;
            cout << "\n\t The updated status of the membership: VALID! ";
            return true;
        }

    } while (choice != 1 && choice != 2);
    return false;
}

void member::update_info()
{
    // without it, causing errors since we used virtual function from the parent
}

void member::read_file(const string &file_name) const
{
}

int member::get_member_ID(){ return this->member_ID;}

float member::get_fee_mem(){return this->fee_mem;}

bool member::operator<(const member &to_compare) const{
    if(member_ID < to_compare.member_ID){
        return true;
    }
    return false;
}

bool member::operator>(const member &to_compare) const{
    if(member_ID > to_compare.member_ID){
        return true;
    }
    return false;
}

bool member::operator>(const int ID_compare) const
{
    if(member_ID > ID_compare)
        return true;
    
    return false;
}

//needed for BST 
bool member::operator==(const member &to_compare) const
{
    if(member_ID == to_compare.member_ID)
        return true;
    
    return false;
}

//needed for BST
bool member::operator==(const int ID_compare) const
{
    if(member_ID == ID_compare)
        return true;
    
    return false;
}
