// Run test:     g++ -g *.cpp *.h -o chocan -Wall
#include "main.h"


int main()
{
    cout << "Did somebody say...chocolate?" << endl;
    
    // testing member class 
    // member test_mem;
    // test_mem.input();
    // test_mem.display();
    // test_mem.update_status();
    // test_mem.display();

/* Leaving all these comments here for now for future reference of testing or how to use classes - Dan
    // testing member class 
    // member test_mem;
    // test_mem.input();
    // test_mem.display();
    // test_mem.update_status();
    // test_mem.display();

    how to run manager class
    base 
	BST_provider * provider_management;		// control all the list of providers 
	BST_member * member_management;			// control all the list of members 
	manager test_manager;					// assume one manager
 	member * test_mem;
	provider * test_provider; 

    how manager requests to add a new provider. it should be the same as the mem
    manager has the add provider function. We pass the new provider obj to the function, then add into a leaf. : ) 

    test_manager.add_provider(provider_management);   // call the from manager class

    at the manager class: 
        add_proivder(BST_provider *& provider_management)
        {
            // create a new object of provider. 
            provider * new_provider_object = new provider(); // allocate memory because each memory will hold one provider obj basically  
            new_provider_object->input(); // this new provider obj will store all the info data

            // add_Into_Tree is a function from BST_provider 
                provider_management->add_Into_Tree(new_provider_object); 

                // root->provider_data = new_provider_object  // passing a new object into a new node.
                ...
        }

   // same as for the member
   test_manager.add_member(member_management); 
*/

	// Ryan's menu stuff
    int tempID; //This variable is for testing the menu: this would be the class member's ID
    char menu_input;
    print_header();

    print_welcome();
    tempID = query_ID();

    if (tempID == 1) {
        do {
            provider_menu();
            cout << "Select a Function: ";
            menu_input = query_menu();
            switch(menu_input) {
                case 's':
                    cout << "Checking Member Status..." << endl;
                    break;
                case 'i':
                    cout << "Searching ID..." << endl;
                    break;
                case 'c':
                    cout << "Charging Member..." << endl;
                    break;
                case 'd':
                    cout << "Requesting Provider Directory..." << endl;
                    break;
                case 'a':
                    cout << "Adding Member..." << endl;
                    break;
                case 'r':
                    cout << "Removing Member" << endl;
                    break;
                case 'u':
                    cout << "Updating Member Information..." << endl;
                    break;
                case 'o':
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
    else if (tempID == 2) {
        do {
            member_menu();
            cout << "Select a Function: ";
            menu_input = query_menu();
            switch (menu_input) {
                case 's':
                    cout << "Requesting service..." << endl << endl;
                    break;
                case 'r':
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
    else if (tempID == 3) {
        do {
            manager_menu();
            cout << "Select a Function: ";
            menu_input = query_menu();
            switch (menu_input) {
                case 'p':
                    cout << "Printing Weekly Report" << endl;
                    break;
                case 'a':
                    cout << "Adding Member" << endl;
                    break;
                case 'd':
                    cout << "Removing Member" << endl;
                    break;
                case 'k':
                    cout << "Adding Provider..." << endl;
                    break;
                case 'r':
                    cout << "Removing Provider..." << endl;
                    break;
                case 'u':
                    cout << "Updating Member Information..." << endl;
                    break;
                case 's':
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
    cout << "Welcome to ChocAn!" << endl << endl
         << "Please enter your ID number: ";
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
    cout << "c: Charge Member for Service(s)" << endl;
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
    int tempID;
    cin >> tempID;
    cout << endl;
    return tempID;
}

char query_menu() 
{
    char tempInput;
    cin.ignore(100, '\n');
    tempInput = getchar();
    cout << endl;
    return tolower(tempInput);
}



