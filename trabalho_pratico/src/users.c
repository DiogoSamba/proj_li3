#include "users.h"
#define SMALL_A 10
#define SIZEARRAY 1000
#define SIZELL 6
/*User
    username;name;gender;birth_date;account_creation;pay_method;account_status
    querrys
        nome (Hash table)
        distancia viajada
        genero
        data cri
*/

//--------Structs

struct lista_l
{
    char letter;
    int pos;
    int size;
    int id;
    struct lista_l* l;
};

struct array_user
{
    int pos;
    int size;
    User* array;
};

typedef struct name_tree
{
    int pos;
    int size;
    struct lista_l* l;
}name_tree;

//--------Functions

name_tree* init_Name_Tree ()                                                        //Devolve uma name tree
{
    name_tree* nt= malloc(sizeof (name_tree));
    nt->pos= 0;
    nt->size= SIZELL;
    nt->l= malloc (SIZELL* sizeof (struct lista_l));
    return nt; 
}

struct array_user* init_array_user ()
{
    struct array_user* au= malloc (sizeof (struct array_user));
    au->pos= 0;
    au->size= SIZEARRAY;
    au->array= malloc (SIZEARRAY* sizeof (User));
    return au;
}
