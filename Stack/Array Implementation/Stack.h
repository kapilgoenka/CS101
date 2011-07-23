//typedef char StackElement;
typedef int StackElement;
typedef struct stack* stack;

stack stackInit();
void stackDestroy(stack);
void push(stack,StackElement);
StackElement pop(stack);
int isFull(stack);
int isEmpty(stack);
StackElement peek(stack);

