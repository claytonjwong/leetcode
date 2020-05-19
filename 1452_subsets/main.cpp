/*
 * 1452. People Whose List of Favorite Companies Is Not a Subset of Another List
 *
 * Q: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
 * A: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/discuss/640681/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VS = vector<string>;
    using VVS = vector<VS>;
    using Map = unordered_map<int, set<string>>;
    VI peopleIndexes(VVS& A, Map m = {}, VI ans = {}) {
        for_each(A.begin(), A.end(), [i = -1, &m](auto& row) mutable { ++i; m[i] = set<string>{ row.begin(), row.end() }; });
        auto isSubset = [&](auto i, auto j) {
            if (i == j)
                return false;
            VS same;
            set_intersection(m[i].begin(), m[i].end(), m[j].begin(), m[j].end(), back_inserter(same));
            return m[i].size() == same.size();
        };
        auto N = A.size();
        for (auto i{ 0 }; i < N; ++i) {
            auto ok = true;
            for (auto j{ 0 }; j < N; ++j) {
                if (isSubset(i, j)) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
