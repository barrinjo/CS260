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

        node *buckets[SIZE] = {};
public:
        class iterator {
                hashtable *table;
                size_t bucket;
                node *n;
                void find(size_t start) {
                        for(bucket = start; bucket < SIZE; ++bucket) {
                                n = table->buckets[bucket];
                                if(n)
                                        break;
                        }
                }
        public:
                iterator() {}
                iterator(const iterator &i): table(i.table), bucket(i.bucket), n(i.n) {}
                iterator(hashtable *table): table(table) { find(0); }

                bool operator==(const iterator &i) {
                        return n == i.n;
                }
                bool operator!=(const iterator &i) {
                        return !(*this == i);
                }
                int &operator*() { return n->data; }
                iterator &operator++() {
                        n = n->next;
                        if(!n)
                                find(bucket+1);
                        return *this;
                }
                iterator operator++(int) {
                        iterator i(*this);
                        ++(*this);
                        return i;
                }
        };

        void add(int data);
        bool contains(int data);
        iterator begin() { return iterator(this); }
        iterator end() { return iterator(); }
};

#endif
