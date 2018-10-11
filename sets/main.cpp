#include <iostream>
#include "treeSet.hpp"
#include "set.hpp"

int main(int argc, char const *argv[])
{
        using std::cout;
        using std::endl;

        treeSet<int> set;
        set += 1;
        set += 3;
        set += 5;
        if(set.contains(3))
                cout << "set contains 3" << endl;
        if(!set.contains(4))
                cout << "set doesn't contain 4" << endl;
        set -= (3);
        if(!set.contains(3))
                cout << "set doesn't contain 3" << endl;

        return 0;
}