#include <iostream>
#include "spellcheck.hpp"

using namespace std;

int main() {
        wordTree wT;
        string input;
        while(true) {
                cout << "Check a word: " << flush;
                getline(cin, input);
                wT.check(input);
        }
}