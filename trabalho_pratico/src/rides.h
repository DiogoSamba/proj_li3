#ifndef RIDES
#define RIDES
#include "defines.h"
#include "drivers.h"
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

typedef struct ride_driver
{
    int sum_score;
    int rides;
    float cash;
    int data_mrecente [3];
}Ride_Driver;

typedef struct ride_user
{
    int sum_score;
    int rides;
    float cash;
    int data_mrecente [3];
    int sum_dist;
}Ride_User;

typedef struct array_ride_driver* Array_Ride_Driver;
typedef struct array_ride_user* Array_Ride_User;
//typedef struct array_ride_user* Array_Dist_User;
typedef struct array_ride* Array_Ride;
typedef struct array_rate_driver* Array_Rate_Driver;


Array_Ride init_array_ride ();
Array_Ride_Driver init_array_ride_driver ();                                    //Returns a ride_driver array
Array_Ride_User init_array_ride_user ();                                        //Returns a ride_user array
Array_Rate_Driver init_array_rate_driver (Array_Ride_Driver a_r_d);
void push_ride (Array_Ride a, Array_Ride_Driver a_r_d, Array_Ride_User a_r_u, Ride* r, Array_Driver a_d);
Ride_Driver* get_ride_driver (Array_Ride_Driver a, int id);
Ride_User* get_ride_user (Array_Ride_User a, int id);
int* top_rated_drivers (Array_Rate_Driver a, int n);                            //Returns an array of the top rated drivers from the best rating(index 0) to the worst (index n-1)
//int* most_dist_users (Array_Dist_User a, int d);

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