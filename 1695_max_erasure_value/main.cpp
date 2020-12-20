/*
 * 1695. Maximum Erasure Value
 *
 * Q: https://leetcode.com/problems/maximum-erasure-value/
 * A: https://leetcode.com/problems/maximum-erasure-value/discuss/978556/Kt-Js-Py3-Cpp-Sliding-Window-%2B-Seen-Set
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    int maximumUniqueSubarray(VI& A, Set seen = {}, int total = 0, int best = 0) {
        int N = A.size(),
            i = 0,
            j = 0;
        while (j < N) {
            if (seen.find(A[j]) != seen.end())  // 👉 shrink window to maintain loop invariant A[i..j] 👀 uniquely seen
                total -= A[i],
                seen.erase(A[i++]);
            else                                // 👉 expand window
                total += A[j],
                seen.insert(A[j++]);
            best = max(best, total);            // 🎯 best total A[i..j]
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
