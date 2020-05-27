/*
 * Brute-Force: N nested for-loops
 */

#include <iostream>

using namespace std;

namespace Verbose {
    void go(int n, string s = {}) {
        if (!n) {
            cout << s << endl;
            return;
        }
        for (auto i{ 0 }; i < 10; ++i) {
            s.push_back('0' + i);
            go(n - 1, s);
            s.pop_back();
        }
    }
}

namespace Concise {
    void go(int n, string&& s = {}) {
        if (!n) {
            cout << s << endl;
            return;
        }
        for (auto i{ 0 }; i < 10; ++i)
            go(n - 1, s + to_string(i));
    }
}

int main() {
    Verbose::go(3);
    Concise::go(3);
    return 0;
}
