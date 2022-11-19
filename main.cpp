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


//////////////////////////////////////////////////////
    // how to run manager class
    // base 
    BST_provider * provider_management; // control all the list of providers 
    BST_member * member_management;
    manager * test_manager;
    member * test_mem;
    provider * test_provider; 

    // how manager requests to add a new provider. it should be the same as the mem
    // manager has the add provider function. We pass the new provider obj to the function, then add into a leaf. : ) 
 //   test_manager->add_provider(provider_management);   // call the from manager class
    /*
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

    */


    
}