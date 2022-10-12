typedef enum tipo
{
    Char,
    Short,
    Int,
    Long,
    Float,
} Type;

typedef struct node
{
    struct node* prev;
    void* data;
    Type t;
    struct node* next;
} Node;

typedef struct deq
{
    Node* bot;
    Node* top;
} DEQ;                                               //Double ended queue

DEQ* create();                                       // Initiallizing DEQ with no elements
void push(DEQ* DEQ, void* data, Type t);             // adiciona data no fim da fila;
void pushFront(DEQ* DEQ, void* data, Type t);        // Adds data to a new node at the front of the queue
void* pop(DEQ* DEQ);                                 // Removes the node at the top of the queue and returns it; Return NULL if the queue is empty
void* popFront(DEQ* DEQ);                            // Removes the first node and returns it; Return NULL if the queue is empty ;
int size(DEQ* DEQ);                                  // retorna o número de elementos da fila;
char isEmpty(DEQ* DEQ);                              // indica se a fila está vazia; 3
void reverse(DEQ* DEQ);                              // inverte a ordem dos elementos da fila;
void printDEQ(DEQ* DEQ, void(*printFunc)(void*));    // imprime os elementos da fila com o auxilio da função printFunc ;
void destroy(DEQ* DEQ);                              // liberta a memória associada à DEQ 