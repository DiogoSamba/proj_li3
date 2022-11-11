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
typedef struct node_array* Node_Array;

Node_Array init_node_array ();                                                  //Returns a Node Array
Array_User init_array_user ();                                                  //Returns a User Array
void push_user (User u, Array_User a_u, Node_Array n_a);                        //Pushes a User into the data structure
int get_user_id (Node_Array n_a, char* name);                                   //Returns User ID 
User get_user (int id, Array_User arr_u);                                        //Returns User given ID
#endif