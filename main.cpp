#include "main.h"

int main()
{
    cout << "Did somebody say...chocolate?" << endl;

    /*General Variables Block*/
    int menu_ID; //This variable is for testing the menu: this would be the class member's ID
    char menu_input;
    int tempID; //Variable for individual cases that need an ID input

    /*Model Classes Block*/
    provider choc_provider;
    provider* provider_ptr;
    member choc_member;
    member* member_ptr;
    manager choc_manager;

    /*Structures Block*/
    BST_member member_tree;
    BST_provider provider_tree;

    /* Service Block*/
    service_list serve_list;
    service_directory serve_dir;

    load_member_data("data_member.txt", member_tree);
    //load_provider_data("provider.txt", provider_tree);


    print_header();

    print_welcome();
    menu_ID = query_ID();

    /* 
        Provider Menu
    */
    if (menu_ID == 1) {
        do {
            provider_menu();
            cout << "Select a Function: ";
            menu_input = query_menu();
            switch(menu_input) {
                case 's':
                    cout << "Please enter the ID of the member you would " <<
                             "like to check the status of: ";
                    tempID = query_ID();

                    if (!member_tree.display_by_ID(tempID)) {
                        cout << "Member ID Not Found..." << endl;
                    }
                    cout << endl << "Member status checked..." << endl;
                    break;
                case 'i':
                    cout << "Please enter the ID of the member you would " <<
                             "like to display: ";
                    tempID = query_ID();

                    if (!member_tree.display_by_ID(tempID)) {
                        cout << "Member ID Not Found..." << endl;
                    }
                    cout << "Searching ID..." << endl;
                    break;

                // case 'c':
                    /*
                        Charging members case was never implemented
                        In a way that could be called by a user
                    */
                //     cout << "Charging Member..." << endl; 
                //     break;
                case 'd':
                    cout << "Displaying Provider Directory" << endl << endl;
                    cout << "List of services and codes as follows:" << endl << endl;
                    serve_dir.display_all();
                    cout << "Requesting Provider Directory..." << endl;
                    break;
                case 'a':
                    choc_member.input();
                    member_ptr = &choc_member;
                    member_tree.add_new_member_(member_ptr);
                    cout << "Adding Member..." << endl;
                    break;
                case 'r':
                    cout << "Please enter the ID of the member you would " <<
                             "like to remove: ";
                    tempID = query_ID();

                    if (!member_tree.remove_member_(tempID)) {
                        cout << "Unable to remove requested member..." << endl;
                    }

                    cout << "Removing Member..." << endl;
                    break;
                case 'u':
                    cout << "Please Enter the ID of the member you would " <<
                             "like to update: ";
                    tempID = query_ID();

                    if (member_tree.search_by_ID(tempID)) {
                        member_ptr = member_tree.retrieve_member(tempID);
                        member_ptr->update_info();
                        cout << "Information updated..." << endl << endl;
                    }
                    else {
                        cout << "Member ID Not Found..." << endl;
                    }
                    cout << "Updating Member Information..." << endl;
                    break;
                case 'o':
                    /*
                        No integrated functionality yet
                    */
                    cout << "Requesting Provider Report" << endl;
                    break;
                case 'q':
                    cout << "Quitting..." << endl;
                    break;
                default:
                    cout << "Unknown Command..." << endl << endl;
                    break;
            }
        } while (menu_input != 'q');

    }
    /*
        Member Menu
    */
    else if (menu_ID == 2) {
        do {
            member_menu();
            cout << "Select a Function: ";
            menu_input = query_menu();
            switch (menu_input) {
                case 's':
                    cout << "Please enter your member ID: ";
                    tempID = query_ID();
                    if (member_tree.search_by_ID(tempID)) {
                        member_ptr = member_tree.retrieve_member(tempID);
                        member_ptr->set_service_list();
                    }
                    else {
                        cout << "Member ID not found..." << endl;
                    }
                    cout << "Requesting service..." << endl << endl;
                    break;
                case 'r':
                    cout << "Please enter your member ID: ";
                    tempID = query_ID();
                    if (member_tree.search_by_ID(tempID)) {
                        member_ptr = member_tree.retrieve_member(tempID);
                        member_ptr->display();
                    }
                    else {
                        cout << "Member ID not found..." << endl;
                    }
                    cout << "Requesting Report..." << endl << endl;
                    break;
                case 'q':
                    cout << "Quitting..." << endl << endl;
                    break;
                default:
                    cout << "Unknown Command..." << endl << endl;
                    break;
            }
        } while (menu_input != 'q');
    }
    /*
        Manager Menu
    */
    else if (menu_ID == 3) {
        do {
            manager_menu();
            cout << "Select a Function: ";
            menu_input = query_menu();
            switch (menu_input) {
                case 'p':
                    /*
                        No Integrated functionality yet
                    */
                    cout << "Printing Weekly Report" << endl;
                    break;
                case 'a':
                    choc_member.input();
                    member_ptr = &choc_member;
                    member_tree.add_new_member_(member_ptr);
                    cout << "Adding Member" << endl;
                    break;
                case 'd':
                    cout << "Please enter the ID of the member you would " <<
                             "like to remove: ";
                    tempID = query_ID();

                    if (!member_tree.remove_member_(tempID)) {
                        cout << "Unable to remove requested member..." << endl;
                    }
                    cout << "Removing Member" << endl;
                    break;
                case 'k':
                    choc_provider.input();
                    provider_ptr = &choc_provider;
                    provider_tree.add_new_provider_(provider_ptr);
                    cout << "Adding Provider..." << endl;
                    break;
                case 'r':
                    cout << "Please enter the ID of the provider you would " <<
                             "like to remove: ";
                    tempID = query_ID();

                    if (!provider_tree.remove_provider_(tempID)) {
                        cout << "Unable to remove requested provider..." << endl;
                    }
                    cout << "Removing Provider..." << endl;
                    break;
                case 'u':
                    cout << "Please Enter the ID of the member you would " <<
                             "like to update: ";
                    tempID = query_ID();

                    if (member_tree.search_by_ID(tempID)) {
                        member_ptr = member_tree.retrieve_member(tempID);
                        member_ptr->update_info();
                        cout << "Information updated..." << endl << endl;
                    }
                    else {
                        cout << "Member ID Not Found..." << endl;
                    }
                    cout << "Updating Member Information..." << endl;
                    break;
                case 's':
                    cout << "Please Enter the ID of the provider you would " <<
                             "like to update: ";
                    tempID = query_ID();

                    if (provider_tree.search_by_ID(tempID)) {
                        provider_ptr = provider_tree.retrieve_provider(tempID);
                        provider_ptr->update_info();
                        cout << "Information Updated..." << endl << endl;
                    }
                    else {
                        cout << "Member ID Not Found..." << endl;
                    }
                    cout << "Updating Provider Information..." << endl;
                    break;
                case 'q':
                    cout << "Quitting..." << endl;
                    break;
                default:
                    cout << "Unknown Command..." << endl << endl;
                    break;
            }
        } while (menu_input != 'q');
    }

    cout << "Thank you for choosing Chocoholics Anonymous!" << endl;

    return 0;
}

