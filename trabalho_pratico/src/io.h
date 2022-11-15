#ifndef IO
#define IO
#include <stdio.h>
#include "users.h"
#include "drivers.h"
#include "rides.h"
#include "defines.h"

int calcular_idade (int * idadeX);
void In (Array_Driver arr_d, Array_User arr_u, Array_Ride_Driver a_r_d, Array_Ride_User a_r_u, Node_Array n_a, Array_Rate_Driver a_rate_d);                                                                     //Handles Input
#endif