#include "obj.h"

DEQ* create ()                                               // Initiallizing DEQ with no elements
{
    DEQ* deq= calloc (1, sizeof(DEQ));
    return deq;
}

void push( DEQ* DEQ, void* data, Type t)                    //Adds data to a new node at the end of the queue
{
    Node* new= calloc (sizeof (Node));
    new->data= data;                                            //New node refers data adress
    new->t= t;
    new->prev= DEQ->top;                                        //Refering top as the bottom of new
    DEQ->top->next= new;                                    
    DEQ->top= new;                                              //Refering new as the new top
}

void pushFront( DEQ* DEQ, void* data, Type t)               //Adds data to a new node at the front of the queue
{
    Node* new= calloc (sizeof (Node));
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