void print_header() 
{
    cout << setw(50) << setfill('*') << "" << setfill(' ') << endl;
    cout << "|" << setw(38) << "Chocoholics Anonymous Terminal" << setw(11) << "|" << endl;
    cout << setw(50) << setfill('*') << "" << setfill(' ') << endl << endl;
}

void print_welcome()
{
    cout << "Welcome to ChocAn!" << endl << endl;
    cout << "[1] Provider Menu\n\n [2] Member Menu\n\n [3] Manager Menu\n\n";
    cout << "Please enter your ID number: ";
}

void member_menu() 
{
    print_header();

    cout << "s: Request provider service(s)" << endl;
    print_line_break();
    cout << "r: Request service report" << endl;
    print_line_break();
    cout << "q: Quit" << endl << endl;
    print_line_break();
}

void provider_menu()
{
    print_header();

    cout << "s: Check Member Status" << endl;
    print_line_break();
    cout << "i: Search by ID" << endl;
    print_line_break();
    cout << "c: Charge Member for Service(s) [Nonfunctional]" << endl;
    print_line_break();
    cout << "d: Request Provider Directory" << endl;
    print_line_break();
    cout << "a: Add Member" << endl;
    print_line_break();
    cout << "r: Remove Member" << endl;
    print_line_break();
    cout << "u: Update Member Record" << endl;
    print_line_break();
    cout << "o: Request Provider Report" << endl;
    print_line_break();
    cout << "q: Quit" << endl << endl;
    print_line_break();
}

void manager_menu() 
{
    print_header();

    cout << "p: Print Weekly Report" << endl;
    print_line_break();
    cout << "a: Add Member" << endl;
    print_line_break();
    cout << "d: Remove Member" << endl;
    print_line_break();
    cout << "k: Add Provider" << endl;
    print_line_break();
    cout << "r: Remove Provider" << endl;
    print_line_break();
    cout << "u: Update Member Information" << endl;
    print_line_break();
    cout << "s: Update Provider Information" << endl;
    print_line_break();
    cout << "q: Quit" << endl << endl;
    print_line_break();
}

void print_line_break()
{
    cout << setfill('-') << setw(20) << "" << endl;
}

/*****************************************************/
int query_ID()
{
    int menu_ID;
    cin >> menu_ID;
    cout << endl;
    return menu_ID;
}

char query_menu() 
{
    char tempInput;
    cin.ignore(100, '\n');
    tempInput = getchar();
    cout << endl;
    return tolower(tempInput);
}

/*****************************************************/

/*******************************************************
    Loads member data from a text file into a member BST
********************************************************/
void load_member_data(string file, BST_member& m_tree)
{
    member temp_reader;

    temp_reader.read_file(file, m_tree);
}

/****************************************************
    Loads provider data from a text file into a BST.
    Breaks all of our code for some reason. Unable to
    determine a solution
*****************************************************/
void load_provider_data(string file, BST_provider& p_tree)
{
    provider temp_reader;

    temp_reader.read(file, p_tree);
}



