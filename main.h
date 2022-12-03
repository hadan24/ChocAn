#include "bst.h"


//Menu Display Block
void print_header();
void print_welcome();
void member_menu();
void provider_menu();
void manager_menu();
void print_line_break();

//Query Block
int query_ID();
char query_menu();

void load_member_data(string file, BST_member& m_tree);
void load_provider_data(string file, BST_provider& p_tree);
