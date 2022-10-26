#include "users.h"

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

typedef struct user_l
{
    User* list;
    int pos;
    int siz;
}User_l ;

struct user_name_ref
{
    char* name;
    int id;
};

typedef struct letter_l
{
    char letter;
    struct user_name_ref* unr;
    int sz;
    int pos;
}Letter_l;

typedef struct name_tree
{
    Letter_l* letter_list;
    int size;
    int pos;
}Name_T;

//--------Functions

User_l* i_user_l ()                                                     //Devolve array para guardar os users
{
    User_l* l= malloc (sizeof (User_l));
    l->list= malloc (100* sizeof (User));
    l->pos= 0;
    l->siz= 100;
    return l;
}

Name_T* i_name_tree ()                                                  //Devolve uma name tree
{
    Name_T* t= malloc (sizeof (Name_T));
    t->letter_list= malloc (10* sizeof (Letter_l));
    t->size= 10;
    return t;
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
    a->array[a->pos]= *u;
}

void m_size_n_l (Letter_l* l)                                           //Aux to push
{
    l->sz<<= 1;                                                         //Sets size of l to double
    l->letter= realloc (l->letter, l->sz);                                //Reallocates into a cell double the prev size
}

void push_n_l (Letter_l* l,char* name, int id)                          //Push into list of the given letter
{
    if (l->pos== l->sz)                                                 //Redimensiona o array se ultrapassar o tamanho definido
        m_size_n_l(l);
    l->unr->name= name;                                                 //Assignment of name field
    l->unr->id= id;                                                  //Assignment of adr field
    l->pos++;                                                           //Increments pos
}

void push_letter_name_t (Name_T* t, char* name)                         //FIXME
{
    /* if (t->pos== t->size)
        //m_size_name_t (t);
    t->letter_list[t->pos]=  */
    
}

void push_name (char* name, Name_T* t, int id)                           //Pushes a name into the name search struct and refers it's corresponding user
{
    Letter_l* l;
    int bin= 0;
    for (int i= 0; i< t->size; i++)
    {
        if (t->letter_list[i].letter== name[0])                            //Finds the letter, refers it and leaves the cycle.
            l= &t->letter_list[i]; i= t->size; bin= 1;
    }
    if (bin)
        push_n_l (l, name, id);                                             //Pushes given name into list of elements of same starting letter 
    /* else
        Mete letra na NAME TREE e manda pah la essa merda */
}

void push_user (User* u, gender_t g, array_user* a, Name_T* t, int id)  //Pushes User
{   
    push_a_user (u, a);                                                 //Pushes user struct into array_user
    push_name (u->name, t, id);                                         //Pushes name into Name Tree
}

