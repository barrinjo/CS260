#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

template <typename T>
class linkedList : list<T> {
        struct node {
                T data;
                node *next;
        };

        node *head;

        linkedList(): head(NULL){}
};

#endif