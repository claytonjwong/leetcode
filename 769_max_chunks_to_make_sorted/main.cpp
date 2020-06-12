/*
 * 769. Max Chunks To Make Sorted
 *
 * Q: https://leetcode.com/problems/max-chunks-to-make-sorted/
 * A: https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/682554/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    int maxChunksToSorted(VI& A, Set seen = {}, int cnt = 0) {
        int i = 0,
                j = 0,
                N = A.size();
        while (i < N && j < N) {
            while (seen.find(i) == seen.end())
                seen.insert(A[j++]);
            while (seen.find(i) != seen.end())
                ++i;
            cnt += i == j;
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
