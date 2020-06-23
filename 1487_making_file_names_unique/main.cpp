/*
 * 1487. Making File Names Unique
 *
 * Q: https://leetcode.com/problems/making-file-names-unique/
 * A: https://leetcode.com/problems/making-file-names-unique/discuss/702044/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Set = unordered_set<string>;
    VS getFolderNames(VS& A, Set seen = {}, VS ans = {}) {
        for (auto& s: A) {
            auto cand{ s };
            auto cnt{ 0 };
            while (seen.find(cand) != seen.end())
                cand = s + "(" + to_string(++cnt) + ")";
            ans.push_back(cand);
            seen.insert(cand);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
