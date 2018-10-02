#include <iostream>
#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class list {
public:
        virtual void append(T data) = 0;
        virtual void insert(T data) = 0;
        virtual void print(std::ostream& os) = 0;
};

#endif