/*
 * 1213. Intersection of Three Sorted Arrays
 *
 * Q: https://leetcode.com/problems/intersection-of-three-sorted-arrays/
 * A: https://leetcode.com/problems/intersection-of-three-sorted-arrays/discuss/531099/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

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

class Solution {
public:
    using VI = vector<int>;
    VI arraysIntersection(VI& A, VI& B, VI& C, int i = 0, int j = 0, int k = 0, VI ans = {}) {
        while(i < A.size() && j < B.size() && k < C.size()) {
            auto max = std::max({A[i], B[j], C[k]});
            if (A[i] == max && B[j] == max && C[k] == max)
                ans.push_back(max),
                        ++i, ++j, ++k;
            while (i < A.size() && A[i] < max) ++i;
            while (j < B.size() && B[j] < max) ++j;
            while (k < C.size() && C[k] < max) ++k;
        }
        return ans;
    }
};

// TODO: use binary search to find the max in logarithmic time rather than linear time

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
