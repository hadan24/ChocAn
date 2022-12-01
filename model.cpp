/*
    11.29.2022 @aho
        working on input() for model
        checking data input is valid or not!
        email input valid ref: https://www.geeksforgeeks.org/check-if-given-email-address-is-valid-or-not-in-cpp/
    11.30.2022 @aho
        adding info for display and update_info func in the model class
        also checking bad inputs.

*/
#include "chocan.h"
#include <regex>

model::model() : first_name("none"), last_name("node"), address("none"), city("none"), state("none"), zipcode(0000), email("none")
{
}

model::model(const model &copy) : first_name(copy.first_name), last_name(copy.last_name), address(copy.address), city(copy.city), state(copy.state), zipcode(copy.zipcode), email(copy.email)
{
}
model::~model()
{
}
void model::input()
{
    bool check_email = false;
    bool check_zipcode = false;

    cout << "\n\n\tEnter your fist name: ";
    getline(cin, first_name);

    cout << "\tEnter your last name: ";
    getline(cin, last_name);

    cout << "\tEnter your home address: ";
    getline(cin, address);

    cout << "\tEnter your city: ";
    getline(cin, city);

    cout << "\tEnter your state: ";
    getline(cin, state);

    //,, zipcode input
    do
    {
        try
        {
            cout << "\tEnter your zipcode: ";
            cin >> zipcode;
            cin.clear();
            if (zipcode == (int)zipcode && zipcode > 0)
            {
                check_zipcode = true;
            }
            else
            {
                throw "Your zipcode is not accepted!";
                check_zipcode = false;
            }
        }
        catch (const char *exp)
        {
            cout << "\n\t***ERROR: " << exp;
            cout << "\n\t****Please enter a valid zipcode with a number!****\n\t";
        }
        cin.ignore(1000, '\n');
        cin.clear();
    } while (check_zipcode != true);

    //.. email input
    do
    {
        cout << "\tEnter your email: ";
        getline(cin, email);
        check_email = valid_email(email);
        if (!check_email)
        {
            cout << "\n**Your email " << email << " is "
                 << "INVALID. Please enter another one following (Eg: email@pdx.edu)\n\t\t";
        }
    } while (!check_email);
}

bool model::valid_email(const string &check_email)
{
    // Regular expression definition
    const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(check_email, pattern);
}

// display personal info from the base of the hierarchy 
void model::display() const
{
    cout << "\n\t** Personal Information **";
    cout << "\tFirst Name         : " << first_name << endl;
    cout << "\tLast Name          : " << last_name << endl;
    cout << "\t Mailing address   : " << address << ", " << city << ", "
         << state << ", " << zipcode << endl;
    cout << "\tEmail contact      : " << email << endl;
}

// this function is used for adding data from a txt file.
void model::read_file(const string &file_name) const
{}

// this function to update info based on a menu
void model::update_info()
{
    int choice = 0;
    bool check = false;
    cout << "\n\t** UPDATE PERSONAL INFORMATION **";
    do
    {
        do
        {
            try
            {
                cout << "\n\tWhich information do you want to update in the system?";
                cout << "\n\t[1] Firt and Last Name";
                cout << "\n\t[2] Mailing Adress";
                cout << "\n\t[3] Email";
                cout << "\n\t[0] I don't want to update anything!";
                cin >> choice;
                cin.clear();
                if (choice == (int)choice && choice >= 0 && choice < 4 )
                    check = true;
                else
               {
                    throw "Your input is not accepted!\n";
                    check = false;
                }
            }
            catch (const char *exp)
            {
                cout << "\n\t***ERROR: " << exp;
                cout << "\n\t****Please re-enter choice with a number from 0 to 3!****";
            }
            cin.ignore(1000, '\n');
            cin.clear();
        } while (check != true);

    } while (choice < 0 && choice > 3);
}