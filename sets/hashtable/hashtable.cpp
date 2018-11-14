#include<cstdlib>
#include "hashtable.hpp"

void hashtable::add(int data) {
        node *n = new node(data);
        size_t i = hash(data);
        n->next = buckets[i];
        buckets[i] = n;
}

bool hashtable::contains(int data) {
        node *n = buckets[hash(data)];
        while(n) {
                if(n->data == data)
                        return true;
                n = n->next;
        }
        return false;
}