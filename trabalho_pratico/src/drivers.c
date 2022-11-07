#include "drivers.h"
#define SIZEARRAY 100

/*Driver
    id;name;birth_day;gender;car_class;license_plate;city;account_creation;account_status
    querrys
        id
        avaliação (Rides)
        genero (Árvore com ramo de array de Driver*) 
        data criação de conta

*/

//--------Structs--------

typedef struct adrv                                                             //Struct q define o array
{
    int size;
    int pos;
    Driver* array;                                                         
}array_driver;

//--------Functions--------

//--------Driver Array

static void more_array_driver (array_driver* a)                                 //Sets array driver to double it's size
{
    a->size<<= 1;
    a->array= realloc(a->array, a->size* sizeof (Driver));
}

//--------API

array_driver* init_Array_Driver ()                                              //Returns the address to a driver array type of variable
{
    array_driver* a= malloc (sizeof (array_driver));
    a->pos= 0;
    a->size= SIZEARRAY;
    a->array= malloc (SIZEARRAY* sizeof (Driver));
    return a;
}

    Driver get_driver_id (array_driver* a, int id)                              //Input the driver's array and the drivers id, returns the driver
    {
        return a->array[id];
    }

void push_driver_Array_Driver (array_driver* a, Driver d)                       //Push a given Driver element into the driver's array
{
    if (a->size== a->pos)
        more_array_driver (a);
    a->array[a->pos++]= d;
}