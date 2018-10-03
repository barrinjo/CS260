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
        node *tail;
public:
        circularList(): head(NULL), tail(NULL) {
                head = tail = new node(T(), NULL, NULL);
                head->next = head->previous = head;
        }

        void append(T data) {
                tail = head->previous = tail->next = new node(data, head, tail);
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