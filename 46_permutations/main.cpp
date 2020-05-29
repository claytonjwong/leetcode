/*
 * 46. Permutations
 *
 * Q: https://leetcode.com/problems/permutations/
 * A: https://leetcode.com/problems/permutations/discuss/657552/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI permute(VI& A, VVI ans = {}) {
        sort(A.begin(), A.end());
        do {
            ans.push_back({ A.begin(), A.end() });
        } while (next_permutation(A.begin(), A.end()));
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
