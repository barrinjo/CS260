/*

This is the version that I made before we learned the doubly linked circular
list with dummy head in class.  It's the same idea as doubleLinkedList.hpp.  I 
decided not to touch it once class started even though there's problems just
to show the work that I was able to do myself.

*/

#ifndef CIRCULARLIST_HPP
#define CIRCULARLIST_HPP
#include "list.hpp"

template <typename T>
class circularList : public list<T> {
        struct node {
                T data;
                node *next;
                node *prev;
                node(T data, node *next, node *prev): data(data),
                                                      next(next),
                                                      prev(prev) {}
        };

        node *head;
public:
        circularList(): head(NULL) {
                head = new node(T(), NULL, NULL);
                head->next = head->prev = head;
        }

        void append(T data) {
                head->prev = head->prev->next = new node(data, head, head->prev);
        }

        void insert(T data) {
                head->next = head->next->prev = new node(data, head->next, head);
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

/*

This is the version that I made before we learned the doubly linked circular
list with dummy head in class.  It's the same idea as doubleLinkedList.hpp.  I 
decided not to touch it once class started even though there's problems just
to show the work that I was able to do myself.

*/