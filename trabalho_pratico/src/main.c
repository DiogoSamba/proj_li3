#include <string.h>
#include <stdio.h>
#include "io.h"
#include "drivers.h"
#include "users.h"
#include "rides.h"


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
    while (getline (&lino, &len, f_drivers) != -1)
    {
        d.name = calloc (1,30);
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
            u->pay_meth = 0;
            return;
        }
    case 'r':
        {
            u->pay_meth = 1;
            return;
        }
    case 'e':
        {
            u->pay_meth = 2;
            return;
        }
    default:
        return;
    }
}

void set_database_user (Array_User a_u, Node_Array n_a)      
{
    FILE * f_users = fopen ("../Dataset/users.csv", "r");
    char * lino = NULL;
    User d;
    size_t len;
    static char determinar [3];
    getline (&lino, &len, f_users);
    free (lino);
    lino = NULL;
    while (getline (&lino, &len, f_users) != -1)
    {
        d.name = calloc (1,30);
        d.user_n = calloc (1,30);
        sscanf (lino, "%[^;];%[^;];%c;%d/%d/%d;%d/%d/%d;%2s%[^;];%c", d.user_n, d.name, &d.gender, &d.birth_date[0], &d.birth_date[1], &d.birth_date[2],
        &d.acc_creat[0], &d.acc_creat[1], &d.acc_creat[2], determinar, lino, &d.acc_status);
        determinar_pay_meth (determinar[1], &d);
        push_user(d, a_u, n_a);
    }
}

void set_database_rides (Array_Ride a_r, Node_Array n_a, Array_Driver a_d, Array_Ride_Driver a_r_d, Array_Ride_User a_r_u)      
{
    FILE * f_rides = fopen ("../Dataset/rides.csv", "r");
    char * lino = NULL, * determinar = calloc(1,30);
    Ride d;
    int idzito;
    size_t len;
    getline (&lino, &len, f_rides);
    free (lino);
    lino = NULL;
    while (getline (&lino, &len, f_rides) != -1)
    {
        d.com = calloc (1,100);
        sscanf (lino, "%d;%d/%d/%d;%d;%[^;];%c%[^;];%d;%d;%d;%f;%[^\n]", &idzito, &d.data[0], &d.data[1], &d.data[2], &d.driver_id, determinar, &d.city, lino, &d.dist, &d.score_u,
        &d.score_d, &d.tip, d.com);
        d.user_id = get_user_id(n_a, determinar);
        //push_ride(a_r, a_r_d, a_r_u, &d, a_d);
        //printf("ola");
    }
}

void main ()
{
    Array_Driver a_d = init_Array_Driver ();
    Array_User a_u = init_array_user ();
    Node_Array n_a = init_node_array ();
    Array_Ride a_r = init_array_ride ();
    Array_Ride_Driver a_r_d = init_array_ride_driver();
    Array_Ride_User a_r_u = init_array_ride_user();
    set_database_driver (a_d);
    set_database_user (a_u, n_a);
    set_database_rides (a_r, n_a, a_d, a_r_d, a_r_u);
    In (a_d, a_r_d, a_r_u);
}

