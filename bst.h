//contains definitions for BST stuff
//feel free to make changes as needed
#include "chocan.h"

class provider_node
{   
    public:
        provider_node();
        ~provider_node();

    private:
        provider * provider_data;
        provider_node * left;
        provider_node * right;
};

class BST_provider
{
    public:
        BST_provider();
        ~BST_provider();
        BST_provider(BST_provider & copy); //copy constructor
        //add and remove functions

    private:
        provider_node * root;
};

class member_node
{
    public:
        member_node();
        ~member_node();
    
    private:
        member * member_data;
        member_node * left;
        member_node * right;
};

class BST_member
{
    public:
        BST_member();
        ~BST_member();
        BST_member(BST_member & copy); //copy constructor
        //add and remove functions

    private:
        member_node * root;
};
/*
Note: I am not sure data members should have for the manager terminal. 
It seems like they just need to access 2 terminals (provider and member) to modify those data  


*/
class manager
{
    public:
        manager();
        manager(const manager & copy); //copy constructor, if needed
        ~manager();
        //add members or providers
        void add_member(BST_member *&);
        void add_provider(BST_provider *&);

        //remove members or providers, based on ID
        bool remove_provider(int ID);
        bool remove_member(int ID);

        bool search_provider(string);
        bool search_member(string);

        void display() const;
        void read() const;
        void update_info();
        void retrieve();
        void write_report(); //writing EFT data to disk

    private:
        
        int manager_ID; 
        BST_provider * manage_p;
        BST_member * manage_m;
};