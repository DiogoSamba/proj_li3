#include "io.h"


//--------Functions--------


static void print_output_q1d (Driver * d, Ride_Driver * r_d)
{
    int idade = calcular_idade(d->birth_date); 
    float avaliacao_media;
    FILE * end_file = fopen("./Resultados/q1.txt", "w");
    if (!r_d->rides)
        avaliacao_media = 0.000;
    else
        avaliacao_media = ((float)r_d->sum_score) / ((float)r_d->rides);
    fprintf(end_file, "%s;%c;%d;%.3f;%d;%.3f\n", d->name, d->gender, idade, avaliacao_media, r_d->rides, r_d->cash); 
    fclose(end_file);
}

static void print_output_q1u (User * u, Ride_User * r_u)
{
    int idade = calcular_idade(u->birth_date);
    float avaliacao_media;
    FILE * end_file = fopen("./Resultados/q1.txt", "w");
    if(!r_u->rides)
        avaliacao_media = 0.000;
    else
        avaliacao_media = ((float)r_u->sum_score) / ((float)r_u->rides);
    fprintf(end_file, "%s;%c;%d;%.3f;%d;%.3f\n", u->name, u->gender, idade, avaliacao_media, r_u->rides, r_u->cash);
    fclose(end_file);
}

static void q1 (Array_Driver arr_d, Array_User arr_u, Array_Ride_Driver a_r_d, Array_Ride_User a_r_u, Node_Array n_a)
{
    char id[30];
    scanf("%29s", id);
    int n;
    if (id[0] >= '0' && id[0] <= '9')
    {
        n = atoi(id);
        Ride_Driver * r_d = get_ride_driver(a_r_d, n-1);
        Driver d = get_driver_id(arr_d, n-1);
        print_output_q1d(&d, r_d);
    }
    else
    {
        n = get_user_id(n_a, id);
        Ride_User * r_u= get_ride_user(a_r_u, n);
        User u = get_user(n, arr_u);
        print_output_q1u(&u, r_u);
    }
}

static void print_output_q2 (int * array_top_d, Array_Driver a_d, int n, Array_Ride_Driver a_r_d)
{
    int i, id;
    Driver xpto;
    float avaliacao_media;
    FILE * end_file = fopen("./Resultados/q2.txt", "w");
    for(i = 0; i < n; i++)
    {
        id = array_top_d[i];
        xpto = get_driver_id(a_d, id-1);
        Ride_Driver * r_d = get_ride_driver(a_r_d, id);
        if (!r_d->rides)
            avaliacao_media = 0.000;
        else
            avaliacao_media = ((float)r_d->sum_score) / ((float)r_d->rides);
        fprintf(end_file, "%d;%s;%.3f\n",id, xpto.name, avaliacao_media);
    }
    fclose(end_file);
}


static void q2 (Array_Rate_Driver a_rate_d, Array_Driver a_d, Array_Ride_Driver a_r_d)
{
    char id [6];
    scanf("%5s", id);
    int n = atoi(id);
    int * array_top_d = top_rated_drivers(a_rate_d, n);
    print_output_q2(array_top_d, a_d, n, a_r_d);
}


static void q3()
{
    char id [6];
    scanf("%5s", id);
    int n = atoi(id);
}

//--------API


int calcular_idade (int * idadeX)
{
    int ano = IDADE_ANO_STD - idadeX[2];
    if (IDADE_MES_STD<idadeX[1])
        return ano-1;
    else
        if(IDADE_DIA_STD<idadeX[0])
            return ano-1;
        else
            return ano;
}

void In (Array_Driver arr_d, Array_User arr_u, Array_Ride_Driver a_r_d, Array_Ride_User a_r_u, Node_Array n_a, Array_Rate_Driver a_rate_d)
{
    char c = getchar();
    switch (c)
    {
        case '1' : q1(arr_d, arr_u, a_r_d, a_r_u, n_a); return;
        case '2' : q2(a_rate_d, arr_d, a_r_d); return;
        case '3' : q3(); return;
        /*
        case '4' : q4(); return;
        case '5' : q5(); return;
        case '6' : q6(); return;
        case '7' : q7(); return;
        case '8' : q8(); return;
        case '9' : q9(); return; */
        default: return;
    }
}
