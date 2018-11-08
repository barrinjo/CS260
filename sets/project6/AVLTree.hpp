#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include <cstdlib>

template <typename T>
class AVLTree {
        struct node {
                T data;
                node *left;
                node *right;
                node *parent;
                size_t height;
                node(T data): data(data), left(NULL), right(NULL), parent(NULL), height(1) {}
                ~node() {
                        if(left)
                                delete left;
                        if(right)
                                delete right;
                }
                node *ensure(T data) {
                        if(this->data == data) {
                                return NULL;
                        } else if(this->data > data) {
                                node *n
                                if(left)
                                        n = left->ensure(data);
                                else
                                        n = left = new node(data);
                                if(left->height + 1 > height) height = left->height + 1;
                        } else {
                                node *n;
                                if(right)
                                        n = right->ensure(data);
                                else
                                        n = right = new node(data);
                                if(right->height + 1 > height) height = right->height + 1;
                        }
                        return n;
                }
                int balance() {
                        int b = 0;
                        if(left)
                                b -= left->height;
                        if(right)
                                b += right->height;
                        return b;
                }
        };
        node *root;
        void rebalance(node *n) {
                
        }
public:
        AVLTree(): root(NULL) {}
        ~AVLTree() {
                if(root)
                        delete root;
        }
        void add(T data) {
                if(!root) {
                        root = new node(data);
                        return;
                }
                node *n = root->ensure(data);
                if(!n)
                        return;
                rebalance(n);
        }
        bool contains(T data) {
                node *n = root;
                while(n) {
                        if(n->data == data)
                                return true;
                        else if(n->data < data)
                                n = n->right;
                        else
                                n = n->left;
                }
                return false;
        }
};

#endif