#include "list.hpp"
#include "linkedList.hpp"
#include "circularList.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
        linkedList<int> list;

        list.append(1);
        list.append(2);
        list.append(3);
        list.insert(0);
        list.print(std::cout);

        circularList<std::string> test;
        
        test.append("hotdog");
        test.append("peanuts");
        test.append("popcorn");
        test.insert("polar bear liver");
        test.print(std::cout);

        return 0;
}