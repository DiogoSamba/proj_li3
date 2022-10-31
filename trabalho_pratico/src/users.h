#include "drivers.h"

typedef struct user User;

Name_T* i_name_tree ();                                                  //Devolve uma name tree
array_user* i_array_user ();                                             //Creates array of users. Each user is given an id corresponding to its index in this array
a_name_id* i_unr_a ();                                                   //Creates list of name-userID pairs
void push_user (User* u, gender_t g, array_user* a, Name_T* t, int id);  //Pushes User
void push_name (char* name, Name_T* t, int id);                          //Pushes a name into the name search struct and refers it's corresponding user
void push_letter_name_t (Name_T* t, char* name);                         //Creates branch for the given letter
