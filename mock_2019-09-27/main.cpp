/*

 Q1: https://leetcode.com/problems/license-key-formatting/
 A1: https://leetcode.com/problems/license-key-formatting/discuss/392002/C%2B%2B-Solution

 Q2: https://leetcode.com/problems/longest-absolute-file-path/
 A2:

 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        S.erase(remove(S.begin(), S.end(), '-'), S.end());
        transform(S.begin(), S.end(), S.begin(), ::toupper);
        ostringstream os;
        auto pos = static_cast<int>(S.size() % K);
        if (pos)
            os << S.substr(0, pos) << "-";
        for (auto i=pos; i+K <= S.size(); i+=K)
            os << S.substr(i, K) << "-";
        auto ans = os.str();
        ans.pop_back(); // remove trailing -
        return ans;
    }
};

int main() {

    Solution solution;
    cout << solution.licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl;
    cout << solution.licenseKeyFormatting("2-5g-3-J", 2) << endl;
    return 0;
}
