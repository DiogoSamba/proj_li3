#include <stdlib.h>
typedef struct adrv* arr_driver;                                                //Struct q define o tamanho do array
typedef struct gen_t* gender_t; 
typedef struct driver Driver;

arr_driver i_driver_l ();                                                       //Devolve um array de elementos do tipo driver
void push_driver (arr_driver a, gender_t g, Driver d, int d_id);                //Adiciona elemento d ao array e às restantes estruturas de dados
Driver get_driver_id (arr_driver a, int n);                                     //Devolve Driver com id n
gender_t i_gender_t ();                                                         //Devolve Estrutura de ref com criterio gender