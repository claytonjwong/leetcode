/*
 * 67. Add Binary
 *
 * Q: https://leetcode.com/problems/add-binary/
 * A: https://leetcode.com/problems/add-binary/discuss/606766/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string A, string B, int carry = 0, string ans = {}) {
        int M = A.size(),
            N = B.size();
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        for (auto i{ 0 }; i < max(A.size(), B.size()); ++i) {
            auto x = (i < M && A[i] == '1')
                   + (i < N && B[i] == '1')
                   + carry;
            ans.push_back((x & 1) + '0');
            carry = x > 1;
        }
        if (carry)
            ans.push_back('1');
        return { ans.rbegin(), ans.rend() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
