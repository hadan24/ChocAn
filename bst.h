//contains definitions for BST stuff
//feel free to make changes as needed

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