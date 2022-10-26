#include <string.h>
#include "users.h"
#include "io.h"

int main ()
{
    arr_driver arrD = i_driver_l();
    gender_t genD = i_gender_t();
    FILE * f_drivers = fopen("drivers.csv", "r");
    char * line = NULL;
    char 
    size_t len;
    getline(&line, &len, f_drivers);
    free(line);
    line = NULL;
    getline(&line, &len, f_drivers);
    strtok(line, ';');

}