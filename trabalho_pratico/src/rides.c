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
#include "users.h"
#define SMALL_A 10
#define ARRAYD 10000
#define ARRAYU 100000                                                     
#define ARRAYR 1000000
#define TARGETRANGE 2

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

typedef struct rate_driver
{
    int id;
    double rating;
}rate_driver;

typedef struct array_rate_driver
{
    int size;
    rate_driver* array;
}array_rate_driver;

//--------Functions--------

//--------Determinar data mais recente

static int determina_data_mrecente(int * data_stored, int * data_atual) 
{
    if(data_stored[2] == data_atual[2])
    {
        if (data_stored[1] == data_atual[1])
        {
            if(data_stored[0]<data_atual[0])
                return 1;
            else    
                return 0;
        }
        else
        {
            if(data_stored[1]<data_atual[1])
                return 1;
            else 
                return 0;
        }
    }
    else
    {
        if (data_stored[2]<data_atual[2])
            return 1;
        else
            return 0;
    }
}

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
    if (determina_data_mrecente(a_r_d->array[id].data_mrecente, r->data))
    {
        a_r_d->array[id].data_mrecente[0] = r->data[0];
        a_r_d->array[id].data_mrecente[1] = r->data[1];
        a_r_d->array[id].data_mrecente[2] = r->data[2];
    }
}

//--------Array_Ride_User

static void push_array_ride_user (array_ride_user* a_r_u, Ride* r, float preco_ride)
{
    int id = r->user_id;
    a_r_u->array[id].rides++;
    a_r_u->array[id].sum_score += r->score_u;
    a_r_u->array[id].cash += preco_ride + r->tip;
    a_r_u->array[id].sum_dist += r->dist;
    if (determina_data_mrecente(a_r_u->array[id].data_mrecente, r->data))
    {
        a_r_u->array[id].data_mrecente[0] = r->data[0];
        a_r_u->array[id].data_mrecente[1] = r->data[1];
        a_r_u->array[id].data_mrecente[2] = r->data[2];
    }    
}

//--------Array_Ride

static void more_array_ride (array_ride* a)                                     //Doubes the size of the Ride's Array
{
    a->size<<= 1;
    a->array= realloc (a->array, a->size* sizeof (Ride));
}

//--------Array_Rate_Driver

static void merge_sort (rate_driver* a, int size)                               //Aplica 
{
    if (size== 1)
        return;
    rate_driver ref= a[0];
    rate_driver maior[size];
    int j=0, k=0;
    for (int i= 1; i< size; i++)
    {
        if (a[i].id> ref.id)
            maior[j++]= a[i];
        else
            a[k++]= a[i];
    } 
    a[k++]= ref;
    for (int i= 0; i< j; i++)                                                       //Ordena o array segundos as chunks de 'menor' 'ref' e 'maior'.
    {
        a[i+k]= maior[i];
    }
    merge_sort (a, k);
    merge_sort (&a[k], j);
}

static void reduce_array_rate_driver (array_rate_driver* a, int n)              //Returns an array with the unordered top a, a is set between 'n'and 'TARGETRANGE*n'
{
    int i, j, refi= 0;                                                              //refi (reference index) Keeps the chosen reference index in case we need to choose another one (j>= n)
    rate_driver ref;
    while (a->size> TARGETRANGE*n)
    {
        array_rate_driver* new= malloc (sizeof (array_rate_driver));
        new->array= malloc (a->size* sizeof (rate_driver));
        new->size= a->size;
        for (i= refi; i< a->size; i++)
        {
            if (a->array[i].rating!= 0)
            {
                ref= a->array[i];                                                   //Reference by wich we compare the other members of the array. We choose a reference different that zero to eliminate the most elements possible out of the array
                refi= i+1;                                                          //refi takes the value of the chosen index +1
                i= a->size;                                                         //break the cycle
            }
        }
        for (i= 0, j= 0; i< a->size; i++)
        {
            if (a->array[i].rating> ref.rating)                                     //If a given driver's rating is higher than our reference value we assign it to the 'new' array
                new->array[j++]= a->array[i];                                       //
        }
        if (j>=n)                                                                   //Our selection must contain the top 'n' elements
        {
            free (a->array);                                                        //Frees 'old' array struct
            new->size= j;                                                           //Assignement of 'new' array struct to 'a'
            a=new;                                                                  //
            refi= 0;                                                                //Resets refi
        }
        else
        {
            free (new->array);                                                      //Frees useless array struct
            free (new);                                                             //
        }
    }    
}

static void ordena_datas (array_rate_driver* a,int n)
{

}

static int* order_array_rate_driver (array_rate_driver* a, int n)                       
{
    int* res= malloc (n* sizeof(int));
    merge_sort (a->array, a->size);                                             
    int i= 0, j= 0, k;
    for (i= 0; i< a->size-1; i++)
        if (a->array[i].rating!= a->array[i+1].rating)
            break;
    k= i;                                                                           //Variable k stores the members of the array that have the same classification so we can compare the dates
    if (!k)                                                                         //
        ordena_datas (a, k);
    for (i= a->size- n- 1; i< n; i++)
        res[j++]= a->array[i].id;
    return res;
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

Array_Rate_Driver init_array_rate_driver (array_ride_driver* a)
{
    array_rate_driver* ard= malloc (sizeof (array_rate_driver));
    ard->size= a->size;
    ard->array= malloc (ard->size* sizeof (rate_driver));
    for (int i= 0; i< ard->size; i++)
    {
        ard->array[i].id= i;                                                    //Important to assign this as we will swap some arguments of our array latter on
        if(!a->array[i].rides)
            ard->array[i].rating = 0.000;
        else    
            ard->array[i].rating= a->array[i].sum_score/ a->array[i].rides;         //Calculates the average score and assigns it to the rating var.
    }
    return ard;
}

int* top_rated_drivers (Array_Rate_Driver a, int n)                             //Returns an array of the top rated drivers from the best rating(index 0) to the worst (index n-1)
{
    int* res= malloc (n* sizeof (int));                                         //Result will be assigned here
    reduce_array_rate_driver (a, n);                                            //Reduces array in size
    res= order_array_rate_driver (a, n);                                        //Orders reduced array
    return res;                                                                 
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
    a->pos++;
}



