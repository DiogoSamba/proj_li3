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
    int id = 1, c;
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

/* void set_database_user (Array_User a_u)      FIXME
{
    FILE * f_drivers = fopen ("../Dataset/users.csv", "r");
    char * lino = NULL;
    int id = 1, c;
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
 */
int main ()
{
    Array_Driver a_d = init_Array_Driver ();
    set_database_driver (a_d);
    printf ("ola");
    printf ("ola");
}

