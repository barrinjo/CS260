#include <iostream>
#include "AVLTree.hpp"
#define SIZE 1000000000

void clearScreen() {
        std::cout << "\033[2J\033[1;1H";
}

int main(int argc, char const *argv[])
{
        using std::cout;
        using std::endl;

        AVLTree<long> h;
        if(h.contains(70))
                cout << "contains 70" << endl;

        for(long i = 0; i < SIZE; i++) {
                h.add(i);
                if(i%100000 == 0) {
                        float complete = 100*((float)i / (float)SIZE);
                        cout << "binary tree " << complete << " percent complete..." << std::flush;
                        clearScreen();
                }
        }

        long input;
        while(true) {
                cout << "pick a number: ";
                std::cin >> input;
                if(h.contains(input))
                        cout << "found" << endl;
        }


        return 0;
}