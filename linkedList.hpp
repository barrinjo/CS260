#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "list.hpp"

template <typename T>
class linkedList : public list<T> {
        struct node {
                T data;
                node *next;
                node(T data): data(data), next(NULL){}
        };

        node *head;
public:
        linkedList(): head(NULL){}
        ~linkedList() { if (head) delete head;}
	void append(T data){
		if(!head) {
			head = new node(data);
		}
		else {
			node *n = head;
			while(n->next) {
				n = n->next;
			}
			n->next = new node(data);
		}
	}

	void print(std::ostream& os) {
		node *n = head;
		while (n) {
			os << n->data;
                        os << std::endl;
			n = n->next;
		}
	}

	void insert(T data) {
		node *n = new node(data);
		n->next = head;
		head = n;
	}
};

#endif