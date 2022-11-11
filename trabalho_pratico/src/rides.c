/*Rides
    id;date;driver;user;city;distance;score_user;score_driver;tip;comment
    querrys
        cidade
        preço
        gorjeta
        data ocurrencia
*/

/* Parametros: 
    Cidade
    Preço
    Data
    City is a Driver caracteristic.
    Avaliação -> Condutor
    Flag Gorjeta
*/   
#include "rides.h"
#define SMALL_A 10
#define ARRAYD 10000
#define ARRAYU 100000                                                     
#define ARRAYR 1000000

//--------Structs--------

typedef struct array_ride_driver
{
    Ride_Driver* array;
    int size;
}array_ride_driver;

typedef struct array_ride_user
{
    Ride_User* array;
    int size;
}array_ride_user;

typedef struct array_ride
{
    int pos;
    int size;
    Ride* array;
}array_ride;


//--------Functions--------


//--------Array_Ride_Driver

void push_array_ride_driver (array_ride_driver* a_r_d, Ride* r)
{
    a_r_d->array[r->driver_id].rides++;
    a_r_d->array[r->driver_id].sum_score+= r->score_d; 
    //a_r_d->array[r->driver_id].cash                                           É preciso calcular o valor auferido com cada viagem
}

//--------Array_Ride_User

void push_array_ride_user (array_ride_user* a_r_d, Ride* r)
{

}

//--------Array_Ride

static void more_array_ride (array_ride* a)                                     //Doubes the size of the Ride's Array
{
    a->size<<= 1;
    a->array= realloc (a->array, a->size* sizeof (Ride));
}

//--------API

array_ride_driver* init_array_ride_driver ()                                    //Returns a ride_driver array
{
    array_ride_driver* a= malloc (sizeof (array_ride_driver));
    a->array= malloc (ARRAYD* sizeof (Ride_Driver));
    a->size= ARRAYD;
}

array_ride_user* init_array_ride_user ()                                        //Returns a ride_user array
{
    array_ride_driver* a= malloc (sizeof (array_ride_driver));
    a->array= malloc (ARRAYU* sizeof (Ride_User));
    a->size= ARRAYU;
}

array_ride* init_array_ride ()                                                  //Returns a ride array
{
    array_ride* a= malloc (sizeof (array_ride));
    a->pos= 0;
    a->size= ARRAYR;
    a->array= malloc (ARRAYR* sizeof (Ride));
    return a;
}

Ride_Driver* get_ride_driver (array_ride_driver* a, int id)
{
    return &a->array[id];
}

Ride_User* get_ride_driver (array_ride_user* a, int id)
{
    return &a->array[id];
}

void push_ride (array_ride* a, array_ride_driver* a_r_d, array_ride_user* a_r_u, Ride* r)                                          //Pushes given ride into the ride array
{
    if (a->pos== a->size)
        more_array_ride (a);
    a->array[a->pos]= *r;
    push_ride_driver (a_r_d, r);
    push_ride_user (a_r_u, r);
    //a->pos++;
}



