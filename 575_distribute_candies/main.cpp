/*
 * 575. Distribute Candies
 *
 * Q: https://leetcode.com/problems/distribute-candies/
 * A: https://leetcode.com/problems/distribute-candies/discuss/668969/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>;

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    int distributeCandies(VI& A) {
        Set S{ A.begin(), A.end() };
        return min(S.size(), A.size() / 2);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
