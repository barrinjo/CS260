#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <cstdlib>

class hashclosed {
        struct bucket {
                int data;
                bool empty;
                bucket(): data(), empty(true) {}
        };

        static size_t hash(int data) { return data % SIZE; }
        bucket table[SIZE] = {};
public:
        hashclosed(size_t size = 32): size(size), table(new bucket[size]) {}
        ~hashclosed() { delete table; }
        void add(int data);
        bool contains(int data);
};

#endif