#include "list.hpp"
#include "linkedList.hpp"
#include "circularList.hpp"
#include "doubleLinkedList.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
        linkedList<int> l;
        l.append(5);
        l.append(6);
        l.insert(4);
        for(auto v : l)
                std::cout << v << std::endl;

        doubleLinkedList<std::string> j;
        j.append("one");
        j.append("two");
        j.append("three");
        for(auto v : j)
                std::cout << v << std::endl;
        return 0;
}