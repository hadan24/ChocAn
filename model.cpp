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
{}    
model::~model()
{

}
void model::input()
{
    bool check_email = false;
    cout << "Please enter your infomation in ChocAn system!\n";
    cout << "Enter your fist name: ";
    getline(cin, first_name);

    cout << "Enter your last name: ";
    getline(cin, last_name);

    cout << "Enter your home address: ";
    getline(cin, address);

    cout << "Enter your city: ";
    getline(cin, city);

    cout << "Enter your state: ";
    getline(cin, state);

    cout << "Enter your zipcode: ";
    cin >> zipcode;
    cin.ignore(1000, '\n');
    cin.clear();

    do {
    cout << "Enter your email: ";
    getline(cin, email);
    check_email = valid_email(email);
      if (!check_email) {
        cout << "Your email "<< email << " is "
             << "INVALID. Please enter another one following (Eg: email@pdx.edu)" << endl;
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