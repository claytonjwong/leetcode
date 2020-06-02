/*
 * 683. K Empty Slots
 *
 * Q: https://leetcode.com/problems/k-empty-slots/
 * A: https://leetcode.com/problems/k-empty-slots/discuss/666536/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = set<int>;
    int kEmptySlots(VI& A, int T, Set S = {}) {
        for (auto day{ 1 }; day <= A.size(); ++day) {
            auto it = S.insert(A[day - 1]).first; // -1 for 0-based indexing
            auto L = it == S.begin() ? it : prev(it), // left
                 R = it == S.end()   ? it : next(it); // right
            if (*it - *L == T + 1 || *R - *it == T + 1) // +1 for i..j inclusive
                return day;
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
