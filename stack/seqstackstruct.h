#ifndef MAX_SIZE
	#define MAX_SIZE 100
#endif

#ifndef EMPTY
	#define EMPTY -1
#endif

#ifndef TOTAL
	#define TOTAL (MAX_SIZE - 1)
#endif

#ifndef SINGLE_STACK
	typedef struct single_stack {
		int elements[MAX_SIZE];
		int top;
	} sstack;
	#define SINGLE_STACK sstack
#endif

#ifndef DOUBLE_STACK
	typedef struct double_stack {
		int elements[MAX_SIZE];
		int left_top, right_top;
	} dbstack;
	#define DOUBLE_STACK dbstack
#endif