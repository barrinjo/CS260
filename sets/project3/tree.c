#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
	void *data;
	struct node *left;
	struct node *right;
	struct node *parent;
};

struct _tree {
	struct tree tree;
	struct node *root;
};

struct _tree_iterator {
	struct tree_iterator tree_iterator;
	struct node *cur;
};

int _equals(struct _tree_iterator *a, struct _tree_iterator *b) {
	return a->cur = b->cur;
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

void _next(struct _tree_iterator *i) {
	i->cur = successor(i->cur);
}

void _get(struct  _tree_iterator *i) {
	return i->cur->data;
};

struct tree_iterator *_begin(struct _tree *tree) {
	struct _tree_iterator *i;
	i = malloc(sizeof *i);
	i->tree_iterator->get = _get;
	i->tree_iterator->set = NULL;
	i->tree_iterator->next = _next;
	i->tree_iterator->equals = _equals;
	i->cur = tree->root;
	if(i->cur)
		while(i->cur->left)
			i->cur = i->cur->left;
	return i;
}

struct tree_iterator *_end(struct _tree *tree) {
	struct _tree_iterator *i;
	i = malloc(sizeof *i);
	i->tree_iterator->get = _get;
	i->tree_iterator->set = NULL;
	i->tree_iterator->next = _next;
	i->tree_iterator->equals = _equals;
	i->cur = NULL;
	return i;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct node *root = NULL;

static struct node *insert(struct node *n, int data) {
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

static void _add(struct tree *tree, void *data) {
	struct _tree _tree = tree;
	_tree->root = insert(_tree-root, data);
}

void drop(int data) {
	struct node *n = find(root, data);
	if(n)
		delete (n);
}

struct tree *tree_create(int (compare)(void *, void *)) {
	struct tree *tree;
	tree = malloc(sizeof *tree);
	tree->tree->compare = _compare;
	tree->tree->add = _add;
	tree->tree->remove = _remove;
	tree->tree->contains = _contains;
	tree->tree->destroy = _destroy;
	tree->tree->begin = _begin;
	tree->tree->add = _add;
	tree->root = NULL;
	return tree;
}