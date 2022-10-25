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

typedef struct user_l
{
    User* list;
    int pos;
    int siz;
}User_l ;

struct user_name_ref
{
    char* name;
    Driver* d_adr;
};

typedef struct leter_l
{
    char leter;
    struct user_name_ref* unr;
    int sz;
    int pos;
}Letter_l;

typedef struct name_tree
{
    Letter_l* leter_list;
    int sz;
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
    t->leter_list= malloc (10* sizeof (Letter_l));
    t->sz= 10;
    return t;
}

void push_n_l (Letter_l* l,char* name, int id)
{
    if (l->pos== l->sz)                                                  //Redimenciona o array se ultrapassar o tamanho definido
        m_size_n_l(l);
    
}

void push_name (char* name, Name_T* t, int id)                           //Pushes a name into the name search truct and refers it's corresponding user
{
    Letter_l* l;
    for (int i= 0; i< t->sz; i++)
    {
        if (t->leter_list[i].leter== name[0])                            //Finds the letter, refers it and leaves the cycle.
            l= &t->leter_list[i]; i= t->sz;
    }
    push_n_l (l, name, id);                                                         //Pushes given name into list of elements of same starting letter 
}

/* void push_user (User u; gender_t g)
{

} */

