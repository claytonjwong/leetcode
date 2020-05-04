/*
 * 1436. Destination City
 *
 * Q: https://leetcode.com/problems/destination-city/
 * A: https://leetcode.com/problems/destination-city/discuss/611838/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VVS = vector<VS>;
    using Set = set<string>;
    string destCity(VVS& A, Set U = {}, Set V = {}, VS ans = {}) {
        for (auto& path: A) {
            auto [u, v] = tie(path[0], path[1]);
            U.insert(u);
            V.insert(v);
        }
        set_difference(V.begin(), V.end(),
                       U.begin(), U.end(), back_inserter(ans));
        return ans.back();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
