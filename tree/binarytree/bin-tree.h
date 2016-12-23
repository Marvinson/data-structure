#ifndef DEPTH 
 	#define DEPTH 10 
#endif

#ifndef TOTAL
	#define TOTAL (1024 - 1)
#endif

#ifndef TREE_NODE
	typedef struct treenode {
		int element;
		int leftchildnode, rightchildnode, parentnode;
	} tree_node;
	#define TREE_NODE tree_node
#endif

#ifndef COLLECTION
	typedef struct collection {
		struct treenode elements[TOTAL];
		int total, cursor;
	} collect;
	#define COLLECTION collect
#endif
