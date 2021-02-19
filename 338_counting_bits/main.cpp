/*
 * 338. Counting Bits
 *
 * Q: https://leetcode.com/problems/counting-bits/
 * A: https://leetcode.com/problems/counting-bits/discuss/657068/Kt-Js-Py3-Cpp-Dynamic-Programming
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI countBits(int N, VI ans = { 0 }) {
        for (auto i{ 1 }; i <= N; ++i)
            ans.push_back(ans[i >> 1] + (i & 1));
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
