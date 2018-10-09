#include "list.hpp"
#include "linkedList.hpp"
#include "circularList.hpp"
#include "doubleLinkedList.hpp"
#include "specialInt.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
        linkedList<std::string> list;

        list.append("worchestershire");
        list.append("wombo");
        list.append("   ");
        list.insert("wiggle");
        for(auto n: list) { std::cout << n << std::endl }

}