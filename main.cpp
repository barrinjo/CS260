#include "list.hpp"
#include "linkedList.hpp"
#include "circularList.hpp"
#include "doubleLinkedList.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
        linkedList<std::string> list;

        list.append("worchestershire");
        list.append("wombo");
        list.append("   ");
        list.insert("wiggle");
        list.print(std::cout);

        circularList<int> test;
        for(int i = 0; i <= 15; i++) { test.append(i); }
        test.print(std::cout);

        std::cout << std::endl;
        doubleLinkedList<int> doubleList;
        doubleList.append(5);
        doubleList.append(6);
        doubleList.insert(4);
        doubleList.print(std::cout);
        return 0;
}