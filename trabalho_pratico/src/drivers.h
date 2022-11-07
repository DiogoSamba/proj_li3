#ifndef __drivers_h
#define __drivers_h
#include <stdlib.h>
typedef struct adrv* arr_driver;                                                //Struct q define o tamanho do array
typedef struct gen_t* gender_t; 

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
//typedef struct driver Driver;

arr_driver i_driver_l ();                                                       //Devolve um array de elementos do tipo driver
void push_driver (arr_driver a, /* gender_t* t, */ Driver d, int d_id);                            //Adiciona elemento d ao array e às restantes estruturas de dados
Driver get_driver_id (arr_driver a, int n);                                     //Devolve Driver com id n
gender_t i_gender_t ();                                                         //Devolve Estrutura de ref com criterio gender

#endif