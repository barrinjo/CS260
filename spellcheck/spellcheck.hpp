#ifndef SPELLCHECK_HPP
#define SPELLCHECK_HPP
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>

using namespace std;

class wordTree {
        struct node {
                int eDist;
                string word;
                node(): eDist(), word() {}
                node(int eDist, string word): eDist(eDist), word(word) {}
        };
        vector<string> dict;
        vector<node> stack;

        int parent(int i) {
                return (i-1)/2;
        }
        int left(int i) {
                return (i*2)+1;
        }
        int right(int i) {
                return (i*2)+2;
        }
        unsigned editDistance(string a, string b) {
                unsigned d[a.length() + 1][b.length() + 1];
                d[0][0] = 0;
                for(size_t i = 1; i <= a.length(); ++i)
                        d[i][0] = i;
                for(size_t j = 1; j <= b.length(); ++j)
                        d[0][j] = j;
                for(size_t i = 1; i <= a.length(); ++i) {
                        for(size_t j = 1; j <= b.length(); ++j) {
                                d[i][j] = min(min(
                                        d[i][j - 1] + 1,
                                        d[i-1][j] + 1), 
                                        d[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
                        }
                }
                return d[a.length()][b.length()];
        }
        void bubble(int i) { 
                if(stack[parent(i)].eDist > stack[i].eDist) {
                        node n = stack[parent(i)];
                        stack[parent(i)] = stack[i];
                        stack[i] = n;
                        bubble(parent(i));
                }
        }
        void add(node n) {
                stack.push_back(n);
                bubble(stack.size() - 1);
        }
        void fill(int i) {
                if(left(i) <= stack.size()) {
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
                ifstream infile("/usr/share/dict/words");
                string line;
                while(getline(infile, line)) {
                        dict.push_back(line);
                }
        }
        void check(string word) {
                unsigned l;
                for(string dictword: dict) {
                        if(word != dictword) {
                                l = editDistance(word, dictword);
                                add(node(l, dictword));
                        } else {
                                cout << "Good spelling." << endl;
                                stack.clear();
                                return;
                        }
                }
                cout << "Did you mean: " << flush;
                for(int i = 0; i < 5 && !stack.empty(); i++) {
                        cout << stack[0].word << ", " << flush;
                        fill(0);
                        //fill(0);
                }
                cout << endl;
                stack.clear();
        }
};

#endif