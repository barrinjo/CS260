#include <iostream>
#include "spellcheck.hpp"

using namespace std;

int main() {
        wordTree w;
        string input;
        cout << "Check a word: " << flush;
        getline(cin, input);
        for(int i = 0; i < 10; ++i)
                w.check(input);
}