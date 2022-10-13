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

char** initCompCom ()
{
    char* a [10];
    for (int i= 0; i<10; i++)
    {
        a[i]= calloc (5, sizeof (char));
    }
    a[0]= "c";
    a[1]= "pus";
    a[2]= "pusf";
    a[3]= "pop";
    a[4]= "popf";
    a[5]= "sz";
    a[6]= "ismt";
    a[7]= "rev";
    a[8]= "dest";
    a[9]= "prnt";
    return a;
}

void execCom (char* com, DEQ* d, char* a [])                    //Função auxiliar ao handle
{
    Node* n;
    Type t;
    void* data;
    if (strcmp ( com, a[0])== 0)
        d= create();
    else if (strcmp ( com, a[1])== 0)
    {
        printf ("What type of data do you intend to queue? (int, char, ...)\n");
        //Apanhar o tipo de dados
        //Interpretar dados segundo o tipo de dados
        push (d, data, t);
    }
    else if (strcmp ( com, a[2])== 0)
    {
        printf ("What type of data do you intend to queue? (int, char, ...)\n");
        //Apanhar o tipo de dados
        printf ("Enter data:\n");
        //Interpretar dados segundo o tipo de dados
        pushFront (d, data, t);
    }
    else if (strcmp ( com, a[3])== 0)
    {
        n= pop (d);
        //Apanhar o tipo para escrever
        printf ("Popped element of type \n");
    }
    else if (strcmp ( com, a[4])== 0)
    {
        n= popFront (d);
        //Apanhar o tipo para escrever
        printf ("Popped element of type \n");
    }
    else if (strcmp ( com, a[5])== 0)
        printf ("%i", size(d));
    else if (strcmp ( com, a[6])== 0)
        if (isEmpty)
            printf ("DEQ is Empty\n");
        else
            printf ("DEQ is not Empty\n");
    else if (strcmp ( com, a[7])== 0)
    {
        reverse (d);
        printf ("DEQ has been reversed.\n");
    }
    else if (strcmp ( com, a[8])== 0)
    {    
        destroy (d);
        printf ("DEQ has been destroyed.\n");
    }
    else if (strcmp ( com, a[9])== 0)
    {
        printf ("Full DEQ:\n");
        printDEQ (d);
    }
    for (int i= 0; i<10; i++)
    {
        free (a[i]);
    }
}

void handle ()                                      //Function to handle input
{
    char* in= malloc (BUFSIZ);
    fgets (in, BUFSIZ, stdin);                              //Gets input string
    char* s= strtok (in, " \n");
    Coms* c= initComs ();                                   //Command list
    while (s!= NULL)                                        //Takes input string and breaks it down into single commands to insert in the list
    {
        pushCom (s, c);
        s= strtok (NULL, " \n");
    }
    DEQ* d;
    for (int i= 0; i< c->pos; i++)                          //Goes through every command in the list
    {
        printf ("Comando #%i, %s:\n", i, c->list[i]);
        execCom (c->list[i], d, initCompCom ());                            //Executes the command at the i index of the array
    }
}

void printNode(Node* n)                                     //Prints a single Node
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

void printDEQ(DEQ* DEQ)                                     // Prints full DEQ ;
{
    Node* n= DEQ->bot;
    while (n->next!= 0)
    {
        printNode (n);
    }
}