#include "users.h"
#include <string.h>
#define SMALL_A 10
#define SIZEARRAY 1000
#define SIZEARRAYNODE 4
/*User
    username;name;gender;birth_date;account_creation;pay_method;account_status
    querrys
        nome (Hash table)
        distancia viajada
        genero
        data cri
*/

//--------Structs--------

typedef struct node 
{
    char* name;
    int id;
    struct node* array_node;
    int pos;
    int size;
}node;

typedef struct node_tree
{
    node* array_node;
    int pos;
    int size;
}node_tree;

typedef struct array_user
{
    User* user_array;
    int pos;
    int size;
}array_user;


//--------Functions--------


//--------Array_User

static void more_array_user (array_user* a)                                     //Doubles the size of Array_User
{
    a->size<<= 1;
    a->user_array= realloc (a->user_array, a->size);
}

static void push_array_user (array_user* a, User u)                             //Pushes User into Array_User
{
    if (a->pos== a->size)
        more_array_user (a);
    a->user_array[a->pos++]= u;
}

//--------Tree

static node_array* init_array_node ()

static node_tree* init_node_tree ()
{
    node_tree* t= malloc (sizeof (node_tree));
    
}

//--------API--------


node_tree* init_node_tree ()
{
    node* n= malloc (sizeof (node));
    n->array_node
}

array_user* init_array_user ()                                                  //Returns a User Array
{
    array_user* a= malloc (sizeof (array_user));
    a->user_array= malloc (SIZEARRAY* sizeof (User));
    a->pos= 0;
    a->size= SIZEARRAY;
    return a;
}

void push_user (User u, array_user* a, node* n)                            //Pushes a User into the data structure
{
    push_array_user (a, u);
    push_tree (u.name, a->pos);
}