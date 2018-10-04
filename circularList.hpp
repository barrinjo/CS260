#ifndef CIRCULARLIST_HPP
#define CIRCULARLIST_HPP
#include "list.hpp"

template <typename T>
class circularList : public list<T> {
        struct node {
                T data;
                node *next;
                node *previous;
                node(T data, node *next, node *previous): data(data), next(next), previous(previous) {}
                ~node() { if(next) delete next; }
        };

        node *head;
public:
        circularList(): head(NULL) {
                head = new node(T(), NULL, NULL);
                head->next = head->previous = head;
        }

        void append(T data) {
                head->previous = head->previous->next = new node(data, head, head->previous);
        }

        void insert(T data) {
                head->next = head->next->previous = new node(data, head->next, head);
        }

        void print(std::ostream& os) {
                node *n = head;
                while(n->next != head) {
                        n = n->next;
                        os << n->data;
                        os << std::endl;
                };
        }
};

#endif