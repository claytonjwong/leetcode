/*
 * 246. Strobogrammatic Number
 *
 * Q: https://leetcode.com/problems/strobogrammatic-number/
 * A: https://leetcode.com/problems/strobogrammatic-number/discuss/590845/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool isStrobogrammatic(string s, VI A = {}) {
        auto rotate = [](auto x) {
            switch (x) {
                case 0: return 0;
                case 1: return 1;
                case 6: return 9;
                case 8: return 8;
                case 9: return 6;
            }
            return -1;
        };
        transform(s.begin(), s.end(), back_inserter(A), [](auto c) { return c - '0'; });
        int N = A.size();
        for (auto i{ 0 }, j{ N - 1 }; i <= j; ++i, --j)
            if (rotate(A[i]) != A[j])
                return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
