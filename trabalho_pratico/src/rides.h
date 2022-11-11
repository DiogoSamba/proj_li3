#ifndef RIDES
#define RIDES
#include "defines.h"
#include <stdlib.h>

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

typedef struct ride
{
    int data [3];
    int driver_id;
    int user_id;
    char city;
    int dist;
    int score_u;
    int score_d;
    float tip;
    char* com;
}Ride;

typedef struct array_ride_driver* Array_Ride_Driver;
typedef struct array_ride_user* Array_Ride_User;
typedef struct array_ride* Array_Ride;

Array_Ride init_array_ride ();
void push_ride (Array_Ride a, Array_Ride_Driver a_r_d, Array_Ride_User a_r_u, Ride r);

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
#endif