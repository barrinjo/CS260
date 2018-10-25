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
        if(h.contains(70))
                cout << "now contains 70" << endl;

        return 0;
}