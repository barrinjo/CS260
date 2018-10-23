#ifndef TREE_H
#define TREE_H

struct tree_iterator {
        void *(*get)(struct tree_iterator *);
        void (*set)(struct tree_iterator *, void *);
        void *(*next)(struct tree_iterator *);
        int (*equals)(struct tree_iterator *, struct tree_iterator *);
        void (*destroy)(struct tree_iterator *);
};

struct tree {
        int (*compare)(void *, void *);
        void (*add)(struct tree *, void *);
        void (*remove)(struct tree *, void *);
        int (*contains)(struct tree *, void *);
        void (*destroy)(struct tree *);
        struct tree_iterator *(*begin)(struct tree *);
        struct tree_iterator *(*end)(struct tree *);
};

struct tree *treeCreate(int (*compare)(void *, void *));

#endif