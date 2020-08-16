/*
 * 484. Find Permutation
 *
 * Q: https://leetcode.com/problems/find-permutation/
 * A: https://leetcode.com/problems/find-permutation/discuss/795156/Javascript-Python3-C%2B%2B-.-Greedy-Mountain
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI findPermutation(string t, VI s = {}, VI ans = {}) {
        t.push_back('I');                               // 🛑 sentinel value to exhaust last downslope xor append max value last
        for (auto i{ 0 }; i < t.size(); ++i) {
            s.push_back(i + 1);                         // +1 for 1-based indexing
            while (t[i] == 'I' && s.size())
                ans.push_back(s.back()), s.pop_back();  // 💥 greedily consume current upslope xor exhaust pending downslope
        }
        return ans;
    }
};

int main() {
    Solution solution;
    auto ans = solution.findPermutation("D");
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
