/*
 * 506. Relative Ranks
 *
 * Q: https://leetcode.com/problems/relative-ranks/
 * A: https://leetcode.com/problems/relative-ranks/discuss/595725/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VS = vector<string>;
    using Map = map<int, int>;
    VS findRelativeRanks(VI& A, Map m = {}, int rank = 0, VS ans = {}) {
        for (auto i{ 0 }; i < A.size(); ++i)
            m[A[i]] = i;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            auto i = it->second;
            A[i] = ++rank;
        }
        transform(A.begin(), A.end(), back_inserter(ans), [](int x) -> string {
            switch (x) {
                case 1: return "Gold Medal";
                case 2: return "Silver Medal";
                case 3: return "Bronze Medal";
                default: return to_string(x);
            }
        });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
