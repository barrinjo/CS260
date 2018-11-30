#ifndef SPELLCHECK_HPP
#define SPELLCHECK_HPP
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#define SIZE 10000

using namespace std;

class wordTree {
        struct node {
                int eDist;
                string word;
                node(): eDist(), word() {}
        };
        node dict[SIZE];
        node stack[SIZE];

        int parent(int i) {
                return (i-1)/2;
        }
        int left(int i) {
                return (i*2)+1;
        }
        int right(int i) {
                return (i*2)+2;
        }
        int editDistance(string string1, string string2, int m, int n) {
                if(m == 0)
                        return n;

                if(n == 0) return m;

                if(string1[m-1] == string2[n-1]) {
                        return editDistance(string1, string2, m-1, n-1);
                }

                return 1 + min (min(editDistance(string1, string2, m, n-1),
                                editDistance(string1, string2, m-1, n)),
                                editDistance(string1, string2, m-1, n-1)
                                );
        }
        void bubble(int i) { 
                if(stack[parent(i)].eDist > stack[i].eDist) {
                        node n = stack[parent(i)];
                        stack[parent(i)] = stack[i];
                        stack[i] = n;
                        bubble(parent(i));
                }
        }
        void add(int priority, string word) {
                for(int i = 0; i < SIZE; i++) {
                        if(!stack[i].eDist) {
                                stack[i].eDist = priority;
                                stack[i].word = word;
                                bubble(i);
                                break;
                        }
                }
        }
        void fill(int i) {
                if(left(i) < SIZE) {
                        if(stack[left(i)].eDist < stack[right(i)].eDist) {
                                stack[i] = stack[left(i)];
                                fill(left(i));
                        } else {
                                stack[i] = stack[right(i)];
                                fill(right(i));
                        }
                }
        }
public:
        wordTree(): dict(), stack() {
                ifstream infile("words");
                string line;
                int i = 0;
                while(getline(infile, line)) {
                        dict[i].word = line;
                        i++;
                }
        }
        void check(string word) {
                cout << "Did you mean: " << endl;
                int l;
                for(int i = 0; i < SIZE; i++) {
                        l = editDistance(word, dict[i].word, word.length(), dict[i].word.length());
                        if(l <= 3)
                                add(l, dict[i].word);
                }
                for(int i = 0; i < 5; i++) {
                        cout << stack[i].word << endl;
                        fill(i);
                }
                for(int i = 0; i < SIZE; i++) {
                        stack[i].eDist = {};
                        stack[i].eDist = {};
                }
        }
};

#endif