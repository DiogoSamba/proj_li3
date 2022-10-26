#include "drivers.h"
#define SIZEARRAY 1024

/*Driver
    id;name;birth_day;gender;car_class;license_plate;city;account_creation;account_status
    querrys
        id
        avaliação (Rides)
        genero (Árvore com ramo de array de Driver*) 
        data criação de conta

*/  

//--------Structs


struct driver
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
};

struct adrv                                                                     //Struct q define o array
{
    int size;
    int pos;
    Driver* array;                                                         
};

struct arr_d_adr                                                                //Array de endereços de Drivers
{
    int size;
    int pos;
    Driver** array;
};

struct gen_t                                                                    //Branch de género com array de endereços para elementos com determinado género
{
    struct arr_d_adr* male;
    struct arr_d_adr* female;
};

//--------Functions



void m_size_d_adr_arr (struct arr_d_adr* a)                                     //Duplica espaço no array de endereços de Drivers
{
    a->size<<= 1;
    a->array= realloc (a->array, a->size);
}

void push_d_adr (struct arr_d_adr* a, Driver* d_adr)                             //Recebe um array de adr e um adr e guarda o adr no array
{
    if (a->size== a->pos)
        m_size_d_adr_arr (a);
    a->array [a->pos++]= d_adr;   
}

struct arr_d_adr* i_arr_d_adr ()                                                //Inicia um array de adr de drivers
{
    struct arr_d_adr* a= malloc (sizeof (struct arr_d_adr));
    a->array= malloc (SIZEARRAY* sizeof (Driver*));
    a->size= SIZEARRAY;
    a->pos= 0;
    return a;
}

gender_t i_gender_t ()                                                          //Devolve Estrutura de ref com criterio gender
{
    gender_t g= malloc (sizeof (gender_t));
    g->female= i_arr_d_adr ();
    g->male= i_arr_d_adr ();
    return g;
}

void m_size (arr_driver a)                                                      //Aumenta size do array
{
    a->size<<= 1;
    a->array= realloc (a->array, a->size);
}

void push_gender (gender_t g, arr_driver a, int d_id)                           //Mete genero do driver no gender_t
{
    if (a->array[a->pos].gender== 0)                                                //Driver is a male
        push_d_adr (g->male, &a->array[a->pos]);
    else                                                                            //Driver is a female
        push_d_adr (g->female, &a->array[a->pos]);
}

arr_driver i_driver_l ()                                                        //Inicia o array de drivers com tamanho 1024
{
    arr_driver r= malloc (sizeof (arr_driver));
    r->size= SIZEARRAY;
    r->pos= 0;
    r->array= malloc (SIZEARRAY* sizeof (Driver));
    return r;
}

void push_driver (arr_driver a, gender_t g, Driver d, int d_id)                 //Adiciona elemento d ao array e às restantes estruturas de dados
{
    static int id;
    if (a->pos== a->size)
        m_size (a);                                                                 //Aumenta tamanho do array se chegar ao fim
    a->array[a->pos++]= d;                                                          //Atribui Driver em pos e incrementa a posição
    push_gender (g, a, d_id);                                                       //Atribui Ref de Driver na gender_t
}

Driver get_driver_id (arr_driver a, int n)                                         //Devolve Driver com id n
{
    return a->array[n];
}







