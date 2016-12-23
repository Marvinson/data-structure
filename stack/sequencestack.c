#include <stdio.h>
#include <stdlib.h>
#include "seqstackstruct.h"

void single_stack_init(SINGLE_STACK *sstk)
{
	sstk->top = EMPTY;
}

int is_empty_of_single_stack(SINGLE_STACK *sstk)
{
	int compare = sstk->top == EMPTY ? 1 : 0;
	return compare;
}

int is_full_of_single_stack(SINGLE_STACK *sstk)
{
	int compare = sstk->top == TOTAL ? 1 : 0;
	return compare;
}

int push_of_single_stack(SINGLE_STACK *sstk, int element)
{
	if (is_full_of_single_stack(sstk)) return (TOTAL - 1);

	sstk->top++;
	sstk->elements[sstk->top] = element;
	return sstk->top;
}

int pop_of_single_stack(SINGLE_STACK *sstk)
{
	if (is_empty_of_single_stack(sstk)) return EMPTY;

	int element = sstk->elements[sstk->top];
	sstk->top--;
	return element;
}

int main()
{
	SINGLE_STACK sstk;
	single_stack_init(&sstk);

	for (int i = 1; i < 10; ++i) {
		int element = i * 10;
		push_of_single_stack(&sstk, element);
	}

	for(int i=0; i<10; i++) {
		int element = pop_of_single_stack(&sstk);
		if(element != -1) printf("%d\n", element);
	}
}