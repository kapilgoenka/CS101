//typedef char stackElement;
typedef int stackElement;
typedef struct stack* stack;

stack stackInit();
void stackDestroy(stack);
void push(stack,stackElement);
stackElement pop(stack);
int isFull(stack);
int isEmpty(stack);
stackElement peek(stack);

