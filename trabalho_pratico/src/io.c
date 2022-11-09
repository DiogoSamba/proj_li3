#include "io.h"

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

static void print_output_q1d (Driver * d)
{
    int idade = calcular_idade(d->birth_date);
    printf("%s;%c;%d\n", d->name, d->gender, idade); 
}

//nuno.f.faria@inesctec.pt

static void q1 (Array_Driver arr_d)
{
    char id[30];
    scanf("%29s", id);
    int n;
    Driver d;
    if (id[0] >= '0' && id[0] <= '9')
    {
        n = atoi(id);
        d = get_driver_id(arr_d, n-1);
        print_output_q1d(&d);
    }   
}



void In (Array_Driver arr_d)
{
    char c = getchar();
    switch (c)
    {
        case '1' : q1(arr_d); return;
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
