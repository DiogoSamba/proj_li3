#ifndef USERS
#define USERS
#include <stdlib.h>

typedef struct user
{
    char* user_n;
    char* name;
    char gender;
    int birth_date [3];
    int acc_creat [3];
    char pay_meth;                                                                  //0 Cash 1 CCard 2 DCard
    char acc_status;
}User;


typedef struct array_user* Array_User;
typedef struct node_tree* Node_Tree;

Name_Tree init_name_tree ();                                                    //Returns a Name Tree
Array_User init_array_user ();                                                  //Returns a User Array
void push_user (User u, Array_User a, Name_Tree t);                             //Pushes a User into the data structure
#endif