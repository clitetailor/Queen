#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

bool CheckBoard(int * board, int n)
{
	int i, j;
	for (i = 0; i < n - 1; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if ( (board[i] - board[j]) == (i - j) ||
				 (board[i] - board[j]) == (j - i) ||
				 (board[i] == board[j])
			   )
			{
				return false;
			}
		}
	}
	
	return true;
}

void Mark(int * board, int n)
{
	int i, j;
	printf("\n");
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (board[i] == j)
			{
				printf("x");
			}
			else
			{
				printf("=");
			}
		}
		printf("\n");
	}
	
	printf("\n");
	
	for (i = 0; i < n; ++i)
	{
		printf("(%d, %d) ", i + 1, board[i] + 1);
	}
	
	printf("\n+++++++++++++++++++++++++\n");
}

typedef struct
{
	int i;
	int k;
} State;

State * CreateState(int k, int i)
{
	State * state = (State *) malloc(sizeof(State));
	
	if (state == NULL)
	{
		printf("Loi: Khong du bo nho!\n");
		exit(0);
	}
	
	state->i = i;
	state->k = k;
	
	return state;
}

void Queen(int * board, int n)
{
	Stack * StateStack;
	if ( CreateStack(&StateStack, sizeof(State), n * n) == false )
	{
		printf("Loi: Khong du bo nho!\n");
		exit(0);
	}
	
	int i, k;
	
	i = 0;
	k = 0;
	
	State * state;
	
	do
	{
		if (k < n)
		{
			for (i = 0; i < n; ++i)
			{
				state = CreateState(k, i);
				push(StateStack, state);
			}
		}
		
		state = pop(StateStack);
		k = state->k;
		i = state->i;
		board[k] = i;
		
		free(state);
		
		if (k == n - 1)
		{
			do
			{
				if (CheckBoard(board, n) == true)
				{
					Mark(board, n);
				}
				
				state = pop(StateStack);
				k = state->k;
				i = state->i;
				board[k] = i;
				
				free(state);
				
			} while (k == n-1);
		}
		
		++k;
		
	} while (CheckEmpty(StateStack) != true);
	
	DestroyStack(StateStack);
}


int main()
{
	int * board;
	
	int n;
	do
	{
		printf("Nhap vao do rong cua ban co:");
		fflush(stdin);
		scanf("%d", &n);
		
		if (n < 0)
		{
			printf("Loi: Du lieu nhap vao khong hop le!\n");
		}
		else
		{
			break;
		}
		
	} while (1);
	
	printf("Cac cach sap xep con hau\n");
	
	board = (int *) malloc(sizeof(int) * n);
	if (board == NULL)
	{
		printf("Loi: Khong du bo nho!");
		exit(0);
	}
	
	int i;
	for (i = 0; i < n; ++i)
	{
		board[i] = -1;
	}
	
	Queen(board, n);
	
	printf("Done!");
	
	return 0;
}