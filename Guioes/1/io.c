#include "io.h"

Coms* initComs ()
{
    Coms* c= malloc (sizeof (Coms));
    c->list= malloc (5* sizeof (char**));
    c->sz= 5;
    for (int i= 0; i< 5; i++)
    {
        c->list[i]= malloc (5);                          //Sets memmory for 5 char, each refered in the list
    }
    c->pos= 0;
    return c;
}

void moreComs (Coms* c)                              //Doubles size of array of commands
{
    c->sz<<= 1;                                             //Sets size to double the current 1
    c->list= realloc (c->list, c->sz);                      //List of commands gets double the size
    while (c->pos!= c->sz)                          
    {
        c->list[c->pos]= malloc (5);                        //Sets memory to new refered strings
        c->pos++;
    }   
    c->pos>>= 1;                                            //Resets var used for cycle
}

void pushCom (char* str, Coms* c)
{
    if (c->pos== c->sz)                             //Checks for open space
        moreComs (c);
    strcpy (c->list[c->pos], str);                  //Copies the string
    c->pos++;                                       //Sets pos to next index of the list
}

void handle ()                                      //Function to handle input
{
    char* in= malloc (BUFSIZ);
    fgets (in, BUFSIZ, stdin);                              //Gets input string
    char* i= strtok (in, " \n");
    Coms* c= initComs ();                                   //Command list
    while (i!= NULL)                                        //Takes input string and breaks it down into single commands to insert in the list
    {
        pushCom (i, c);
        i= strtok (NULL, " \n");
    }
}

void printNode(Node* n)
{
    switch (n->t)
    {
        case Char:
            printf ("%c\t", *(char*) n->data);
            return;
        case Short:
            printf ("%hi\t", *(short*) n->data);
            return;
        case Int:
            printf ("%i\t", *(int*) n->data);
            return;
        case Long:
            printf ("%ld\t", *(long*) n->data);
            return;
        case Float:
            printf ("%4f\t", *(float*) n->data);
            return;
    }
}

void printDEQ(DEQ* DEQ, void(*printFunc)(void*))          // Prints Nodes ;
{
    Node* n= DEQ->bot;
    while (n->next!= 0)
    {
        printNode (n);
    }
}