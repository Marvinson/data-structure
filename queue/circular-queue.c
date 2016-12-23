#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data, next;
};

struct pointer
{
	struct front {
		int current, next;
	} front;

	int rear;
};

#if !defined(MAX_SIZE) 
	#define MAX_SIZE 6
#endif

#if !defined(MAX_LENGTH) 
	#define MAX_LENGTH (MAX_SIZE - 1)
#endif

#if !defined(NOT_EMPTY) 
	#define NOT_EMPTY -1
#endif

#if !defined(EMPTY) 
	#define EMPTY 1
#endif

struct container
{
	int total;
	
	struct node elements[MAX_LENGTH];
};

void initialize(struct pointer *point)
{
	point->front.current = 0;
	point->rear  = 0;
}

int isEmpty(struct pointer *point)
{
	int isEmpty = point->front.current == point->rear ? EMPTY : NOT_EMPTY;
	return isEmpty;
}

int enter(int data, struct container *container, struct pointer *point)
{
	int seat = (point->rear + 1) == MAX_SIZE ? 0 : (point->rear + 1);
	printf("seat is %d\n", seat);
	
	if (seat == point->front.current) return -1;

	// 把链表的节点存放到容器中
	struct node element;
	element.data = data;
	element.next = -1;
	container->elements[seat] = element;
	printf("container->elements[%d]:{data:%d, next:%d}\n", seat, element.data, element.next);

	// 如果队列为空,头指针的后继指针域存储当前节点的指针地址
	if (isEmpty(point) == EMPTY) {
		point->front.next = seat;
		printf("point->front.next=%d\n", seat);
	// 如果队列不为空,新插入节点的前驱节点的后继指针域存储新插入节点的指针地址
	} else { 
		container->elements[point->rear].next = seat;
		printf("container->elements[%d].next=%d\n", point->rear, seat);
	}
	// 尾指针指向最后一个节点
	point->rear = seat;
	printf("point->rear=%d\n", seat);
	printf("point->front.current=%d\n", point->front.current);
	printf("point->front.next=%d\n", point->front.next);

	return seat;

}

int out(struct pointer *point, struct container *container)
{
	if (isEmpty(point) == EMPTY) {
		return -1;
	}

	// 取出头结点的后继节点的值
	int element = container->elements[point->front.next].data;

	// 替换头结点的后继指针域
	point->front.next = container->elements[point->front.next].next;

	// 销毁
	// free(container->elements[point->front.next]);

	// 替换头结点的当前指针域
	point->front.current = point->front.current == MAX_SIZE ? 0 : (point->front.current + 1);

	return element;
}

int main()
{
	struct pointer point;
	
	struct container container;

	initialize(&point);

	for(int i=0; i<3; i++) {
		int data = i + 2;
		int input = enter(data, &container, &point);
		if (input == -1) {
			printf("queue overflow \n");
			break;
		}
		printf("------------------------------------\n");
	}

	for(int j=0; j<3; j++) {
		int ele = out(&point, &container);
		printf("ele is %d and point->front.current is %d\n", ele, (point.front.current));
	}

	// int isEmpty = isEmpty(&point);
	// printf("isEmpty %d\n", isEmpty);

}