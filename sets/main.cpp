#include <iostream>

int main(int argc, char const *argv[])
{
        using std::cout;
        using std::endl;

        treeSet<int> set;
        set.add(1);
        set.add(3);
        set.add(5);
        if(set.contains(3))
                cout << "set contains 3" << endl;
        if(!set.contains(4))
                cout << "set doesn't contain 4" << endl;
        set.remove(3);
        if(!set.contains(3))
                cout << "3 has been removed from the set" << endl;
        
        return 0;
}