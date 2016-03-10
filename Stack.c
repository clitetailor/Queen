#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



bool CreateStack(Stack ** stack, int datatype, int quantity)
{
	(* stack) = (Stack *) malloc( sizeof(Stack) );
	
	(* stack)->data = (void **) malloc( sizeof(void *) * quantity );
	
	
	if ( (* stack)->data == NULL )
	{
		return false;
	}
	
	(* stack)->top = 0;
	(* stack)->datatype = datatype;
	(* stack)->quantity = quantity;
	
	return true;
}

void DestroyStack(Stack * stack)
{
	while (CheckEmpty(stack) != true)
	{
		free( pop(stack) );
	}
	
	free(stack->data);
}

void push(Stack * stack, void * data)
{
	if (CheckFull(stack) == true)
	{
		return;
	}
	
	stack->data [ stack->top ] = data;
	
	++ (stack->top);
}

void * pop(Stack * stack)
{
	if (CheckEmpty(stack) == true)
	{
		return NULL;
	}
	
	-- (stack->top);
	return stack->data [ stack->top ];
}

bool CheckEmpty(Stack * stack)
{
	if (stack->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CheckFull(Stack * stack)
{
	if (stack->top == stack->quantity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Match(Stack * stack, void * data)
{
	int i;
	for (i = 0; i < stack->top; ++i)
	{
		if ( memcmp( stack->data[i], data, stack->datatype) == 0 )
		{
			return true;
		}
	}
	
	return false;
}



#ifdef test


int main()
{
	Stack * a;
	CreateStack(a, sizeof(int), 5);
	
	int i;
	
	for (i = 0; i < 6; ++i)
	{				
		int * MyInt = malloc(sizeof(int));
		(*MyInt) = i;
		 
		if(CheckFull(a) != true)
		{
			push( a, (void *) MyInt );
		}
		else
		{
			printf("Stack is full!\n");
		}
	}
	
	DestroyStack(a);
	
	for (i = 0; i < 7; ++i)
	{
		int * MyInt;
		
		if (CheckEmpty(a) != true)
		{
			MyInt = (int *) pop(a);
			printf("Good content: %d\n",  (* MyInt) );
			free(MyInt);
		}
		else
		{
			printf("Stack is empty!\n");
		}
	}
	
	return 0;
}

#endif