#include "users.h"
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

typedef struct name_tree
{
    node* array_node;
    int pos;
    int size;
}name_tree;

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

//--------Name_Tree

static void more_node_nt (name_tree* t)
{
    t->size<<= 1;
    t->array_node= realloc (t->array_node, t->size);
}

static void new_node_nt (name_tree* t, char* name)
{
    if (t->pos== t->size)
        more_node_nt (t);
    node* n= &t->array_node[t->pos++];
    n->array_node= NULL;
    n->name= NULL;
}

static void init_array_node (node* n)
{
    n->array_node= calloc (SIZEARRAYNODE, sizeof (node));
    n->pos= 0;
    n->size= SIZEARRAYNODE;
}

static void more_node_node_array (node* n)                                      //Doubles the size of the node array refered by a node
{
    n->size<<= 1;
    n->array_node= realloc (n->array_node, n->size);
    for (void* i= &n->array_node[n->pos]; i< &n->array_node[n->size]; i++)      //Set the realloc unused cells to zeros
    {
        i= NULL;
    }
}

static void new_node_node_array (node* n, char* name, int id)                   //Adds a new node to the node array
{
    if (n->pos== n->size)
        more_node_node_array (n);
    n= &n->array_node[n->pos++];
    n->id= id; 
    n->name= name;
}

static void push_name_node (node* n, int l, char* name, int id)                 //Builds node tree with minimum depth
{
    if (n->name==NULL)
    {
        n->name= name;                                                              
        n->id= id;
        return;
    }
    if (n->array_node==NULL)
    {
        init_array_node(n);
        push_name_node (n->array_node, l+1, n->name, n->id);                        //Pushes the old termination node into the following node array
        push_name_node (n, l, name, id);                                            //Pushes the argument name/id pair into the reworked tree
        return;
    }
    int i= 0, bin= 0;
    for (; i< n->size; i++) if (n->array_node[i].name[l]== name[l]) bin= 1;
    if (!bin)                                                                       //Doesn't find node with the corresponding "l"th letter.
    {
        new_node_node_array (n, name, id);
    }
    push_name_node (&n->array_node[i], l+1, name, id);                              //If node with corresponding letter is found, fucntion is called recursively to the higher level corresponding node
}

static void push_name_tree (name_tree* t, char* name, int id)                   //Pushes a name into the name tree Data Structure
{
    int bin= 0, i= 0;
    node* n;
    for (; i< t->size && !bin; i++) if (t->array_node[i].name== *name) bin= 1;      //Finds the corresponing node of level 0 in the Name_Tree
    if (!bin)                                                                       //If nothing was found gets a new node with name's first letter
    {
        new_node_nt (t, name);
    }
    n= &t->array_node[i];                                                           //Node with the corresponding first letter 
    push_name_node (n, 0, name, id);
}


//--------API--------


array_user* init_array_user ()                                                  //Returns a User Array
{
    array_user* a= malloc (sizeof (array_user));
    a->user_array= malloc (SIZEARRAY* sizeof (User));
    a->pos= 0;
    a->size= SIZEARRAY;
    return a;
}

name_tree* init_name_tree ()                                                    //Returns a Name Tree
{
    name_tree* n= malloc (sizeof (name_tree));
    n->array_node= malloc (SIZEARRAYNODE* sizeof (node));
    n->pos= 0;
    n->size= SIZEARRAYNODE;
    return n;
}

void push_user (User u, array_user* a, name_tree* t)                            //Pushes a User into the data structure
{
    push_array_user (a, u);
    push_name_tree (t, u.name, a->pos);
}