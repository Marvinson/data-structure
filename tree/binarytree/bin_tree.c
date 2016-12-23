#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "bin-tree.h"

int last_parent_pointer = -1;
int current_seat = -1;

COLLECTION * initialize()
{
	COLLECTION *collect = malloc(sizeof(COLLECTION));
	collect->total = 0;
	collect->cursor = -1;
	return collect;
}

int is_empty(COLLECTION *collect)
{
	return collect->total == 0 ? 1 : -1;
}

int is_full(COLLECTION *collect)
{
	return collect->total == TOTAL ? 1 : -1;
}

/**
 * return int{-1:insert-error, other-number:array-index} 
 */
int insert(int data, COLLECTION *collect)
{
	if (is_full(collect) == 1) return -1;

	// initialize tree node
	TREE_NODE tree_node;
	tree_node.element        = data;
	tree_node.parentnode     = -1;
	tree_node.leftchildnode  = -1;
	tree_node.rightchildnode = -1;

	// storage nodex
	current_seat++;
	collect->elements[current_seat] = tree_node;
	
	// if node is head
	if (is_empty(collect) == 1) {
		collect->cursor++;	
		last_parent_pointer = collect->cursor;
	} 
	
	// if node is descendant node
	else if (is_empty(collect) == -1) {
		// fetch parent node
		struct treenode parentnode = collect->elements[last_parent_pointer];

		if (parentnode.leftchildnode == -1) {
			parentnode.leftchildnode = current_seat; 
			tree_node.parentnode = last_parent_pointer;
		} else if (parentnode.rightchildnode == -1) {
			parentnode.rightchildnode = current_seat;
			tree_node.parentnode = last_parent_pointer;
		}
		
		if (parentnode.leftchildnode != -1 && parentnode.rightchildnode != -1) {
			collect->cursor++;
			last_parent_pointer = collect->cursor;
		}
	}

	collect->total++;
	
	return current_seat;
}

int main()
{
	COLLECTION *collect = initialize();
	
	for(int i=1; i<=TOTAL; i++) {
		int seat = insert(i, collect);
		printf("current seat is %d\n", seat);
	}

	printf("------------------------------\n");

	for(int i=0; i<TOTAL; i++) {
		int element = collect->elements[i].element;
		printf("current element is %d\n", element);
	}
}


