//contains definitions for BST stuff
//feel free to make changes as needed
/*
11/18/2022 - Anh Ho
----
Note: I am not sure data members should have for the manager terminal. 
It seems like they just need to access 2 terminals (provider and member) to modify those data  
If you have another way to reduce functions or good way to pass variables, please feel free to update 
what I have done: 
I have added BST_provider and BST_member functions without implementation 
I have implemented Manager classes including data members and a few functions. 
----
*/
#include "chocan.h"

class provider_node
{   
    public:
        provider_node();
        ~provider_node();
        provider_node(provider *& copy);
        provider_node *& go_left(); //returns left pointer
        provider_node *& go_right(); //returns right pointer
        void display(); //calls provider's display function
        provider* retrieve_provider_data();
        //wrappers for operator overloading
        bool greater(provider *& compare);
        bool greater(int compare);
        bool equal(int compare);

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
        //BST_provider(BST_provider & copy);                  //copy constructor

        //add and remove functions
        void add_new_provider_(provider *& to_add);              // add by an object
        bool remove_provider_(int ID);          
        bool display_by_ID(int ID);
        bool search_by_ID(int ID);
        provider* retrieve_provider(int ID);
        int count_nodes();

        void display_tree_();


    private:
        //recursive functions
        void add_provider(provider *& to_add, provider_node *& root);
        bool remove_provider(int ID, provider_node *& root);
        bool display_ID(int ID, provider_node *& root);
        bool search_ID(int ID, provider_node *& root);
        provider* retrieve_provider(int ID, provider_node *& root);
        int count_nodes(provider_node * root);
        void display_tree(provider_node * root);
        void delete_all(provider_node *& root); //for destructor
        void find_ios(provider_node *& root, provider_node *& ios); //less headache when removing via match
        provider_node * root;
};

class member_node
{
    public:
        member_node();
        ~member_node();  
        member_node(member *& copy);      
        member_node *& go_left(); //returns left pointer
        member_node *& go_right(); //returns right pointer
        void display(); //calls member's display function
        member* retrieve_member_data();
        bool greater(member *& compare);
        bool greater(int compare);
        bool equal(int compare);

    
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
        //BST_member(BST_member & copy);                   //copy constructor

        //add and remove functions
        void add_new_member_(member *& to_add);                // add by an object
        bool remove_member_(int ID); 
        bool display_by_ID(int ID);
        bool search_by_ID(int ID);
        member* retrieve_member(int ID);

        void display_tree_();

    private:
        //recursive functions
        void add_member(member *& to_add, member_node *& root);
        bool remove_member(int ID, member_node *& root);
        bool display_ID(int ID, member_node *& root);
        bool search_ID(int ID, member_node *& root);
        member* retrieve_member(int ID, member_node *& root);
        void display_tree(member_node * root);
        void delete_all(member_node *& root); //for destructor
        void find_ios(member_node *& root, member_node *& ios); //less headache when removing via match
        member_node * root;
};

class manager
{
    public:
        manager();
        manager(const manager & copy); //copy constructor, if needed
        ~manager();
        //add members or providers
        void add_provider(BST_provider *&);
        void add_member(BST_member *&);
    
        //remove members or providers, based on ID
        bool remove_provider(BST_provider *&);
        bool remove_member(BST_member *&);

        //display a info of an invidual by ID
        bool search_display_provider(BST_provider *&);
        bool search_display_member(BST_member *&);

        // display a whole list of ...
        void display_provider(BST_provider *) const;
        void display_member(BST_member *) const;

        void read() const;
        void update_info();
        void retrieve();
        void write_report(); //writing EFT data to disk

    private:
        
        int manager_ID; 
        BST_provider * manage_p;
        BST_member * manage_m;
};