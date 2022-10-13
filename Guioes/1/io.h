#include <stdio.h>
#include <string.h>
#include "obj.h"

void handle ();                                     //Function to handle input
Coms* sComs ();                                     //Function to initialize a commands list
void printDEQ(DEQ* DEQ, void(*printFunc)(void*));   // Prints Nodes ;