#include "io.h"

void q1 ()
{
    char id[30];
    scanf("%29s", id);
    int n;
    if (id[0] >= '0' && id[0] <= '9')
    {
        n = atoi(id);
        
    }   
}






void In ()
{
    char c = getchar();
    switch (c)
    {
        case '1' : q1(); return;
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
