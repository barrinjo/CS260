#ifndef CIRCULARLIST_HPP
#define CIRCULARLIST_HPP
#include "list.hpp"

template <typename T>
class circularList : public list<T> {
        struct node {
                T data;
                node *next;
                node *previous;
                node(T data): data(data), next(NULL), previous(NULL) {}
                ~node() { if(next) delete next; }
        };

        node *head;
        node *tail;
public:
        circularList(): head(NULL), tail(NULL) {}

        void append(T data) {
                if(!head) {
                        tail = head = new node(data);
                        head->next = head->previous = head;
                }
                else {
                        node *n = tail;
                        tail = head->previous = tail->next = new node(data);
                        tail->previous = n;
                        tail->next = head;
                }
        }

        void insert(T data) {
                node *n = head;
                head = head->previous = tail->next = new node(data);
                head->previous = tail;
                head->next = n;
        }

        void print(std::ostream& os) {
                node *n = head;
                do {
                        os << n->data;
                        os << std::endl;
                        n = n->next;
                } while(n != head);
        }
};

#endif