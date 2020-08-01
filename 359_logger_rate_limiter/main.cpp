/*
 * 359. Logger Rate Limiter
 *
 * Q: https://leetcode.com/problems/logger-rate-limiter/
 * A: https://leetcode.com/problems/logger-rate-limiter/discuss/473779/Javascript-Python3-C%2B%2B-hash-table
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Logger {
    using Map = unordered_map<string, int>;
    Map m;
public:
    bool shouldPrintMessage(int t, string s) {
        if (m.find(s) == m.end() || 10 <= t - m[s]) {
            m[s] = t;
            return true;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
