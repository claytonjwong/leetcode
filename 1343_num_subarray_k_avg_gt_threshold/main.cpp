/*
 * 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
 *
 * Q: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
 * A: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/discuss/507957/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    using VI = vector<int>;
//    int numOfSubarrays(VI& A, int K, int T, int ans = 0) {
//        int N = A.size();
//        VI S(N + 1);
//        for (auto i = 1; i <= N; ++i)
//            S[i] = S[i - 1] + A[i - 1];
//        for (auto i = 0, j = i + K; j <= N; ++i, ++j) {
//            auto sum = S[j] - S[i];
//            auto avg = sum / K;
//            if (avg >= T)
//                ++ans;
//        }
//        return ans;
//    }
//};

class Solution {
public:
    using VI = vector<int>;
    int numOfSubarrays(VI& A, int K, int T, int ans = 0) {
        int N = A.size();
        VI S(N + 1);
        for (auto i = 1; i <= N; ++i)
            S[i] = S[i - 1] + A[i - 1];
        for (auto i = 0, j = i + K; j <= N; ++i, ++j)
            if ((S[j] - S[i]) / K >= T)
                ++ans;
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VI A{4,4,4,4};
    auto K = 4, T = 1;
    cout << solution.numOfSubarrays(A, K, T) << endl;
    return 0;
}
