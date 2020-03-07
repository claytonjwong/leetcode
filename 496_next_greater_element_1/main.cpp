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
    VI nextGreaterElement(VI& A, VI& B, Map m = {}, VI ans = {}) {
        int N = B.size();
        if (N == 0)
            return {};
        for (auto i = 0; i + 1 < N; ++i) {
            auto j = i + 1;
            for (; j < N && B[i] > B[j]; ++j);
            if (j == N)
                m[B[i]] = -1;
            else
                m[B[i]] = B[j];
        }
        m[B.back()] = -1;
        transform(A.begin(), A.end(), back_inserter(ans), [&](auto x) { return m[x]; });
        return ans;
    }
};

// TODO: use a stack to generate the map more efficiently in O(N) time

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
