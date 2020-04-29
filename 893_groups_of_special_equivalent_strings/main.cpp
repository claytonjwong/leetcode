/*
 * 893. Groups of Special-Equivalent Strings
 *
 * Q: https://leetcode.com/problems/groups-of-special-equivalent-strings/
 * A: https://leetcode.com/problems/groups-of-special-equivalent-strings/discuss/601822/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Set = unordered_set<string>;
    int numSpecialEquivGroups(VS& A, Set group = {}) {
        auto key = [](auto& s) {
            string e, o; // even, odd
            for (auto i{ 0 }; i < s.size(); ++i)
                if (i % 2)
                    o.push_back(s[i]);
                else
                    e.push_back(s[i]);
            sort(e.begin(), e.end());
            sort(o.begin(), o.end());
            return e + o;
        };
        for_each(A.begin(), A.end(), [&](auto& s) { group.insert(key(s)); });
        return group.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
