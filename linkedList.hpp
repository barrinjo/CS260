#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "list.hpp"

template <typename T>
class linkedList : public list<T> {
        struct node {
                T data;
                node *next;
        };

        node *head;
public:
        linkedList(): head(NULL){}
        void append(T data);
        void print(std::ostream& os);
};

#endif