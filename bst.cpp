#include "bst.h"

/*
    -------------------------
    Thomas Brooks
    Revision date: 11/22/2022
    -------------------------
*/

/*
    ----------------------------
    Provider tree implementation
    ---------------------------- 
*/

provider_node::provider_node()
{
    provider_data = NULL;
    left = right = NULL;
}

provider_node::provider_node(provider *& copy)
{
    left = right = NULL;
    provider_data = new provider(*copy);

}

provider_node::~provider_node()
{
    if(provider_data)
        delete(provider_data);
}

provider_node *& provider_node::go_left()
{
    return left;
}

provider_node *& provider_node::go_right()
{
    return right;
}

void provider_node::display()
{
    provider_data->display();
}

/*
    Ryan Addition: Provider data getter
*/

provider* provider_node::retrieve_provider_data()
{
    return provider_data;
}

//operator overloading stuff below
bool provider_node::greater(provider *& compare)
{
    return *provider_data > *compare;
}

bool provider_node::greater(int compare)
{
    return *provider_data > compare;
}

bool provider_node::equal(int compare)
{
    return *provider_data == compare;
}

BST_provider::BST_provider()
{
    root = NULL;
}

BST_provider::~BST_provider()
{
    if(root)
        delete_all(root);
}

void BST_provider::delete_all(provider_node *& root)
{
    //traverse to leaves, delete as we return
    delete_all(root->go_left());
    delete_all(root->go_right());

    delete root;
    root = NULL;
}

//wrapper for adding provider
void BST_provider::add_new_provider_(provider *& to_add)
{
    add_provider(to_add, root);
}

//adding a provider, comparing using operator overloading
void BST_provider::add_provider(provider *& to_add, provider_node *& root)
{
    //first case, empty tree
    if(!root)
    {
        root = new provider_node(to_add);    
        return;
    }

    if(root->greater(to_add))
        add_provider(to_add, root->go_left());
    else
        add_provider(to_add, root->go_right());

    return;
}

bool BST_provider::remove_provider_(int ID)
{
    return remove_provider(ID, root);
}

bool BST_provider::remove_provider(int ID, provider_node *& root)
{
    //base case
    if(!root)
        return false;

    bool found = false;
    if(root->greater(ID))
        found = remove_provider(ID, root->go_left()); //match in left subtree

    else if(!root->greater(ID) && !root->equal(ID))
        found = remove_provider(ID, root->go_right()); //match in right subtree

    //match found
    else
    {
        //match found at a leaf
        if(!root->go_left() && !root->go_right())
        {
            delete root;
            root = NULL;
            return true;
        }

        //one right child, no left children
        if(!root->go_left() && root->go_right())
        {
            provider_node * hold = root->go_right();
            delete root;
            root = hold;
            return true;
        }

        //one left child, no right children
        if(root->go_left() && !root->go_right())
        {
            provider_node * hold = root->go_left();
            delete root;
            root = hold;
            return true;
        }

        //two children, need to find IOS before deleting
        if(root->go_left() && root->go_right())
        {
            provider_node * hold = root;
            provider_node * ios;

            //checking first if there IS an IOS
            if(root->go_right()->go_left())
            {
                find_ios(root->go_right(), ios);
                root = ios;
                root->go_left() = hold->go_left();
                root->go_right() = hold->go_right();
            }

            //no IOS exists
            else
            {
                root = hold->go_right();
                root->go_left() = hold->go_left();
            }

            delete hold;
            return true;
        }
    }
    //match not found
    return found;
}

//finds a node's IOS
void BST_provider::find_ios(provider_node *& root, provider_node *& ios)
{
    if(!root->go_left()->go_left())
    {
        ios = root->go_left();
        root->go_left() = root->go_left()->go_right();
        return;
    }

    find_ios(root->go_left(), ios);
}

//displays by a given ID match
bool BST_provider::display_by_ID(int ID)
{
    return display_ID(ID, root);
}

bool BST_provider::display_ID(int ID, provider_node *& root)
{
    if(!root)
        return false;

    bool found = false;
    found = display_ID(ID, root->go_left());
    if(root->equal(ID))
    {
        root->display();
        return true;
    }
    found = display_ID(ID, root->go_right());

    return found;
}

/*
    Ryan Additions: Search and retrieve
*/

bool BST_provider::search_by_ID(int ID)
{
    return search_ID(ID, root);
}

bool BST_provider::search_ID(int ID, provider_node *& root)
{
    if(!root)
        return false;

    bool found = false;
    found = display_ID(ID, root->go_left());
    if(root->equal(ID))
    {
        return true;
    }
    found = display_ID(ID, root->go_right());

    return found;
}

provider* BST_provider::retrieve_provider(int ID)
{
    return retrieve_provider(ID, root);
}

provider* BST_provider::retrieve_provider(int ID, provider_node *& root)
{
    if(!root)
        return NULL;

    
    display_ID(ID, root->go_left());
    if(root->equal(ID))
    {
        return root->retrieve_provider_data();
    }
    display_ID(ID, root->go_right());

    return NULL;
}


int BST_provider::count_nodes()
{
    if(!root)
        return 0;
    
    return count_nodes(root);
}

