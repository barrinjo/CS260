#ifndef SET_HPP
#define SET_HPP

template <typename T>
class set {
public:

        virtual bool contains(T elem) = 0;
        virtual void add(T elem) = 0;
        virtual void remove(T elem) = 0;

};

#endif