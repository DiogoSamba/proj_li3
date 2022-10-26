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


struct user
{
    char* user_n;
    char* name;
    char gender;
    int birth_date [3];
    int acc_creat [3];
    char pay_meth;                                                              //0 Cash 1 CCard 2 DCard
    char acc_status;
};

struct user_l
{
    struct user* list;
    int pos;
    int siz;
};

struct user_name_ref
{
    char* name;
    Driver* d_adr;
};

struct leter_l
{
    char leter;
    struct user_name_ref* unr;
    int sz;
    int pos;
};

struct name_tree
{
    struct leter_l* leter_list;
    int sz;
    int pos;
};

//--------Functions

struct user_l* i_user_l ()                                                      //Devolve array para guardar os users
{
    struct user_l* l= malloc (sizeof (struct user_l));
    l->list= malloc (100* sizeof (struct user));
    l->pos= 0;
    l->siz= 0;
    return l;
}

struct name_tree* i_name_tree ()
{
    struct name_tree* nt= malloc (sizeof (struct name_tree));
    nt->leter_list= malloc (10* sizeof (struct leter_l));
    
}

/* void push_user (User u; gender_t g )
{

} */

