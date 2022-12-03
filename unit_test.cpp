#include "bst.h"
#include <assert.h>
#include <sstream>

//testing member class
int test_mem_verify_ID(int ID)
{
	member myMember;
	myMember.set_ID(ID);
	assert((myMember.verify_ID(ID) == 1));
	return 1;
}

int test_mem_input(int ID, bool status, float fee)
{
	member myMember;
	myMember.set_input(ID, status, fee);
	assert(myMember.get_member_ID() == ID);
	assert(myMember.get_status_mem() == status);
	assert(myMember.get_fee_mem() == fee); 
	return 1;

}

int test_mem_update_status(bool status)
{
	member myMember;
	myMember.set_status(status);	
	assert(myMember.get_status_mem() == status);

	return 1;
}

int test_member_display()
{
	std::stringstream ss;
	member myMember;
	myMember.set_input(123456789, true, 1000);
//	myMember.display(ss);
	assert(ss.str() == "\n\tMember Information:\n\tThe ID of the membership           :  123456789\n\tThe status of the membership       :  VALID!\n\tThe fee of the membership          :  1000");	
	return 1;
}
//testing provider class
int test_provider_verify_ID(int ID)
{       
        provider myProvider;
        myProvider.set_ID(ID);
        assert(myProvider.verify_provider_ID(ID) == 1);
        return 1;
}

int test_provider_display()
{
        std::stringstream ss;
        provider myProvider;
        myProvider.setInput(123456789, 10, 100);
        myProvider.display(ss);
	assert(ss.str() == "\n\tThe ID of the provider:  123456789\n\tThe number of consultations:  10\n\tThe fee of the membership:  100\n\tThe services list:  \n\n");
        return 1;
}

int test_provider_input(int ID, int num, int fee)
{
	provider myProvider;
	myProvider.setInput(ID, num, fee);
	assert(myProvider.get_provider_ID() == ID);
	assert(myProvider.get_num_consul() == num);
	assert(myProvider.get_total_fee() == fee);	

	return 1;
}

//testing BST
int test_provider_BST_add(const string& first, const string& last, const string& address, const string& city, const string& state, int zipcode, const string& email, int num, int ID, float fee, BST_provider * providerTree)
{
	service_list * list = new service_list();	
	provider myProvider(first, last, address, city, state, zipcode, email, num, ID, fee, list);
	provider * myProvider1 = &myProvider;
	providerTree->add_new_provider_(myProvider1);
	assert(providerTree->display_by_ID(ID) == true);
	delete list;
	return 1;
}

//Unit test 4
int test_member_BST_add(const string& first, const string& last, const string& address, const string& city, const string& state, int zipcode, const string& email, int ID, bool status, float fee, BST_member * memberTree)
{
	service_list * list = new service_list();
	member myMember(first, last, address, city, state, zipcode, email, status, ID, fee, list);
	member * myMember1 = &myMember;

	memberTree->add_new_member_(myMember1);
	assert(memberTree->display_by_ID(ID) == 1);
	delete list;
	return 1;
}

int test_provider_BST_remove(int ID, int num, int fee, BST_provider * providerTree)
{
	provider * myProvider = new provider;
	myProvider->setInput(ID, num, fee);
	providerTree->add_new_provider_(myProvider);
	assert(providerTree->display_by_ID(ID) == 1);
	assert(providerTree->remove_provider_(ID) == 1);
	assert(providerTree->display_by_ID(ID) == 0);	

	return 1;
}

int test_member_BST_remove(int ID, bool status, float fee, BST_member * memberTree)
{
	member * myMember = new member;
        myMember->set_input(ID, status, fee);
        memberTree->add_new_member_(myMember);
	assert(memberTree->display_by_ID(ID) == 1);
	assert(memberTree->remove_member_(ID) == 1);
	assert(memberTree->display_by_ID(ID) == 0);
	
	return 1;
}

