/*
 * 1213. Intersection of Three Sorted Arrays
 *
 * Q: https://leetcode.com/problems/intersection-of-three-sorted-arrays/
 * A: https://leetcode.com/problems/intersection-of-three-sorted-arrays/discuss/531099/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// class Solution {
// public:
//     using VI = vector<int>;
//     VI arraysIntersection(VI& A, VI& B, VI& C, VI D = {}, VI E = {}) {
//         set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(D));
//         set_intersection(C.begin(), C.end(), D.begin(), D.end(), back_inserter(E));
//         return E;
//     }
// };

//class Solution {
//public:
//    using VI = vector<int>;
//    VI arraysIntersection(VI& A, VI& B, VI& C, int i = 0, int j = 0, int k = 0, VI ans = {}) {
//        while(i < A.size() && j < B.size() && k < C.size()) {
//            auto max = std::max({A[i], B[j], C[k]});
//            if (A[i] == max && B[j] == max && C[k] == max)
//                ans.push_back(max),
//                ++i, ++j, ++k;
//            while (i < A.size() && A[i] < max) ++i;
//            while (j < B.size() && B[j] < max) ++j;
//            while (k < C.size() && C[k] < max) ++k;
//        }
//        return ans;
//    }
//};

// TODO: use binary search to find the max in logarithmic time rather than linear time

// class Solution {
// public:
//     using VI = vector<int>;
//     VI arraysIntersection(VI& A, VI& B, VI& C, VI D = {}, VI E = {}) {
//         set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(D));
//         set_intersection(C.begin(), C.end(), D.begin(), D.end(), back_inserter(E));
//         return E;
//     }
// };

// [1,2,3,4,5]
// 0 1 2 3 4 5
// i   k   j
//     i k j
//.        i

// [1,2,5,7,9]
//. 0 1 2 3 4 5
//. i   k   j

// [1,3,4,5,8]
//. i   k   j
//.     i k j

class Solution {
public:
    using VI = vector<int>;
    VI arraysIntersection(VI& A, VI& B, VI& C, int i = 0, int j = 0, int k = 0, VI ans = {}) {
        auto search = [&](VI& A, int start, int target) {
            int i = start, j = static_cast<int>(A.size()) - 1, ans = start;
            while (i <= j) {
                auto k = (i + j) / 2;
                if (target == A[k])
                    return k;
                else if (target < A[k])
                    j = k - 1;
                else
                    i = ans = k + 1;
            }
            return ans;
        };
        while(i < A.size() && j < B.size() && k < C.size()) {
            auto max = std::max({A[i], B[j], C[k]});
            if (A[i] == max && B[j] == max && C[k] == max)
                ans.push_back(max),
                ++i, ++j, ++k;
            i = search(A, i, max);
            j = search(B, j, max);
            k = search(C, k, max);
        }
        return ans;
    }
};

int main() {
    Solution::VI A{1,2,3,4,5}, B{1,2,5,7,9}, C{1,3,4,5,8};
    Solution solution;
    auto ans = solution.arraysIntersection(A, B, C);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
