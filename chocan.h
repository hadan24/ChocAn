//contains classes for model, member, and provider class
//feel free to make changes as needed
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <iomanip>
#include <map>
#include <fstream>

using namespace std;

// Inheritance 
//            Model
//   proivder       member
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

        //input checking
        bool valid_email(const string &);

        //ChocAn functions
        void update_address();
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

class provider: public model
{
    public:
        provider();
        provider(const provider & copy); //copy constructor, if needed
        provider(string &, string &, string &, int, int, float);
        ~provider();
        void input();
        void display() const;
        void read(const string& file_name) const;
        void update_info();

		// void add_provider(); manager's Privilege 
		// void add_service_code(); manager's Privilege
        bool check_service_code(int service_code); // waiting for service_list
        void display_summary() const; // waiting for service_list
        void write_file() const;
        bool verify_provider_ID(int ID);

        
        int get_provider_ID() const;
        int get_num_consul() const;
        float get_total_fee() const;

        //operator overloading
        bool operator>(const provider & to_compare) const;
        bool operator<(const provider & to_compare) const;
        bool operator>(const int ID_compare) const;
        bool operator==(const provider & to_compare) const;
        bool operator==(const int ID_compare) const;

    protected:
        int num_consul; //number of consultations
        float total_fee; //weekly fee
        int provider_ID;
		// vector<service> services_provided;
};

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

        float get_fee_mem();
        int get_member_ID();    // provider may need this.. hmm.. 

        //operator overloading
        bool operator<(const member &to_compare) const; //sorting by ID member
        bool operator>(const member &to_compare) const; //sorting by ID member
        bool operator>(const int ID_compare) const;
        bool operator==(const member &to_compare) const;
        bool operator==(const int ID_compare) const;

    protected:
        bool status_mem; // true: valid   |    false: invalid
        int member_ID;
        float fee_mem;
        float overdue_fee; // ???? not sure| shoud we leave it here or not
		// vector<service> services_received;
};  

class service
{
    public:
        service();
    
        void input();
        void display() const;
        void update_info();
		// not sure who should handle writing to disk
		static void show_available_services();	// display provider directory

		// if provider class handles writing to disk, will include getter
		// functions so they can access the proper information to print reports

    protected:
		void load_available_services();
		static map<int, string> available_services;

		string date_of_service;
		int service_code;
        string service_name;
        string comments;
		float service_cost;
		string current_date;
};