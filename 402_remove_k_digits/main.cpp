/*
 * 402. Remove K Digits
 *
 * Q: https://leetcode.com/problems/remove-k-digits/
 * A: https://leetcode.com/problems/remove-k-digits/discuss/630343/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int K, string S = {}) {
        for (auto x: num) {
            while (K && !S.empty() && x < S.back())
                S.pop_back(), --K; // greedily remove up to K values greater-than x from the stack
            S.push_back(x);
        }
        auto beg = S.find_first_not_of('0'), // begin at first non-zero index
             end = S.size() - K;                // end before remaining K
        return S.empty() || beg == string::npos || beg == end ? "0" : S.substr(beg, beg + end);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
