#include <cstdlib>
#include "hashclosed.hpp"

void hashclosed::add(int data) {
        size_t i = hash(data);
        while(!table[i].empty)
                i = (i+1);
        table[i].data = data;
        table[i].empty = false;
}

bool hashclosed::contains(int data) {
        size_t i = hash(data);
        for(size_t i = hash(data); !table[i].empty; i = hash(i+1)) {
                if(table[i].data == data)
                        return true; 
        }
        while(!table[i].empty) {
                if(table[i].data == data)
                        return true;
                i = (i + 1);
        }
        return false;
}