#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "list.hpp"

template <typename T>
class linkedList : public list<T> {
        struct node {
                T data;
                node *next;
                node(T data): data(data), next(NULL){}
                ~node() { if(next) delete next; }\
        };

        node *head;
        node *tail;
public:
        linkedList(): head(NULL), tail(NULL) {}
        ~linkedList() { if (head) delete head; }
	void append(T data){
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
};

#endif