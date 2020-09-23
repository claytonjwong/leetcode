/*
 * 229. Majority Element II
 *
 * Q: https://leetcode.com/problems/majority-element-ii/
 * A: https://leetcode.com/problems/majority-element-ii/discuss/859901/Javascript-Python3-C%2B%2B-Naive-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    VI majorityElement(VI& A, Map m = {}, VI ans = {}) {
        int N = A.size();
        for (auto x: A) ++m[x];
        for (auto [x, cnt]: m)
            if (N / 3 < cnt)
                ans.push_back(x);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
