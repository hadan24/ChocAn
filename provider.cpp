// Linh Nguyen

#include "chocan.h"

// initialize
provider::provider() : num_consul(000), total_fee(000), provider_ID(000) , service_provided(nullptr)
{  
}

// copy constructor for provider class
provider::provider(const provider &copy) : model(copy), num_consul(copy.num_consul), total_fee(copy.total_fee), provider_ID(copy.provider_ID)
{
    this -> service_provided = new service_list(*copy.service_provided);
}
provider:: provider (const string& p_first, const string& p_last,
                    const string & p_address,const string & p_city,const string & p_state,int p_zip,
                    const string & p_email, int num_consul,  int p_ID,float total_fee, service_list *list)
{

}
provider::~provider()
{
    if (service_provided) {
        delete service_provided;
        service_provided = NULL;
    }
}

void provider:: input()
{
    cout << "\n\t\t[ADDING A NEW PROVIDER]";

    //call the model input to ask personal data of provider
    model::input();
    cout << "\n\tEnter the ID of the membership:  ";
    cin >> provider_ID;

    cout << "\n\tEnter the number of consultant:  ";
    cin >> num_consul;

    cout << "\n\tEnter the fee of consultant:  ";
    cin >> total_fee;

    cout << "\n\tThe service list:  ";
    service_provided = new service_list();
    service_provided -> add_new_service_record();
                                
}

void provider:: display() const
{
    
    //same input () we need to call the function from the model to display some info
    model::display();
    cout << "\n\tThe ID of the provider:  " << provider_ID;

    cout << "\n\tThe number of consultant " << num_consul;

    cout << "\n\tThe fee of the membership:  " << total_fee;

    cout << "\n\tThe services list:  ";
    service_provided -> display_all_services();
    cout << "\n\n";
}
void provider:: display_summary () const
{
    float total_fee;
    int total_num;
    total_num = service_provided -> num_services();
    cout << "\n\t2.The total number of consultations:  " << total_num;
    
    total_fee = service_provided ->total_cost();
    cout <<  "\n\t3.The overall fee  " << total_fee;
}

void provider:: write_file() 
{
    float total_fee;
    int total_num;

    char fileNameOut [] = "p_report.txt";
  	ofstream outfile(fileNameOut);
    total_num = service_provided -> num_services();
    total_fee = service_provided ->total_cost();
    outfile << "2.The total number of consultations:  " << total_num << '\n';
    outfile << "3.The overall fee " << total_fee << '\n';

    outfile.close();
}
void provider:: display_directory()
{
    service_provided -> display_all_services();
}

/*bool provider::check_service_code () 
{
    int check;
    cout <<  "Please enter service code that you want to check "<< check;
    //service_provided -> check_code(check);
}*/

void provider::read(const string &file_name) const
{
    string p_first;
    string p_last;
    string p_address;
    string p_city;
    string p_state;
    int p_zipcode;
    string p_email;
    int num_consul;
    float total_fee;
    int provider_ID;
    //service_list *list;
    string eachLine;

    ifstream INFILE(file_name);
    if(INFILE.is_open())
    {
        while(getline(INFILE, eachLine))
        {

            stringstream readFile(eachLine);
            getline(readFile, p_first, '|');
            getline(readFile, p_last, '|');
            getline(readFile, p_address, '|');
            getline(readFile, p_city, '|');
            getline(readFile, p_state, '|');
            readFile >> p_zipcode;
            readFile.ignore(1, '|');
            getline(readFile, p_email, '|');
            readFile >> num_consul;  
            readFile.ignore(1,'|'); 
            readFile >> total_fee;
            readFile.ignore(1,'|');
            readFile >> provider_ID;
            
            //provider new_provider(p_first, p_last, p_address, p_city, p_state
            //                    , p_zipcode, p_email, num_consul,total_fee, provider_ID, list);
            
            //new_provider.display();
        }
        return;
    }
    cerr << "ERROR: unable to open file " << file_name << " for loading data!!!\n";
    exit(1);     
}

void provider::update_info()
{
    model::update_info();
}

// verify ID provider
bool provider::verify_provider_ID(int ID)
{
    if (this->provider_ID == ID)
        return true;
    return false;
}

//operator overloading
/*
bool provider::operator < (const provider &to_compare) const{
    if(provider_ID < to_compare.provider_ID){
        return true;
    }
    return false;
}

bool provider::operator > (const provider &to_compare) const{
    if(provider_ID > to_compare.provider_ID){
        return true;
    }
    return false;
}
bool provider::operator == (const provider &to_compare) const{
    if(provider_ID == to_compare.provider_ID){
        return true;
    }
    return false;
}
*/
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

bool provider::operator>(const int ID_compare) const
{
    if(provider_ID > ID_compare)
        return true;

    return false;
}

//needed for BST
bool provider::operator==(const provider &to_compare) const
{
    if(provider_ID == to_compare.provider_ID)
        return true;

    return false;
}

//needed for BST
bool provider::operator==(const int ID_compare) const
{
    if(provider_ID == ID_compare)
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