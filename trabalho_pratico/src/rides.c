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

typedef struct ride_driver
{
    int numb_score;
    int sum_score;
    int rides;
    int cash;
}ride_driver;

typedef struct array_ride_driver
{
    ride_driver* array;
    int size;
}array_ride_driver;

typedef struct ride_user
{
    int numb_score;
    int sum_score;
    int rides;
    int cash;
}ride_user;

typedef struct array_ride_user
{
    ride_user* array;
    int size;
}array_ride_user;

typedef struct array_ride
{
    int pos;
    int size;
    Ride* array;
}array_ride;


//--------Functions--------

//--------Array_Ride

static void more_array_ride (array_ride* a)                                     //Doubes the size of the Ride's Array
{
    a->size<<= 1;
    a->array= realloc (a->array, a->size* sizeof (Ride));
}

//--------API

array_ride_driver* init_array_ride_driver ()
{
    array_ride_driver* a= malloc (sizeof (array_ride_driver));
    a->array= malloc (ARRAYD* sizeof (ride_driver));
    a->size= ARRAYD;
}

array_ride_user* init_array_ride_user ()
{
    array_ride_driver* a= malloc (sizeof (array_ride_driver));
    a->array= malloc (ARRAYU* sizeof (ride_driver));
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

void push_ride (array_ride* a,array_ride_driver* a_r_d, array_ride_user* a_r_u, Ride r)                                          //Pushes given ride into the ride array
{
    if (a->pos== a->size)
        more_array_ride (a);
    a->array[a->pos++]= r;
}

