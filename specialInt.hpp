#ifndef SPECIALINT_HPP
#define SPECIALINT_HPP

#include<iostream>
using std::ostream;

class specialInt {
        int value;
public:
        specialInt() { std::cerr << "default special int: " << value << std::endl; }
        specialInt(int value): value(value) {}
        specialInt(const specialInt &other): value(other.value) {}
        friend ostream &operator<<(ostream &os, const specialInt &si);
};

ostream &operator<<(ostream &os, const specialInt &si) {
        os << si.value;
        return os;
}

#endif