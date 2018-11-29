#ifndef HEAP_HPP
#define HEAP_HPP
#include<vector>
#define SIZE 16

class heap {
        int heapArray[SIZE];
        int parent(int i) {
                return (i-1)/2;
        }
        int left(int i) {
                return (i*2)+1;
        }
        int right(int i) {
                return (i*2)+2;
        }
        void bubble(int i) { 
                if(heapArray[parent(i)] < heapArray[i]) {
                        int temp = heapArray[parent(i)];
                        heapArray[parent(i)] = heapArray[i];
                        heapArray[i] = temp;
                        bubble(parent(i));
                }
        }
        void fill(int i) {
                if(left(i) < SIZE) {
                        if(heapArray[left(i)] > heapArray[right(i)]) {
                                heapArray[i] = heapArray[left(i)];
                                fill(left(i));
                        } else {
                                heapArray[i] = heapArray[right(i)];
                                fill(right(i));
                        }
                }
        }
public:
        heap(): heapArray() {}
        int data(int i) { return heapArray[i]; }
        void add(int data) {
                for(int i = 0; i < SIZE; i++) {
                        if(!heapArray[i]) {
                                heapArray[i] = data;
                                bubble(i);
                                break;
                        }
                }
        }
        void remove(int data) {
                for(int i = 0; i < SIZE; i++) {
                        if(heapArray[i] == data)
                                fill(i);
                }
        }
};

#endif