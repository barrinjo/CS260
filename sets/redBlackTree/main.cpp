#include <iostream>
#include "RedBlackTree.hpp"

int main(int argc, char const *argv[])
{
        using std::cout;
        using std::endl;

        RedBlackTree<int> h;

        h.add(1);
        h.add(13);
        h.add(20);
        h.add(33);
        h.add(35);
        h.add(38);
        h.add(44);
        h.add(50);
        h.add(69);
        h.add(77);
        h.add(100);
        h.dump(cout);

        if(h.contains(44))
                cout << "contains 70" << endl;

        return 0;
}