int BST_provider::count_nodes(provider_node * root)
{
    //base case
    if(!root)
        return 0;

    int count = count_nodes(root->go_left()) + count_nodes(root->go_right());
    return 1 + count;
}

void BST_provider::display_tree_() 
{
    display_tree(root);
}

void BST_provider::display_tree(provider_node * root)
{
    //base case
    if(!root)
        return;

    //inorder traversal display
    display_tree(root->go_left());
    root->display();
    display_tree(root->go_right());
}

/*
    --------------------------
    Member tree implementation
    --------------------------
*/

member_node::member_node()
{
    member_data = NULL;
    left = right = NULL;
}

member_node::member_node(member *& copy)
{
    left = right = NULL;
    member_data = new member(*copy);
}

member_node::~member_node()
{
    if(member_data)
        delete(member_data);
}

member_node *& member_node::go_left()
{
    return left;
}

member_node *& member_node::go_right()
{
    return right;
}

void member_node::display()
{
    member_data->display();
}

/*
    Ryan Addition: Getter for member data
*/
member* member_node::retrieve_member_data()
{
    return member_data;
}

//operator overloading stuff
bool member_node::greater(member *& compare)
{
    return *member_data > *compare;
}

bool member_node::greater(int compare)
{
    return *member_data > compare;
}

bool member_node::equal(int compare)
{
    return *member_data == compare;
}

BST_member::BST_member()
{
    root = NULL;
}

BST_member::~BST_member()
{
    if(root)
        delete_all(root);
}

void BST_member::delete_all(member_node *& root)
{
    //traverse to leaves, delete as we return
    delete_all(root->go_left());
    delete_all(root->go_right());

    delete root;
    root = NULL;
}

void BST_member::add_new_member_(member *& to_add)
{
    add_member(to_add, root);
}

void BST_member::add_member(member *& to_add, member_node *& root)
{
    if(!root)
    {
        root = new member_node(to_add);
        return;
    }

    if(root->greater(to_add))
        add_member(to_add, root->go_left());
    else
        add_member(to_add, root->go_right());

    return;
}

bool BST_member::remove_member_(int ID)
{
    return remove_member(ID, root);
}

bool BST_member::remove_member(int ID, member_node *& root)
{
    if(!root)
        return false;

    bool found = false;
    if(root->greater(ID))
        found = remove_member(ID, root->go_left()); //match in left subtree

    else if(!root->greater(ID) && !root->equal(ID)) //match in right subtree
        found = remove_member(ID, root->go_right());

    //match found
    else
    {
        //match found at leaf
        if(!root->go_left() && !root->go_right())
        {
            delete root;
            root = NULL;
            return true;
        }

        //one right child, no left children
        if(!root->go_left() && root->go_right())
        {
            member_node * hold = root->go_right();
            delete root;
            root = hold;
            return true;
        }

        //one left child, no right children
        if(root->go_left() && !root->go_right())
        {
            member_node * hold = root->go_right();
            delete root;
            root = hold;
            return true;
        }

        if(root->go_left() && root->go_right())
        {
            member_node * hold = root;
            member_node * ios;

            if(root->go_right()->go_left())
            {
                find_ios(root->go_right(), ios);
                root = ios;
                root->go_left() = hold->go_left();
                root->go_right() = hold->go_right();
            }

            else
            {
                root = hold->go_right();
                root->go_left() = hold->go_left();
            }

            delete hold;
            return true;
        }
    }

    //match not found
    return found;
}

//makes things easier with removal
void BST_member::find_ios(member_node *& root, member_node *& ios)
{
    if(!root->go_left()->go_left())
    {
        ios = root->go_left();
        root->go_left() = root->go_left()->go_right();
        return;
    }

    find_ios(root->go_left(), ios);
}

bool BST_member::display_by_ID(int ID)
{
    return display_ID(ID, root);
}

bool BST_member::display_ID(int ID, member_node *& root)
{
    if(!root)
        return false;

    bool found = false;
    found = display_ID(ID, root->go_left());
    if(root->equal(ID))
    {
        root->display();
        return true;
    }
    found = display_ID(ID, root->go_right());

    return found;
}

/*
    Ryan BST Addition: search by ID
*/
bool BST_member::search_by_ID(int ID)
{
    return search_ID(ID, root);
}

bool BST_member::search_ID(int ID, member_node *& root)
{
    if(!root)
        return false;

    bool found = false;
    found = search_ID(ID, root->go_left());
    if(root->equal(ID))
    {
        return true;
    }
    found = search_ID(ID, root->go_right());

    return found;
}

member* BST_member::retrieve_member(int ID)
{
    return retrieve_member(ID, root);
}

member* BST_member::retrieve_member(int ID, member_node *& root)
{
    if(!root)
        return NULL;

    
    search_ID(ID, root->go_left());
    if(root->equal(ID))
    {
        return root->retrieve_member_data();
    }
    search_ID(ID, root->go_right());

    return NULL;
} 

/*
    End Ryan Additions
*/

void BST_member::display_tree_()
{
    display_tree(root);
}

void BST_member::display_tree(member_node * root)
{
    //base case
    if(!root)
        return;

    //inorder traversal display
    display_tree(root->go_left());
    root->display();
    display_tree(root->go_right());
}