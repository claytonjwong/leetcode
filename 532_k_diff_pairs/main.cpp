/*
 * 532. K-diff Pairs in an Array
 *
 * Q: https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * A: https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/596830/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    using Set = unordered_set<int>;
    int findPairs(VI& A, int K, Map m = {}, Set seen = {}) {
        sort(A.begin(), A.end());
        return count_if(A.begin(), A.end(), [&](auto x) {
            if (!K)
                return ++m[x] == 2;
            else
                return seen.insert(x).second && seen.find(x - K) != seen.end();
        });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
