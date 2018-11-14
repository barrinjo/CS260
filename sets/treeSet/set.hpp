#ifndef SET_HPP
#define SET_HPP

template <typename T>
class set {
public:

        virtual bool contains(T elem) = 0;
        virtual bool add(T elem) = 0;
        virtual bool remove(T elem) = 0;
        set &operator +=(T elem) { add(elem); return *this; }
        set &operator -=(T elem) { remove(elem); return *this; }

};

#endif