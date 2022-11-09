#include "users.h"
#include <string.h>
#define SMALL_A 20
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

struct node;

typedef struct node_array
{
    struct node* array;
    int size;
}node_array;

typedef struct node 
{
    char* name;
    int id;
    node_array* a;
}node;

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
    a->user_array= realloc (a->user_array, a->size* sizeof (User));
}

static void push_array_user (array_user* a, User u)                             //Pushes User into Array_User
{
    if (a->pos== a->size)
        more_array_user (a);
    a->user_array[a->pos++]= u;
}

//--------Tree

static void more_node_array (node_array* a)                                     //Reallocs node array to allow more space
{
    a->size<<= 1;
    a->array= realloc (a->array, a->size* sizeof (node));
}

static void push_node_array (node_array* a, char* name, int id, int l);

static void set_node_up (node* n)                                               //Sets the node into a higher level of the reference tree
{
    n->a= init_node_array ();
    push_node_array (n->a, n->name, n->id, 0);                                      //The "level" parameter of this instruction doesn't matter as we know for a fact that our push_node_array call will branch into the "a->array[0].nome== NULL" case
}

static void push_node_array (node_array* a, char* name, int id, int l)          //Pushes a node into a node array
{
    int i= 0;
    for (; i< a->size; i++)
    {
        if (a->array[i].name== NULL)                                                //Found an unoccupied position
        {
            a->array[i].name= name;
            a->array[i].id= id;
            return;
        }
        if (a->array[i].name[l]== name[l])                                          //Found a node with the same letter at the same level
        {
            if (a->array[i].a== NULL)                                               //If the node doesn't have an inicialized array (the node had a unique symbol combination)
                set_node_up (&a->array[i]);
            push_node_array (a->array[i].a, name, id, l+1);                          //Recalls the function after the node structure has been changed
            return;
        }
    }                                                                               //We can correctly assume we weren't able to find neither an open space nor a matching letter for our fucntion. As such, we need to get some space
    more_node_array (a);                                                            //We get more space
    a->array[i].name= name;                                                         //Here*     We solve the push by using the 'i' variable that made it all the way to the old a->size
    a->array[i].id= id;                                                             //Here*
}


//--------API--------


node_array* init_node_array ()                                                  //Returns a Node Array
{
    node_array* a= malloc (sizeof (node_array));                                
    a->array= calloc (SMALL_A, sizeof (node));                                  //Allocates memory for node array refered in the struct
    a->size= SMALL_A;
    return a;
}

array_user* init_array_user ()                                                  //Returns a User Array
{
    array_user* a= malloc (sizeof (array_user));
    a->user_array= malloc (SIZEARRAY* sizeof (User));
    a->pos= 0;
    a->size= SIZEARRAY;
    return a;
}

void push_user (User u, array_user* a_u, node_array* n_a)               //Pushes a User into the data structure
{
    push_array_user (a_u, u);                                                       //Pushes user into the user_array thus matching the user with it's array index
    push_node_array (n_a, u.user_n, a_u->pos-1, 0);                                         //Combined function call to match a user_name with the user id (index in the user_array)
}