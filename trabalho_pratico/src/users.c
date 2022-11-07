#include "users.h"
#define SMALL_A 10
#define SIZEARRAY 1000

/*User
    username;name;gender;birth_date;account_creation;pay_method;account_status
    querrys
        nome (Hash table)
        distancia viajada
        genero
        data cri
*/

//--------Structs

typedef struct user
{
    char* user_n;
    char* name;
    char gender;
    int birth_date [3];
    int acc_creat [3];
    char pay_meth;                                                              //0 Cash 1 CCard 2 DCard
    char acc_status;
}User ;

typedef struct a_ussr
{
    User* array;
    int size;
    int pos;
}array_user;

typedef struct user_name_ref
{
    char* name;
    int id;
}a_name_id;

typedef struct letter_l
{
    char letter;
    a_name_id** unr;
    int size;
    int pos;
}Letter_l;

typedef struct name_tree
{
    Letter_l* letter_list;
    int size;
    int pos;
}Name_T;

//--------Functions--------

//--------Name Tree Functions

Name_T* i_name_tree ()                                                  //Devolve uma name tree
{
    Name_T* t= malloc (sizeof (Name_T));
    t->letter_list= malloc (10* sizeof (Letter_l));
    t->size= 10;
    return t;
}


void m_size_n_l (Letter_l* l)                                           //Aux to push
{
    l->size<<= 1;                                                           //Sets size of l to double
    l->letter= realloc (l->letter, l->size);                                //Reallocates into a cell double the prev size
}

void push_n_l (Letter_l* l, char* name, int id)                         //Push into list of the given letter
{
    if (l->pos== l->size)                                                   //Redimensiona o array se ultrapassar o tamanho definido
        m_size_n_l (l);
    l->unr[l->pos]->name= name;                                             //Assignment of name field
    l->unr[l->pos]->id= id;                                                 //Assignment of id field
    l->pos++;                                                               //Increments pos
}

void m_size_name_t (Name_T* t)                                          //Makes letter_list double the size
{
    t->size<<= 1;
    t->letter_list= realloc (t->letter_list, t->size);
}

a_name_id* i_unr_a ()                                                   //Creates list of Name-ID pairs
{
    a_name_id* a= malloc (SIZEARRAY * sizeof (a_name_id));                            
    return a;
}

void push_letter_name_t (Name_T* t, char* name)                         //Creates branch for the given letter
{
    if (t->pos== t->size)
        m_size_name_t (t);
    t->letter_list[t->pos].letter= name[0];                                 //Sets the letter on the letter list to the first of the name (prob will be changed)
    t->letter_list[t->pos].unr= i_unr_a ();                                 //Creates array of the given letter
    t->letter_list[t->pos].size= SIZEARRAY;                                 //Sets size of the "unr" array to it's alocated size
    t->letter_list[t->pos].pos= 0;                                          //Sets array position to 0;
    t->pos++;                                                               //Increments position
}

void push_name (char* name, Name_T* t, int id)                          //Pushes a name into the name search struct and refers it's corresponding user
{
    int n;
    int bin= 1;
    for (int i= 0; i< t->size; i++)
    {
        if (t->letter_list[i].letter== name[0])                             //Finds the letter, refers it and leaves the cycle.
            n=i; i= t->size; bin= 0;                                        //n variable stores the index when the searched for letter is found.
    }
    if (bin)
        push_letter_name_t (t, name);                                       //If a list with the same letter is not found, creates one. 
    push_n_l (&t->letter_list[n], name, id);                                //Pushes given name into list of elements of same starting letter 
}

//--------Array of Users Functions 

array_user* i_array_user ()                                             //Creates array of users. Each user is given an id corresponding to its index in this array
{
    array_user* a= malloc (sizeof (array_user));
    a->pos= 0;
    a->size= SIZEARRAY;
    a->array= malloc (SIZEARRAY* sizeof (User));
}

void m_size_a_user (array_user* a)                                      //Sets given cell to double its prev size
{
    a->size<<= 1;
    a->array= realloc(a->array, a->size);
}


void push_a_user (User* u, array_user* a)                               //Pushes given element into given array
{
    if (a->size== a->pos)
        m_size_a_user (a);
    a->array[a->pos++]= *u;
}

//--------Name-ID Pairs


void push_user (User* u, gender_t g, array_user* a, Name_T* t, int id)  //Pushes User
{   
    push_a_user (u, a);                                                     //Pushes user struct into array_user
    push_name (u->name, t, id);                                             //Pushes name into Name Tree
}

int search_name_t (Name_T* t, char* name)
{
    for (int i= 0; i< t->size; i++)
        if (t->letter_list[i].letter== *name)
            for (int j= 0; j< t->size; j++)
                if (!strcomp (t->letter_list[i].unr[j]->name, name))
                    return t->letter_list[i].unr[j]->id;
}

User get_user_name (array_user* a, Name_T* t, char* name)
{
    return a->array[search_name_t (t, name)];
}