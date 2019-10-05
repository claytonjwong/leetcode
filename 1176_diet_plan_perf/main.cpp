/*

1176. Diet Plan Performance

Q: https://leetcode.com/problems/diet-plan-performance/
A: https://leetcode.com/problems/diet-plan-performance/discuss/396500/Javascript-and-C%2B%2B-Solutions

*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int dietPlanPerformance(vector<int>& A, int k, int lower, int upper, int ans=0) {
        auto sum = accumulate(A.begin(), A.begin() + k, 0); // A[0] + ... + A[k-1]
        auto j = k-1;
        for(;;) {
            if (sum < lower) --ans;
            if (sum > upper) ++ans;
            if (++j >= A.size())
                break;
            sum -= A[j-k];
            sum += A[j];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> A{1,2,3,4,5};
    auto ans = solution.dietPlanPerformance(A, 1, 3, 3);
    cout << ans << endl;
    return 0;
}