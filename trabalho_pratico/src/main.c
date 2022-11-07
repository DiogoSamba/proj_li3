#include <string.h>
#include "io.h"

int main ()
{
    arr_driver arrD = i_driver_l();
    gender_t genD = i_gender_t();
    FILE * f_drivers = fopen("drivers.csv", "r");
    char * lino = NULL;
    int id = 1, c;
    Driver res;
    size_t len;
    getline(&lino, &len, f_drivers);
    free(lino);
    lino = NULL;
    while ((c = fgetc(f_drivers)) != EOF)
    {
        res.name = calloc(1,30);
        getline(&lino, &len, f_drivers);
        sscanf(lino, "%d;%[^;];%d/%d/%d;%c;%c%[^;];%2s-%2s-%2s;%c%[^;];%d/%d/%d;%c", &res.id, res.name, &res.birth_date[0], &res.birth_date[1], &res.birth_date[2],
        &res.gender, &res.class, lino, &res.license_plate[0], &res.license_plate[2], &res.license_plate[4], &res.city, lino, 
        &res.acc_creat[0], &res.acc_creat[1], &res.acc_creat[2], &res.acc_stat);
        push_driver(arrD, res, res.id);
    }
    printf("ola");
    res = get_driver_id(arrD, 1000);
    printf("ola");
}