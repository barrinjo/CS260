#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#define SIZE 32

#include<cstdlib>

class hashtable {
        struct node {
                int data;
                node *next;

                node(int data): data(data) {}
        };

        static size_t hash(int data) { return data % SIZE; }

        node *buckets[SIZE];
public:
        void add(int data);
        bool contains(int data);
};

#endif