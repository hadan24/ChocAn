// @anhho
// miss reading a txt file into data
#include "chocan.h"

// initialize
member::member() : status_mem("false"), member_ID(000), fee_mem(000), service_provided(nullptr)
{
}

// copy constructor for member class
member::member(const member &copy) : model(copy), status_mem(copy.status_mem), member_ID(copy.member_ID), fee_mem(copy.fee_mem)
{
    this -> service_provided = new service_list(*copy.service_provided);
}
member::member(
    const string& t_first,
    const string& t_last, const string& t_address, const string& t_city, 
    const string& t_state, int t_zipcode, const string& t_email, 
    const bool& t_status, int t_ID, float t_fee, service_list * m_list):
    model(t_first, t_last, t_address, t_state, t_city, t_zipcode, t_email)
    , status_mem(t_status), member_ID(t_ID), fee_mem(t_fee), service_provided(m_list)
{
}

member::~member() //if I get rid we get mem leaks, if not invalid free
{
    if (service_provided) {
        delete service_provided;
        service_provided = NULL;
    }
}

void member::input()
{
    cout << "\n\t\t[ADDING A NEW MEMBER]"; // testing
    // call the model input to ask an user to enter personal data
    model::input();

    cout << "\n\tEnter the ID of the membership      :  ";
    cin >> member_ID;

    // first time adding a new member. it should be valid as i think
    cout << "\tThe status of the membership         : Valid ";
    status_mem = true;

    cout << "\n\tEnter the fee of the membership      :  ";
    cin >> fee_mem;

    service_provided = new service_list();
    service_provided->add_new_service_record();

}

void member::display(std::ostream& cout = std::cout) const
{

    cout << "\n\tMember Information:";
    // same input () we need to call the function from the model to display some info
    model::display();
    cout << "\n\tThe ID of the membership           :  " << member_ID;

    cout << "\n\tThe status of the membership       : ";
    if (status_mem)
        cout << " VALID!";
    else
        cout << "INVALID!";

    cout << "\n\tThe fee of the membership          :  " << fee_mem;

    service_provided->display_all_services();
}

// verify ID number
bool member::verify_ID(int ID_check)
{
    if (this->member_ID == ID_check)
        return true;
    return false;
}

void member::set_ID(int ID)
{           
        this->member_ID = ID;
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

void member::set_status(bool choice)
{
        status_mem = choice;
        if(status_mem)
                cout << "\n\t The updated status of the membership: VALID! ";
        else
                cout << "\n\t The updated status of the membership: INVALID! ";
}

void member::update_info()
{
    model::update_info();
}

// tree is included to allow login feature to work
void member::read_file(const string &file_name, BST_member& m_tree) const
{
    ifstream INFILE(file_name);
    // temp variable to get input into data.
    string t_first;
    string t_last;
    string t_address;
    string t_city;
    string t_state;
    int t_zipcode;
    string t_email;
    bool t_status = 0;
    int t_id;
    float t_fee;
    string eachLine;
 
    //error check for open file
    if(INFILE.is_open())
    {
        while(getline(INFILE, eachLine))
        {
            stringstream readFile(eachLine);
            getline(readFile, t_first, '|');
            getline(readFile, t_last, '|');
            getline(readFile, t_address, '|');
            getline(readFile, t_city, '|');
            getline(readFile, t_state, '|');
            readFile >> t_zipcode;
            readFile.ignore(1, '|');
            getline(readFile, t_email, '|');
            readFile >> t_status;  
            readFile.ignore(1,'|'); 
            readFile >> t_id;
            readFile.ignore(1,'|');
            readFile >> t_fee;
            service_list * t_list = new service_list();
         //   t_list->add_new_service_record();
            member get_new_member(t_first, t_last, t_address, t_city, t_state
                                   , t_zipcode, t_email, t_status, t_id, t_fee, t_list);

            //member* temp_mem = &get_new_member;

            //m_tree.add_new_member_(temp_mem);
        }
        return;
    }
    cerr << "ERROR: Failed to open file " << file_name << " for loading data!!!\n";
    exit(1);    
}

void member::set_service_list()
{
    this->service_provided->add_new_service_record();
}

int member::get_member_ID(){ return this->member_ID;}

float member::get_fee_mem(){return this->fee_mem;}

bool member::get_status_mem(){return this->status_mem;}

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
  