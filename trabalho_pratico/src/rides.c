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

//--------Preço das viagens Driver

static float get_preco_ride(int id, Array_Driver a_d, int dist)
{
    Driver d = get_driver_id(a_d, id);
    float preco;
    switch (d.class)
    {
        case 'b':
            {
                preco = 3.25 + (0.62 * dist);
                return preco;
            }
        case 'g':
            {
                preco = 4.00 + (0.79 * dist);
                return preco;
            }
        case 'p':
            {
                preco = 5.20 + (0.94 * dist);
                return preco;
            }
        default:
                return 0.00;
    }
}

//--------Array_Ride_Driver

static void push_array_ride_driver (array_ride_driver* a_r_d, Ride* r, float preco_ride)
{
    int id = r->driver_id;
    a_r_d->array[id].rides++;
    a_r_d->array[id].sum_score += r->score_d; 
    a_r_d->array[id].cash += preco_ride + r->tip;
}

//--------Array_Ride_User

static void push_array_ride_user (array_ride_user* a_r_u, Ride* r, float preco_ride)
{
    int id = r->user_id;
    a_r_u->array[id].rides++;
    a_r_u->array[id].sum_score += r->score_u;
    a_r_u->array[id].cash += preco_ride + r->tip; 
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

Ride_User* get_ride_user (array_ride_user* a, int id)
{
    return &a->array[id];
}

void push_ride (array_ride* a, array_ride_driver* a_r_d, array_ride_user* a_r_u, Ride* r, Array_Driver a_d)                                          //Pushes given ride into the ride array
{
    if (a->pos== a->size)
        more_array_ride (a);
    a->array[a->pos]= *r;
    float preco_ride = get_preco_ride (r->driver_id, a_d, r->dist);
    push_array_ride_driver (a_r_d, r, preco_ride);
    push_array_ride_user (a_r_u, r, preco_ride);
    //a->pos++;
}



