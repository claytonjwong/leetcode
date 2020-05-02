/*
 * 1426. Counting Elements
 *
 * Q: https://leetcode.com/problems/counting-elements/
 * A: https://leetcode.com/problems/counting-elements/discuss/567834/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

namespace Solution1 {
    class Solution {
    public:
        using VI = vector<int>;
        using Seen = unordered_set<int>;
        int countElements(VI& A) {
            Seen seen{ A.begin(), A.end() };
            return count_if(A.begin(), A.end(), [&](auto x) { return seen.find(x + 1) != seen.end(); });
        }
    };
}
namespace Solution2 {
    class Solution {
    public:
        using VI = vector<int>;
        using Seen = unordered_set<int>;
        int countElements(VI& A, Seen seen = {}, int ans = 0) {
            sort(A.rbegin(), A.rend());
            for (auto x: A)
                ans += int(seen.find(x + 1) != seen.end()),
                seen.insert(x);
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