int test_member_greater()
{
	member * smallerMem = new member;
	member * largerMem = new member;
	smallerMem->set_ID(111111111);
	largerMem->set_ID(222222222);
	assert(largerMem>smallerMem == 1);
	assert(smallerMem>largerMem == 0);

	return 1;	
}

int test_member_lesser()
{
        member * smallerMem = new member;
        member * largerMem = new member;
        smallerMem->set_ID(111111111);
        largerMem->set_ID(222222222);
        assert(largerMem<smallerMem == 0);
        assert(smallerMem<largerMem == 1);

        return 1;
}

int test_provider_greater()
{
        provider * smallerProv = new provider;
        provider * largerProv = new provider;
        smallerProv->set_ID(111111111);
        largerProv->set_ID(222222222);
        assert(largerProv>smallerProv == 1);
        assert(smallerProv>largerProv == 0);

        return 1;
}

int test_provider_lesser()
{
	provider * smallerProv = new provider;
        provider * largerProv = new provider;
        smallerProv->set_ID(111111111);
        largerProv->set_ID(222222222);
        assert(largerProv<smallerProv == 0);
        assert(smallerProv<largerProv == 1);
        return 1;
}

int main()
{
	BST_member * memberTree = new BST_member;
	BST_provider * providerTree = new BST_provider;
	manager myManager;

	if(test_mem_verify_ID(123456789) && test_mem_verify_ID(234567891) && test_mem_verify_ID(456789123))
		cout << "Unit test 1: Completed successfully. Member function verify_ID() runs without errors." << endl;

	if(test_mem_input(123456789, true, 23.5) && test_mem_input(987654321, true, 1))
		cout << "Unit test 2: Completed successfully. Member function setInput() runs without errors." << endl;
	
	if(test_mem_update_status(true) && test_mem_update_status(false))
		cout << "\nUnit test 3: Completed successfully. Member function set_status() runs without errors." << endl;	

	if(test_member_BST_add("Layla", "Smith", "1234 WhereamI", "Portland", "OR", 97016, "laysmith@pdx.edu", 123456789, true, 10, memberTree))
		cout << "\nUnit test 4: Completed successfully. BST function add_new_member() runs without errors." << endl;

	if(test_provider_BST_add("Layla", "Smith", "1234 WhereamI", "Portland", "OR", 97016, "laysmith@pdx.edu", 100,123456789, 10, providerTree))
		cout << "\nUnit test 5: Completed successfully. BST function add_new_provider() runs without errors." << endl;

	if(test_provider_BST_remove(121212121, 1000, 100, providerTree))
		cout << "\nUnit test 6: Completed successfully. BST function remove_provider_() runs without errors." << endl;
	
	if(test_member_BST_remove(121212121, 1000, 100, memberTree))
		cout << "\nUnit test 7: Completed successfully. BST function remove_member_() runs without errors." << endl;
	
	if(test_provider_input(367530912, 101, 420))
		cout << "\nUnit test 8: Completed successfully. Provider function setInput() runs without errors." << endl;

	if(test_provider_display())
		cout << "\nUnit test 9: Completed successfully. Provider function display() runs without errors." << endl;

	if(test_member_display())
                cout << "\nUnit test 10: Completed successfully. Member function display() runs without errors." << endl;

	if(test_provider_verify_ID(123456789) && test_provider_verify_ID(987654321))
                cout << "\nUnit test 11: Completed successfully. Provider function setInput() runs without errors." << endl;

	if(test_member_greater())
		cout << "\nUnit test 12: Completed successfully. Member overloaded operator > runs without errors." << endl;

	if(test_member_lesser())
		cout << "\nUnit test 13: Completed successfully. Member overloaded operator < runs without errors." << endl;	

	if(test_provider_greater())
		cout << "\nUnit test 14: Completed successfully. Provider overloaded operator > runs without errors." << endl;

	if(test_provider_lesser())
		cout << "\nUnit test 15: Completed successfully. Provider overloaded operator < runs without errors." << endl;
	return 0;
}
