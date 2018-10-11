#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "list.hpp"

template <typename T>
class linkedList : public list<T> {
        struct node {
                T data;
                node *next;
                node(T data): data(data), next(NULL) {}
                ~node() { if(next) delete next; }
        };

        node *head;
        node *tail;

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
        linkedList(): head(NULL), tail(NULL) {}
        ~linkedList() { if (head) delete head; }

	void append(T data) {
		if(!tail)
			tail = head = new node(data);
		else
			tail = tail->next = new node(data);
	}

        void insert(T data) {
                node *n = new node(data);
                n->next = head;
                head = n;
                if(!tail)
                        tail = n;
        }

	void print(std::ostream& os) {
		node *n = head;
		while (n) {
			os << n->data;
                        os << std::endl;
			n = n->next;
		}
	}

        iterator begin() { return iterator(head); }
        iterator end() { return iterator(NULL); }
};

#endif