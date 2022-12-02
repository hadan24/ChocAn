//contains classes for model, member, and provider class
//feel free to make changes as needed
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Inheritance 
//            Model
//   proivder       member
class model  // @anhho
{
    public:
        model();
        model(const model & copy); //copy constructor, if needed
        model(
            const string& , //first
            const string& , //last
            const string& , //address
            const string& , //city
            const string& , //state
            int ,           //zipcode
            const string& //email
        );
        virtual ~model();
        virtual void input();
        virtual void display() const;
        virtual void read_file(const string& file_name) const;
        virtual void update_info();

        //input checking
        bool valid_email(const string &);

        //ChocAn functions
        void update_address();
        void update_email();
        bool update_name();

        bool verify_ID(int ID_check); // not done

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

class service_list;

class member: public model  // @anhho
{
    public: 
        member();
        member(const member & copy); //copy constructor, if needed
        member(
            const string& , //first
            const string& , //last
            const string& , //address
            const string& , //city
            const string& , //state
            int ,           //zipcode
            const string& , //email
            const bool& ,   //status
            int ,           //ID
            float,           //fee
            service_list *
        );     

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
    	service_list *service_provided;
};  

class service
{
    public:
        service();
    
        void create();
        void display() const;
		int compare_dates(service &to_cmp);	// works like strcmp, calling obj is on left, arg is on right
		void read_from_disk();
		float get_cost();

    protected:
		// create() helper functions
		void enter_date();
		void get_service_dir_data();
		void get_curr_date();
		void capitalize_name();

		// error/input checking functions
		int parse_date(string date);	// turns date strings into nums for comparisons
		bool check_date(string m, string d, string y);	// checks if date passed is valid
		string prep_str(string to_prep);	// makes string all lowercase for comparisons

		string date_of_service;		// MM-DD-YYYY
		int code;
        string name;
        string comments;
		float cost;
		string current_date;	// MM-DD-YYYY HH:MM:SS
};

class service_list
{
	public:
		void add_new_service_record();
		void display_all_services();
		float total_cost();
		int num_services();

	private:
		vector<service> list;
};

class service_directory
{
	public:
		service_directory();

		// both return -1 on failure
		int find_code_by_name(string name);
		float find_cost_by_name(string name);				

		void display_all();
		bool is_code_valid(int to_check);

	private:
		struct entry {
			string name;
			int code;
			float cost;
		};
		vector<entry> dir;
};