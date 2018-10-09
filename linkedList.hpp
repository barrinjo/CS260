#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "list.hpp"

template<typename T> class linkedListIterator;

template <typename T>
class linkedList : public list<T> {
        typedef linkedListIterator<T> iterator;
        friend class linkedListIterator<T>;

        struct node {
                T data;
                node *next;
                node(T data): data(data), next(NULL) {}
                ~node() { if(next) delete next; }
        };

        node *head;
        node *tail;
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

        iterator begin() {
                return head;
        }

        iterator end() {
                return NULL;
        }
};

template <typename T>
class linkedListIterator {
        typedef typename linkedList<T>::node node;
};

template <typename T>
linkedListIterator<T> operator++(linkedListIterator<T> i) {
        i.cur = i.cur->next;
        return i;
}

template <typename T>
linkedListIterator<T> operator*(linkedListIterator<T> i) {
        return i.cur->data;
}

template <typename T>
bool operator!=(linkedListIterator<T> a, linkedListIterator<T> b) {
        return a.cur != b.cur;
}

#endif