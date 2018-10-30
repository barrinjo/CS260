#include <iostream>
#include "hashtable.hpp"

int main(int argc, char const *argv[])
{
        using std::cout;
        using std::endl;

        hashtable h;
        if(h.contains(70))
                cout << "contains 70" << endl;

        h.add(70);
        h.add(13);
        h.add(15);
        h.add(198);
        h.add(123909);
        h.add(4);
        h.add(36);
        h.add(44);

        /*for(int i : h)
                cout << i << endl;*/

        for(hashtable::iterator i = h.begin(); i != h.end(); ++i)
                cout << *i << endl;

        if(h.contains(70))
                cout << "now contains 70" << endl;
        if(h.contains(36))
                cout << "now contains 36" << endl;
        if(!h.contains(3))
                cout << "does not contain 3" << endl;

        return 0;
}