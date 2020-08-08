/*
 * 1539. Kth Missing Positive Number
 *
 * Q: https://leetcode.com/problems/kth-missing-positive-number/
 * A: https://leetcode.com/problems/kth-missing-positive-number/discuss/780016/Javascript-Python3-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    int findKthPositive(VI& A, int K) {
        Set seen{ A.begin(), A.end() };
        for (auto i{ 1 };; ++i)
            if (seen.find(i) == seen.end() && !--K)
                return i;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
