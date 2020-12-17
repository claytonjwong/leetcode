/*
 * 454. 4Sum II
 *
 * Q: https://leetcode.com/problems/4sum-ii/
 * A: https://leetcode.com/problems/4sum-ii/discuss/975519/Kt-Js-Py3-Cpp-Map
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int fourSumCount(VI& A, VI& B, VI& C, VI& D, Map m = {}, int cnt = 0) {
        for (auto a: A)
            for (auto b: B)
                ++m[a + b];
        for (auto c: C)
            for (auto d: D)
                if (m.find(-(c + d)) != m.end())
                    cnt += m[-(c + d)];
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
