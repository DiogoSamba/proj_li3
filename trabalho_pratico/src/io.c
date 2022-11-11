#include "io.h"

static void print_output_q1d (Driver * d, Ride_Driver * r_d)
{
    int idade = calcular_idade(d->birth_date); 
    double avaliacao_media = r_d->sum_score / r_d->rides;
    printf("%s;%c;%d;%.3lf;%d\n", d->name, d->gender, idade, avaliacao_media, r_d->rides); 
}

static void q1 (Array_Driver arr_d, Array_Ride_Driver a_r_d, Array_Ride_User a_r_u)
{
    char id[30];
    scanf("%29s", id);
    int n;
    if (id[0] >= '0' && id[0] <= '9')
    {
        n = atoi(id);
        Ride_Driver * r_d = get_ride_driver(a_r_d, n);
        Driver d = get_driver_id(arr_d, n);
        print_output_q1d(&d, r_d);
    }   
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

void In (Array_Driver arr_d, Array_Ride_Driver a_r_d, Array_Ride_User a_r_u)
{
    char c = getchar();
    switch (c)
    {
        case '1' : q1(arr_d, a_r_d, a_r_u); return;
        /*
        case '2' : q2(); return;
        case '3' : q3(); return;
        case '4' : q4(); return;
        case '5' : q5(); return;
        case '6' : q6(); return;
        case '7' : q7(); return;
        case '8' : q8(); return;
        case '9' : q9(); return; */
        default: return;
    }
}
