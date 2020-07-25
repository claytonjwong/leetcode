/*
 * 1525. Number of Good Ways to Split a String
 *
 * Q: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
 * A: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/discuss/754776/Javascript-Python3-C%2B%2B-count-uniques-from-leftright
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    struct Unique {
        Set L, R;
    };
    int numSplits(string s, Unique unique = {}, int cnt = 0) {
        int N = s.size(),
            beg = 0,
            end = N - 1;
        VI L(N),
           R(N);
        for (auto i{ beg }; i <  N; ++i) unique.L.insert(s[i]), L[i] = unique.L.size(); // unique counts from Left-to-right 👉
        for (auto j{ end }; 0 <= j; --j) unique.R.insert(s[j]), R[j] = unique.R.size(); // unique counts from Right-to-left 👈
        for (auto i{ 1 }; i < N; ++i)
            if (L[i - 1] == R[i])
                ++cnt;
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
