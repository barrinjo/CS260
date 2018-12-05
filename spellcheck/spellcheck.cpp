#include <iostream>
#include "spellcheck.hpp"

using namespace std;

int main() {
        wordTree w;
        string input;
        while(true) {
                cout << "Check a word: " << flush;
                getline(cin, input);
                w.check(input);
        }
}