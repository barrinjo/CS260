#include<iostream>
#include "heap.hpp"

int main(int argc, char const *argv[])
{
        heap h;
        for(int i = 1; i <= SIZE; i++)
                h.add(i);
        for(int i = 0; i < SIZE; i++)
                std::cout << h.data(i) << " ";
        std::cout << std::endl;
        h.remove(SIZE);


        return 0;
}