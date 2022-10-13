#include <stdio.h>
#include <string.h>
#include "obj.h"

/*
    Comandos:
        c           DEQ* create();                                       // Initiallizing DEQ with no elements ;
        pus         void push(DEQ* DEQ, void* data, Type t);             // adiciona data no fim da fila ;
        pusf        void pushFront(DEQ* DEQ, void* data, Type t);        // Adds data to a new node at the front of the queue ;
        pop         Node* pop(DEQ* DEQ);                                 // Removes the node at the top of the queue and returns it; Return NULL if the queue is empty ;
        popf        void*   popFront(DEQ* DEQ);                            // Removes the first node and returns it; Return NULL if the queue is empty ;
        sz          int size(DEQ* DEQ);                                  // Size fo queue ;
        ismt        char isEmpty(DEQ* DEQ);                              // Checks if queue is empty; 1 for empty 0 for not empty ;
        rev         void reverse(DEQ* DEQ);                              // Reverse queue ;
        dest        void destroy(DEQ* DEQ);                              // Frees the memory associated with the DEQ ;
        prnt        void printDEQ(DEQ* DEQ, void(*printFunc)(void*));   // Prints Nodes ;
*/

void handle ();                                     //Function to handle input
Coms* sComs ();                                     //Function to initialize a commands list
void printDEQ(DEQ* DEQ);                            // Prints Nodes ;