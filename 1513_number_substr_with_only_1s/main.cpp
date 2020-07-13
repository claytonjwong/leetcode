/*
 * 1513. Number of Substrings With Only 1s
 *
 * Q: https://leetcode.com/problems/number-of-substrings-with-only-1s/
 * A: https://leetcode.com/problems/number-of-substrings-with-only-1s/discuss/731600/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using LL = long long;
    using VLL = vector<LL>;
    int numSub(string s, int len = 0, VLL run = {}, int cnt = 0) {
        auto sum = [](auto n) { return (n * (n + 1)) / 2; };
        s.push_back('0'); // sentinel value to terminate the last run (if it exists)
        for (auto c: s)
            if (c == '1') ++len; else run.push_back(len), len = 0;
        for (auto len: run)
            cnt = (cnt + sum(len)) % LL(1e9 + 7);
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
