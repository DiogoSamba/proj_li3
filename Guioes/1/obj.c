#include "obj.h"

DEQ* create ()                                               // Initiallizing DEQ with no elements
{
    DEQ* deq= calloc (1, sizeof(DEQ));
    return deq;
}

void push( DEQ* DEQ, void* data, Type t)                    //Adds data to a new node at the end of the queue
{
    Node* new= calloc (1, sizeof (Node));
    new->data= data;                                            //New node refers data adress
    new->t= t;
    new->prev= DEQ->top;                                        //Refering top as the bottom of new
    DEQ->top->next= new;                                    
    DEQ->top= new;                                              //Refering new as the new top
}

void pushFront( DEQ* DEQ, void* data, Type t)               //Adds data to a new node at the front of the queue
{
    Node* new= calloc (1, sizeof (Node));
    new->data= data;
    new->t= t;
    new->next= DEQ->bot;
    DEQ->bot->prev= new;
    DEQ->bot= new;
}

Node* pop(DEQ* DEQ)                                         // Removes the node at the top of the queue and returns it; Return NULL if the queue is empty
{
    if (DEQ->bot== 0)
        return 0;
    else
    {
        Node* tnode= DEQ->top;                                  // Stores top node's address
        DEQ->top= DEQ->top->prev;                               // Sets the queue top as the 2nd node from the top
        DEQ->top->next= 0;                                      // Sets the new top's next node to NULL
        return tnode;
    }
}

void* popFront(DEQ* DEQ)                                   // Removes the first node and returns it; Return NULL if the queue is empty ;
{
    if (DEQ->bot== 0)
        return 0;
    else
    {
        Node* bnode= DEQ->bot;                                  // Stores bot node's address
        DEQ->bot= DEQ->bot->next;                               // Sets the queue top as the 2nd node from the bot
        DEQ->bot->prev= 0;                                      // Sets the new bot's prev node to NULL
        return bnode;
    }
}

int size(DEQ* DEQ)                                        // Size of queue
{
    int i= 0;
    Node* n= DEQ->bot;
    while (n->next!= 0)
    {
        n= n->next;
        i++;
    }
    return i;
}

char isEmpty(DEQ* DEQ)                                  // Checks if queue is empty; 1 for empty 0 for not empty
{
    if (DEQ->bot== 0)
        return 1;
    return 0;
}

void reverse(DEQ* DEQ)                                  // Reverse queue;
{
    Node* n= DEQ->bot, aux;
    
    DEQ->top= n;
    while (n->next!= 0)                                     // Swap without the use of aux mem
    {
        n->prev+= (long) n->next;
        n->next-= (long) n->prev;
        n->prev-= (long) n->next;
    } 
}

void printNode(Node* n)
{
    switch (n->t)
    {
        case Char:
            putchar (n->data); putchar ("\t");
            return;
        case Short:
            printf ("%hi\t", n->data);
            return;
        case Int:
            printf ("%i\t", n->data);
            return;
        case Long:
            printf ("%ld\t", n->data);
            return;
        case Float:
            printf ("%4f\t"), n->data;
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

void destroy(DEQ* DEQ)                                    // Frees the memory associated with the DEQ ;
{
    Node* n= DEQ->bot;
    DEQ->bot= 0; DEQ->top= 0;
    while (n->next!= 0)
    {
        free (n->data);                                         //Frees data refered in node n
        n= n->next;                                             //Refers next node
        free (n->prev);                                         //Frees prev node
    }
}