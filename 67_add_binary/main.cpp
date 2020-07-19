/*
 * 67. Add Binary
 *
 * Q: https://leetcode.com/problems/add-binary/
 * A: https://leetcode.com/problems/add-binary/discuss/744220/Javascript-Python3-C%2B%2B-accumulate-sum-a%2Bb%2Bc-in-reverse
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string A, string B, int c = 0, string ans = {}) { // ⭐️ c is the carry
        int M = A.size(),
            N = B.size();
        for (auto i{ M - 1 }, j{ N - 1 }; 0 <= i || 0 <= j; --i, --j) {
            auto a = 0 <= i ? A[i] - '0' : 0,
                 b = 0 <= j ? B[j] - '0' : 0;
            ans.push_back((a + b + c) % 2 + '0');
            c = 1 < a + b + c;
        }
        if (c)
            ans.push_back('1');
        return { ans.rbegin(), ans.rend() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
