#include <stdlib.h>

typedef enum type                                   //Enum of possible data types for elements in a node
{
    Char,
    Short,
    Int,
    Long,
    Float,
} Type;

typedef struct node                                 //Definition of single node structure
{
    struct node* prev;
    void* data;
    Type t;
    struct node* next;
} Node;

typedef struct deq                                  //Struct defining the DEQ itself
{
    Node* bot;
    Node* top;
} DEQ;                                               //Double ended queue


typedef struct commands                             //Struct to define an array of commands meant for input
{
    char** list;                                    //Array of "strings" of size 5 to be interpreted
    int sz;                                         //Size of array
    int pos;                                        //Posiition referenced for writing next command. Also used to check if list hits max size
} Coms;

DEQ* create();                                       // Initiallizing DEQ with no elements ;
void push(DEQ* DEQ, void* data, Type t);             // adiciona data no fim da fila ;
void pushFront(DEQ* DEQ, void* data, Type t);        // Adds data to a new node at the front of the queue ;
Node* pop(DEQ* DEQ);                                 // Removes the node at the top of the queue and returns it; Return NULL if the queue is empty ;
void* popFront(DEQ* DEQ);                            // Removes the first node and returns it; Return NULL if the queue is empty ;
int size(DEQ* DEQ);                                  // Size fo queue ;
char isEmpty(DEQ* DEQ);                              // Checks if queue is empty; 1 for empty 0 for not empty ;
void reverse(DEQ* DEQ);                              // Reverse queue ;
void destroy(DEQ* DEQ);                              // Frees the memory associated with the DEQ ;