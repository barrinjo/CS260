#ifndef TREESET_HPP
#define TREESET_HPP
#include "set.hpp"

template <typename T>
class treeSet : public set<T> {

        class node {
                T data;
                node *left;
                node *right;
                node *parent;
        public:
                node(): node(T()) {}
                node(T data): data(data), left(NULL), right(NULL), parent(NULL) {}
                ~node() { if(left) delete left; if(right) delete right; }

                bool contains(T elem) {
                        if(elem < data)
                                return left && left->contains(elem);
                        else if(elem > data)
                                return right && right->contains(elem);
                        else
                                return true;
                }
                bool add(T elem) {
                        if(elem == data)
                                return false;
                        else if(elem < data) {
                                if(!left) {
                                        left = new node(elem);
                                        return true;
                                } else {
                                        return left->add(elem);
                                }
                        }
                        else {
                               if(!right) {
                                        right = new node(elem);
                                        return true;
                                } else {
                                        return right->add(elem);
                                }
                        }
                }
        };

        node *root;
public:
        treeSet(): root(NULL) {}
        ~treeSet() { if(root) delete root; }

        bool contains(T elem) {
                return root && root->contains(elem);
        }
        bool add(T elem) {
                if(!root) {
                        root = new node(elem);
                        return true;
                } else {
                        return root -> add(elem);
                }
        }
        bool remove(T elem) {
                return true;
        }
};

#endif