/*
 * 496. Next Greater Element I
 *
 * Q: https://leetcode.com/problems/next-greater-element-i/
 * A: https://leetcode.com/problems/next-greater-element-i/discuss/531111/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    VI nextGreaterElement(VI& A, VI& B, Map m = {}, VI s = {}, VI ans = {}) {
        int N = B.size();
        for (auto i = N - 1; i >= 0; --i) {
            while (!s.empty() && B[i] > s.back())
                s.pop_back();
            if (s.empty())
                m[B[i]] = -1;
            else
                m[B[i]] = s.back();
            s.push_back(B[i]);
        }
        transform(A.begin(), A.end(), back_inserter(ans), [&](auto x) { return m[x]; });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
