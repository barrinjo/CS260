#include "linkedList.hpp"
#include <iostream>

template<typename T>
void linkedList<T>::append(T data){
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

template<typename T>
void linkedList<T>::print(std::ostream& os) {
        node *n = head;
        while (n) {
                os << n->data;
                n = n->next;
        }
}