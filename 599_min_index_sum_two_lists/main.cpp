/*
 * 599. Minimum Index Sum of Two Lists
 *
 * Q: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 * A: https://leetcode.com/problems/minimum-index-sum-of-two-lists/discuss/597138/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Map = unordered_map<string, int>;
    VS findRestaurant(VS& A, VS& B, Map m = {}, int min = 2001, VS ans = {}) {
        for (auto i{ 0 }; i < A.size(); ++i)
            m[A[i]] = i;
        for (auto j{ 0 }; j < B.size(); ++j) {
            auto x = B[j];
            if (m.find(x) == m.end())
                continue;
            auto i = m[x];
            if (min > i + j)
                min = i + j,
                ans.clear();
            if (min == i + j)
                ans.push_back(x);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
