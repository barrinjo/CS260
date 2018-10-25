#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#define SIZE 32

class hashtable {
        struct node {
                int data;
                node *next;

                node(int data): data(data) {}
        };

        node *buckets[SIZE];
public:
        void add(int data);
        bool contains(int data);
};

#endif