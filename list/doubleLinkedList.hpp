#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
#include "list.hpp"

template <typename T>
class doubleLinkedList : public list<T> {
        struct node {
                T data;
                node *next;
                node *prev;
                node(): next(this), prev(this) {}
                node(T data, node *next): data(data),
                                          next(next),
                                          prev(next->prev)
                                          { fix (); }
                node(T data): data(data), next(this), prev(this) {}
                void fix() { next->prev = prev->next = this; }
        };

        node *head;

        class iterator {
                node *cur;
        public:
                iterator(const iterator &i): cur(i.cur) {}
                iterator(node *cur): cur(cur) {}

                bool operator ==(const iterator &i) { return cur == i.cur; }
                bool operator !=(const iterator &i) { return cur != i.cur; }
                T &operator *() { return cur->data; }
                iterator &operator++() {
                        cur = cur->next;
                        return *this;
                }
                iterator &operator++(int) {
                        iterator i(this);
                        cur = cur->next;
                        return i;
                }
        };
public:
        doubleLinkedList(): head(new node) {}
        ~doubleLinkedList() {
                node *n = head->next;
                while(n != head) {
                        n = n->next;
                        delete n->prev;
                }
        }

	void append(T data) {
		new node(data, head);
	}

        void insert(T data) {
                new node(data, head->next);
        }

	void print(std::ostream& os) {
		node *n = head->next;
                while(n != head) {
                        os << n->data << std::endl;
                        n = n->next;
                }
	}

        iterator begin() { return iterator(head->next); }
        iterator end() { return iterator(head); }
};

#endif