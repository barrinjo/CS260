#include <stdlib.h>
#include <stdio.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
};

struct node *root = NULL;

struct node *insert(struct node *n, int data) {
	if(!n) {
		n = malloc(sizeof *n);
		n->data = data;
		n->left = n->right = n->parent = NULL;
	} else if(n->data > data) {
		n->left = insert(n->left, data);
		n->left->parent = n;
	} else if(n->data < data) {
		n->right = insert(n->right, data);
		n->right->parent = n;
	}
	return n;
}

struct node *find(struct node *n, int data) {
	if (!n) {
		return n;
	} else if (n->data > data) {
		return find(n->left, data);
	} else if (n->data < data) {
		return find(n->right, data);
	} else {
		return n;
	}
}

struct node **into(struct node *n) {
	if(!n->parent)
		return &root;
	else if (n == n->parent->left)
		return &n->parent->left;
	else 
		return &n->parent->right;
}

struct node *successor(struct node *n) {
	if(n->right) {
		n = n->right;
		while(n->left)
			n = n->left;
	} else {
		while(n->parent && n->parent->right == n) 
			n = n->parent;
		n = n->parent;
	}
	return n;
}

struct node *begin(void) {
	struct node *n = root;
	if(n)
		while(n->left)
			n = n->left;
	return n;
}

struct node *end(void) {
	return NULL;
}

void delete(struct node *n) {
	if(!n->left && !n->right){
		*into(n) = NULL;
		free(n);
	}
	else if (n->left && !n->right){
		n->left->parent = n->parent;
		*into(n) = n->left;
		free(n);
	}
	else if (n->left && !n->right){
		n->right->parent = n->parent;
		*into(n) = n->left;
		free(n);
	} else {
		struct node *s = successor(n);
		n->data = s->data;
		delete(s);
	}
}

void add(int data) {
	root = insert(root, data);
}

void drop(int data) {
	struct node *n = find(root, data);
	if(n)
		delete (n);
}

void print_node(struct node *n) {
	printf("%d\n", n->data);
}

void traverse(struct node *n, void (*action)(struct node *)) {
	if(n) {
		traverse(n->left, action);
		action(n);
		traverse(n->right, action);
	}
}

int addNodeTotal;
void addNodes(struct node *n) {
	addNodeTotal += n->data;
}

int main(int argc, char const *argv[])
{
	//struct node *n;
	//int i = 0;

	add(13);
	add(7);
	add(6);
	add(2);
	add(12);
	add(1);
	add(14);


	//for(n = begin(); n != end(); n = successor(n))
	//	print_node(n);

	traverse(root, print_node);

	addNodeTotal = 0;
	traverse(root, addNodes);
	printf("%d total\n", addNodeTotal);

	/*for(n = begin(); n != end(); n = successor(n))
		i += n->data;
	printf("\ntotal = %d\n", i);*/

	/*if(find(root, 6))
		printf("found 6\n");
	if(find(root, 5))
		printf("found 5\n");
	drop(1);
	if(!find(root, 1))
		printf("no 1\n");
	drop(7);
	drop(13);*/
	return 0;
}