#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class list {
        void append(T data);
        void insert(T data);
        void print(ostream& os);
};

#endif