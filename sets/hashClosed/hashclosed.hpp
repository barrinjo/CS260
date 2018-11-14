#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <cstdlib>

class hashclosed {
        struct bucket {
                int data;
                bool empty;
                bucket(): data(), empty(true) {}
        };

        size_t hash(int data) { return data % size; }
        size_t size;
        bucket *table;
public:

        class iterator {
                hashclosed *table;
                size_t bucket;
        public:
                iterator(const iterator &i): table(i.table), bucket(i.bucket) {}
                iterator(hashclosed *table): table(table) {
                        for(bucket = 0; bucket < table->size; ++bucket) {
                                if(!table->table[bucket].empty)
                                        break;
                        }
                }
                iterator &end() { bucket = table->size; return *this; }
                bool operator==(const iterator &i) { return table == i.table && bucket == i.bucket; }
                bool operator!=(const iterator i) { return !(*this == i); }
                int &operator*() { return table->table[bucket].data; }
                iterator &operator++() {
                        for(++bucket; bucket < table->size; ++bucket) {
                                if(!table->table[bucket].empty)
                                        break;
                        }
                        return *this;
                }
                iterator operator++(int) {
                        iterator i(*this);
                        ++(*this);
                        return i;
                }
        };

        hashclosed(size_t size = 32): size(size), table(new bucket[size]) {}
        ~hashclosed() { delete[] table; }
        void add(int data);
        bool contains(int data);

        iterator begin() { return iterator(this); }
        iterator end() {
                return iterator(this).end();
        }
};

#endif