#ifndef DRIVERS
#define DRIVERS
#include <stdlib.h>

typedef struct driver
{
    int id;
    char* name;
    int birth_date[3];
    char gender;                                                                //0 Male 1 Female
    char class;
    char license_plate[7];
    char city;
    int acc_creat[3];
    char acc_stat;
}Driver;
typedef struct adrv* Array_Driver;

Array_Driver init_Array_Driver ();                                                                  //Returns the address to a driver array type of variable
Driver get_driver_id (Array_Driver a, int id);                                                      //Input the driver's array and the drivers id, returns the driver
void push_driver_Array_Driver (Array_Driver a, Driver d);                                             //Push a given Driver element into the driver's array
#endif