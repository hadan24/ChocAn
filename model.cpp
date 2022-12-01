/*
    11.29.2022 @aho
        working on input() for model
        checking data input is valid or not!
        email input valid ref: https://www.geeksforgeeks.org/check-if-given-email-address-is-valid-or-not-in-cpp/
*/
#include "chocan.h"
#include <regex>

model::model():first_name("none"), last_name("node"), address("none")
            ,city("none"), state("none"), zipcode(0000), email("none")
{

}

model::model(const model &copy):
    first_name(copy.first_name), last_name(copy.last_name)
    ,address(copy.address), city(copy.city)
    ,state(copy.state),zipcode(copy.zipcode)
    ,email(copy.email)
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
    do {
    cout << "\tEnter your email: ";
    getline(cin, email);
    check_email = valid_email(email);
      if (!check_email) {
        cout << "\n**Your email "<< email << " is "
             << "INVALID. Please enter another one following (Eg: email@pdx.edu)\n\t\t";
    }
    } while (!check_email);
}

bool model::valid_email(const string& check_email)
{  
    // Regular expression definition
    const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(check_email, pattern);
}

void model::display() const
{

}

void model::read_file(const string& file_name) const
{

}

void model::update_info()
{

}