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


//--------Structs--------

typedef struct array_ride_driver
{
    int numb_score;
    int sum_score;
    int viagens;
    int recebido;
}
array_ride_driver;

typedef struct array_ride_user
{
    int numb_score;
    int sum_score;
    int viagens;
    int pago;
}
array_ride_user;

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
    a->array= realloc (a->size* sizeof (Ride));
}

//--------API



array_ride* init_array_ride ()                                                  //Returns a ride array
{
    array_ride* a= malloc (sizeof (array_ride));
    a->pos= 0;
    a->size= SMALL_A;
    a->array= malloc (SMALL_A* sizeof (Ride));
    return a;
}

void push_ride (array_ride* a, Ride r)                                          //Pushes given ride into the ride array
{
    if (a->pos== a->size)
        more_array_ride (a);
    a->array[a->pos++]= r;
}

