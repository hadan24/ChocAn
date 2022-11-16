//contains classes for model, member, and provider class
//feel free to make changes as needed
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

class model
{
    public:
        model();
        model(const model & copy); //copy constructor, if needed
        virtual ~model();
        virtual void input();
        virtual void display() const;
        virtual void read_file(const string& file_name) const;
        virtual void update_info();

        void update_address(string new_address, string new_city, string new_state, int new_zip);
        void update_email(string new_email);
        bool update_name();
        bool verify_ID(int ID_check);

    private:
        string first_name;
        string last_name;
        string address;
        string city;
        string state;
        int zipcode;
        string email;
};

class service_list
{
    public:
        service_list();
        service_list(const service_list & copy); //copy constructor, if needed
    
        void input();
        void display() const;
        void update_service_info();

        void print_report_provider();
        void print_report_member(); //print and write EFT report to file
        bool verify_service_code();
        void update_comments();

    protected:
        int service_code;
        float service_cost;
        string service_name;
        string comments;
        string DOS; //date of service
        string current_date;
};

// class provider: public model
// {
//     public:
//         provider();
//         provider(const provider & copy); //copy constructor, if needed
//         provider(string &, string &, string &, int, int, float);
//         ~provider();
//         void input();
//         void display() const;
//         void read() const;
//         void update_info();

//         void add_provider();
//         void add_service_code();
//         bool check_service_code(int service_code);
//         void display_summary() const;
//         void write_file() const;
//         bool verify_provider_ID(int ID);

//         //operator overloading
//         bool operator>(const provider & to_compare) const;
//         bool operator<(const provider & to_compare) const;
//         bool operator==(const provider & to_compare) const;

//         friend ostream& operator<<(ostream & o, const provider & to_display);
//         friend bool operator==(int id_to_compare, const provider & to_compare);

//     protected:
//         int num_consul; //number of consultations
//         float total_fee; //weekly fee
//         int provider_ID;
//         service_list * service_provided; //services provided by providers
// };

class member: public model
{
    public: 
        member();
        member(const member & copy); //copy constructor, if needed
        member(string, string, string, int);
        ~member();
        void input();
        void display() const;
        void read_file(const string& file_name) const;
        void update_info();

        bool verify_ID(int ID_check);
        bool update_status();
        bool display_summary();

        void write_reports();

        //operator overloading
        bool operator<(const member & to_compare); //sorting by ID member

    protected:
        bool status_mem; // true: valid   |    false: invalid
        int member_ID;
        float fee_mem;
        float overdue_fee; // ???? not sure| shoud we leave it here or not
};