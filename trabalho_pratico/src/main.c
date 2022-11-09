#include <string.h>
#include <stdio.h>
//#include "io.h"
#include "drivers.h"
#include "users.h"
//#include "rides.h"

void set_database_driver (Array_Driver a_d)
{
    FILE * f_drivers = fopen ("../Dataset/drivers.csv", "r");
    char * lino = NULL;
    int c;
    Driver d;
    size_t len;
    getline (&lino, &len, f_drivers);
    free (lino);
    lino = NULL;
    while ((c = fgetc(f_drivers)) != EOF)
    {
        d.name = calloc (1,30);
        getline (&lino, &len, f_drivers);
        sscanf (lino, "%d;%[^;];%d/%d/%d;%c;%c%[^;];%2s-%2s-%2s;%c%[^;];%d/%d/%d;%c", &d.id, d.name, &d.birth_date[0], &d.birth_date[1], &d.birth_date[2],
        &d.gender, &d.class, lino, &d.license_plate[0], &d.license_plate[2], &d.license_plate[4], &d.city, lino, 
        &d.acc_creat[0], &d.acc_creat[1], &d.acc_creat[2], &d.acc_stat);
        push_driver_Array_Driver (a_d, d);
    }
}

void determinar_pay_meth (char pay_meth, User * u)
{
    switch (pay_meth)
    {
    case 'a':
        {
            u->pay_meth = '0';
            return;
        }
    case 'r':
        {
            u->pay_meth = '1';
            return;
        }
    case 'e':
        {
            u->pay_meth = '2';
            return;
        }
    default:
        return;
    }
}

void set_database_user (Array_User a_u)      
{
    FILE * f_drivers = fopen ("../Dataset/users.csv", "r");
    char * lino = NULL;
    int id = 1, c;
    Node_Array n_a =init_node_array ();
    User d;
    size_t len;
    getline (&lino, &len, f_drivers);
    free (lino);
    lino = NULL;
    while ((c = fgetc(f_drivers)) != EOF)
    {
        d.name = calloc (1,30);
        d.user_n = calloc (1,30);
        char determinar [3];
        getline (&lino, &len, f_drivers);
        sscanf (lino, "%[^;];%[^;];%c;%d/%d/%d;%d/%d/%d;%2s%[^;];%c", d.user_n, d.name, &d.gender, &d.birth_date[0], &d.birth_date[1], &d.birth_date[2],
        &d.acc_creat[0], &d.acc_creat[1], &d.acc_creat[2], determinar, lino, &d.acc_status);
        determinar_pay_meth (determinar[1], &d);
        push_user(d, a_u, n_a);
    }
}

int main ()
{
    Array_Driver a_d = init_Array_Driver ();
    Array_User a_u = init_array_user ();
    set_database_driver (a_d);
    set_database_user (a_u);
    printf ("ola");
    Driver manuel = get_driver_id(a_d, 9998);
    printf ("ola");
}

