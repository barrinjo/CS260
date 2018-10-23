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
	return a->cur == b->cur;
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

void *_get(struct  _tree_iterator *i) {
	return i->cur->data;
};

struct _tree_iterator *_begin(struct _tree *tree) {
	struct _tree_iterator *i;
	i = malloc(sizeof *i);
	i->tree_iterator.get = (void *(*)(struct tree_iterator *)) _get;
	i->tree_iterator.set = NULL;
	i->tree_iterator.next = (void *(*)(struct tree_iterator *)) _next;
	i->tree_iterator.equals = (int (*)(struct tree_iterator *, struct tree_iterator *)) _equals;
	i->cur = tree->root;
	if(i->cur)
		while(i->cur->left)
			i->cur = i->cur->left;
	return i;
}

struct _tree_iterator *_end(struct _tree *tree) {
	struct _tree_iterator *i;
	i = malloc(sizeof *i);
	i->tree_iterator.get = (void *(*)(struct tree_iterator *)) _get;
	i->tree_iterator.set = NULL;
	i->tree_iterator.next = (void *(*)(struct tree_iterator *)) _next;
	i->tree_iterator.equals = (int (*)(struct tree_iterator *, struct tree_iterator *)) _equals;
	i->cur = NULL;
	return i;
}

static struct node *find(struct _tree *tree, void *data) {
	struct node *n = tree->root;
	while(n) {
		int direction = tree->tree.compare(data, n->data);
		if(direction > 0) {
			n = n->right;
		} else if(direction < 0) {
			n = n->left;
		} else {
			return n;
		}
	}
	return n;
}

static int contains(struct _tree *tree, void *data) {
	return find(tree, data) != NULL;
}

static void destroy_node(struct node *node) {
	if(node) {
		destroy_node(node->left);
		destroy_node(node->right);
		free(node);
	}
}

static void _destroy(struct _tree *tree) {
	destroy_node(tree->root);
	free(tree);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static struct node *insert(struct _tree *tree, struct node *n, void *data) {
	if(!n) {
		n = malloc(sizeof *n);
		n->data = data;
		n->left = n->right = n->parent = NULL;
	} else if(tree->tree.compare(n->data, data) > 0) {
		n->left = insert(tree, n->left, data);
		n->left->parent = n;
	} else if(tree->tree.compare(n->data, data) < 0) {
		n->right = insert(tree, n->right, data);
		n->right->parent = n;
	}
	return n;
}

static struct node **into(struct _tree *tree, struct node *n) {
	if(!n->parent)
		return &tree->root;
	else if (n == n->parent->left)
		return &n->parent->left;
	else 
		return &n->parent->right;
}

static void delete(struct _tree *tree, struct node *n) {
	if(!n->left && !n->right){
		*into(tree, n) = NULL;
		free(n);
	}
	else if (n->left && !n->right){
		n->left->parent = n->parent;
		*into(tree, n) = n->left;
		free(n);
	}
	else if (n->left && !n->right){
		n->right->parent = n->parent;
		*into(tree, n) = n->left;
		free(n);
	} else {
		struct node *s = successor(n);
		n->data = s->data;
		delete(tree, s);
	}
}

static void _add(struct tree *tree, void *data) {
	struct _tree *_tree = (struct _tree *) tree;
	_tree->root = insert(_tree, _tree->root, data);
}

static void _remove(struct _tree *tree, void *data) {
	struct node *n = find(tree, data);
	if(n)
		delete(tree, n);

}

struct tree *tree_create(int (compare)(void *, void *)) {
	struct _tree *tree;
	tree = malloc(sizeof *tree);
	tree->tree.compare = compare;
	tree->tree.add = _add;
	tree->tree.remove = (void (*)(struct tree *, void *)) _remove;
	tree->tree.contains = (int (*)(struct tree *, void *)) contains;
	tree->tree.destroy = (void (*)(struct tree *)) _destroy;
	tree->tree.begin = (struct tree_iterator *(*)(struct tree *)) _begin;
	tree->tree.add = _add;
	tree->root = NULL;
	return (struct tree *) tree;
}