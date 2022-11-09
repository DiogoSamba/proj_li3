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

typedef struct ride_a
{
    int date[3];
    int driver;
    int user;
    char city;
    int distance;
    int score_u;
    int score_d;
    int tip;
    char* com;
}ride_a;