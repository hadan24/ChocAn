#include "chocan.h"

// initialize
provider::provider() : num_consul(000), total_fee(000), provider_ID(000) //, service_provided(nullptr)
{  
}

// copy constructor for provider class
provider::provider(const provider &copy) : model(copy), num_consul(copy.num_consul), total_fee(copy.total_fee), provider_ID(copy.provider_ID)
{
    //this -> service_provided = new service_list(*copy.service_provided);
}

provider::~provider()
{
    // if (service_provided ){
    //     delete service_provided;
    //     service_provided = NULL;
    // }
}

void provider:: input()
{
    cout << "\n\t\t[ADDING A NEW PROVIDER]";

    // call the model input to ask personal data of provider
    // model::input();
    cout << "\n\tEnter the ID of the membership:  ";
    cin >> provider_ID;

    cout << "\n\tEnter the number of consultant:  ";
    cin >> num_consul;

    cout << "\n\tEnter the fee of consultant:  ";
    cin >> total_fee;

    cout << "\n\tThe service list:  ";// Waiting for services_list class
                                
}

void provider:: display() const
{
    cout << "\n\t testing - Display from providerclass! ";
    // same input () we need to call the function from the model to display some info
    // model::display();
    cout << "\n\tThe ID of the provider:  " << provider_ID;

    cout << "\n\tThe number of consultant " << num_consul;

    cout << "\n\tThe fee of the membership:  " << total_fee;

    cout << "\n\tThe services list:  ";
    cout << "\n\n";
}

void provider::read(const string &file_name) const
{
}

void provider::update_info()
{
    // without it, causing errors since we used virtual function from the parent
}
// verify ID provider
bool provider::verify_provider_ID(int ID)
{
    if (this->provider_ID == ID)
        return true;
    return false;
}

//operator overloading

bool provider::operator<(const provider &to_compare) const{
    if(provider_ID < to_compare.provider_ID){
        return true;
    }
    return false;
}

bool provider::operator>(const provider &to_compare) const{
    if(provider_ID > to_compare.provider_ID){
        return true;
    }
    return false;
}
bool provider::operator==(const provider &to_compare) const{
    if(provider_ID == to_compare.provider_ID){
        return true;
    }
    return false;
}

// needed for BST
bool provider::operator==(const int ID_compare) const
{
    if(provider_ID == ID_compare)
        return true;
    
    return false;
}

bool provider::operator>(const int ID_compare) const
{
    if(provider_ID > ID_compare)
        return true;
    
    return false;
}

int provider::get_provider_ID() const
{ 
    return this->provider_ID;
}

float provider::get_total_fee() const
{ 
    return this->total_fee;
}

int provider::get_num_consul() const
{ 
    return this->num_consul;
}