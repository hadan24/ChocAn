#include "main.h"

int main()
{
    cout << "Did somebody say...chocolate?" << endl;
    
    // testing member class 
    member test_mem;
    test_mem.input();
    test_mem.display();
    test_mem.update_status();
    test_mem.display();

    // testing provider class
    provider test_provider;
    test_provider.input();
}