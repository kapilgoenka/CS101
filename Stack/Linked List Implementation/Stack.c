#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#define MAX_SIZE 100

struct node
{
  StackElement data;
  struct node* next;
};

typedef struct node* node;

struct stack
{
  node top;
};

stack stackInit()
{
  stack s = malloc(sizeof(struct stack));
  
  if(s == NULL)
    return NULL; /* Not enough memory */
   
  s->top = NULL;
  return s; 
}

void stackDestroy(stack s)
{
  while(!isEmpty(s))
    pop(s);

  free(s);
}

void push(stack s, StackElement data)
{
  node n  = malloc(sizeof(struct node));
  
  if(n == NULL)
    return;
  
  n->data = data;
  n->next = s->top;
  s->top = n;
}

StackElement pop(stack s)
{
  if(isEmpty(s))
    return;
  
  StackElement data = s->top->data;
  node top = s->top;
  s->top = s->top->next;
  free(top); 
  return data;
}

int isEmpty(stack s)
{
  if(s->top == NULL)
    return 1;
  return 0;
}

main() {
    char str[101];   /* String entered by user. */
    char *traverse;  /* Pointer used to traverse the string. */
    
    /*
     * Get a string from the user--don't enter more
     * than 100 characters!
     */
    printf("Enter a string: ");
    
    gets(str);  /* Read line, discard newline. */
    
    /*
     * Initialize the stack.  Make it at least
     * big enough to hold the string we read in.
     */
    stack s = stackInit(s);
    
    /*
     * Traverse the string and put each
     * character on the stack.
     */
    
    for (traverse = str; *traverse != '\0'; traverse++) {
        push(s, *traverse);
    }
    
    /*
     * Pop each of the characters off of
     * the stack and print them out.
     */
    
    printf("\nPopped characters are: ");
    
    while (!isEmpty(s)) {
        printf("%c", pop(s));
    }
    
    printf("\n");
    
    stackDestroy(s);
    
    return 0;
}