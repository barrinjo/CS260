#include <iostream>
#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class list {
public:
        void append(T data);
        void insert(T data);
        void print(std::ostream& os);
};

#endif