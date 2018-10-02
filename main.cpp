#include "list.hpp"
#include "linkedList.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
        linkedList<int> list;
        list.append(1);
        list.append(2);
        list.append(3);
        list.insert(0);
        list.print(std::cout);
        return 0;
}