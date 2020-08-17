/*
 * 1103. Distribute Candies to People
 *
 * Q: https://leetcode.com/problems/distribute-candies-to-people/
 * A: https://leetcode.com/problems/distribute-candies-to-people/discuss/323409/Javascript-Python3-C%2B%2B-Brute-Force
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector< int >;
    VI distributeCandies(int k, int N, int candy = 0){
        VI ans(N);
        while (k) {
            for (auto i{ 0 }; i < N; ++i) {
                auto take = min(++candy, k);  // ⭐️ take candy (not exceeding available k candies)
                ans[i] += take, k -= take;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    auto ans = solution.distributeCandies(7, 4);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
