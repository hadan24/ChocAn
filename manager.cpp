// @anhho
#include "bst.h"

manager::manager(): manager_ID(000), manage_p(NULL), manage_m(NULL)
{}

manager::manager(const manager & copy):manager_ID(copy.manager_ID), manage_p(copy.manage_p), manage_m(copy.manage_m)
{}

manager::~manager()
{
    // leave it empty if there is nothing alloacted memory 
}


// Manger manges the MEMBER terminal - begin
void manager::add_member(BST_member *& mange_m)
{
    member * new_member = new member();
    new_member->input();
    mange_m->add_new_member_(new_member);
}

bool manager::remove_member(BST_member *& mange_m)
{
    int temp_id = 0;
    cout << "\n\tPlease enter an ID of the membership you want to remove:  ";
    cin >> temp_id;
    if (manage_m->remove_member_(temp_id)){
        cout << "\n\t Successfully removed the membership by ID!";
        return true;
    }
    cout << "\n\t Unable to remove the membership!";
    return false;    
}


bool manager::search_display_member(BST_member *& mange_m)
{
    int temp_id = 0;
    cout << "\n\tPlease enter an ID of the membership you want to search and display:  ";
    cin >> temp_id;
    if (manage_m->display_by_ID(temp_id)){
        cout << "\n\t Successfully found the membership by ID!";
        return true;
    }
    cout << "\n\t Unable to find the membership!";
    return false;    
}

void manager::display_member(BST_member * manage_m) const 
{
    manage_m->display_tree_();
}
// Manger manges the MEMBER terminal - end
//////////////////////////////////////////////////////////
// Manger manges the PROVIDER terminal - begin
void manager::add_provider(BST_provider *& mange_p)
{
    provider * new_provider = new provider();
    new_provider->input();
    mange_p->add_new_provider_(new_provider);
}

bool manager::remove_provider(BST_provider *& mange_p)
{
    int temp_id = 0;
    cout << "\n\tPlease enter an ID of the provider you want to remove:  ";
    cin >> temp_id;
    if (mange_p->remove_provider_(temp_id)){
        cout << "\n\t Successfully removed the provider by ID!";
        return true;
    }
    cout << "\n\t Unable to remove the provider!";
    return false;    
}


bool manager::search_display_provider(BST_provider *& mange_p)
{
    int temp_id = 0;
    cout << "\n\tPlease enter an ID of the membership you want to search and display:  ";
    cin >> temp_id;
    if (mange_p->display_by_ID(temp_id)){
        cout << "\n\t Successfully found the membership by ID!";
        return true;
    }
    cout << "\n\t Unable to find the membership!";
    return false;    
}

void manager::display_provider(BST_provider * manage_p) const 
{
    manage_p->display_tree_();
}
// Manger manges the PROVIDER terminal - end

