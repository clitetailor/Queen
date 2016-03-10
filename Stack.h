#ifndef H_STACK
#define H_STACK

#include <stdbool.h>


typedef struct
{
	void ** data;
	int quantity;
	int datatype;
	int top;
}
Stack;


bool CreateStack(Stack ** stack, int datatype, int quantity);
void DestroyStack(Stack * stack);

void push(Stack * stack, void * data);
void * pop(Stack * stack);

bool CheckEmpty(Stack * stack);
bool CheckFull(Stack * stack);

bool Match(Stack * stack, void * data);

#endif