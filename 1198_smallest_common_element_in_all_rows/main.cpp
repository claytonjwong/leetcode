/*

 1198. Find Smallest Common Element in All Rows

 Q: https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
 A: https://leetcode.com/problems/find-smallest-common-element-in-all-rows/discuss/391150/Javascript-and-C%2B%2B-solutions

 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//class Solution {
//public:
//    using VI = vector<int>;
//    using VVI = vector<VI>;
//    int smallestCommonElement(VVI& A, VI cnt=VI(1e4+1)) {
//        auto M = static_cast<int>(A.size()),
//             N = static_cast<int>(A.back().size());
//        for (auto j=0; j < N; ++j) {
//            auto maxi = 0;
//            for (auto i=0; i < M; ++i) {
//                maxi = max(maxi, A[i][j]);
//                if (++cnt[A[i][j]] == M)
//                    return A[i][j];
//            }
//        }
//        return -1;
//    }
//};

// class Solution {
// public:
//     using VI = vector<int>;
//     using VVI = vector<VI>;
//     int smallestCommonElement(VVI& A, VI cnt=VI(1e4+1)) {
//         for (auto& row: A)
//             for (auto num: row)
//                 if (++cnt[num] == A.size())
//                     return num;
//         return -1;
//     }
// };

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Set = unordered_set<int>;
    using VSI = vector<Set>;
    int smallestCommonElement(VVI& A, VSI lookup={}) {
        for (auto& row: A)
            lookup.emplace_back(Set{row.begin(), row.end()});
        for (auto num: A.back()) {
            bool match = true;
            for (auto& row: lookup) {
                if (row.find(num) == row.end()) {
                    match = false;
                    break;
                }
            }
            if (match)
                return num;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    Solution::VVI A{
        {1,2,3,4,5},
        {2,4,5,8,10},
        {3,5,7,9,11},
        {1,3,5,7,9},
    };
    auto ans = solution.smallestCommonElement(A);
    cout << ans << endl;
    return 0;
}