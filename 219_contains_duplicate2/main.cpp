/*
 * 219. Contains Duplicate II
 *
 * Q: https://leetcode.com/problems/contains-duplicate-ii/
 * A: https://leetcode.com/problems/contains-duplicate-ii/discuss/825078/Javascript-Python3-C%2B%2B-Sliding-Window-Seen-Set
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    bool containsNearbyDuplicate(VI& A, int K, Set S = {}) {
        for (auto i{ 0 }; i < A.size(); ++i) {
            if (!S.insert(A[i]).second)   // 🎯 duplicate in window XOR ✅ add value in window
                return true;
            if (0 <= i - K)
                S.erase(A[i - K]);        // 🚫 delete value which "fell off the end" as the window slides 👉
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
