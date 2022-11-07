#ifndef USERS
#define USERS

typedef struct user
{
    char* user_n;
    char* name;
    char gender;
    int birth_date [3];
    int acc_creat [3];
    char pay_meth;                                                              //0 Cash 1 CCard 2 DCard
    char acc_status;
}User;
typedef struct a_ussr* Array_User;
typedef struct name_tree* Name_Tree;

Name_Tree i_name_tree ();                                                //Devolve uma name tree
array_user* i_array_user ();                                             //Creates array of users. Each user is given an id corresponding to its index in this array
a_name_id* i_unr_a ();                                                   //Creates list of name-userID pairs

void push_user (User* u/* , gender_t g */, array_user* a, Name_T* t, int id);  //Pushes User
void push_name (char* name, Name_T* t, int id);                          //Pushes a name into the name search struct and refers it's corresponding user
void push_letter_name_t (Name_T* t, char* name);                         //Creates branch for the given letter
#endif