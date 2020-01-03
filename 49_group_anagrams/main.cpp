/*
 * 49. Group Anagrams
 *
 * Q: https://leetcode.com/problems/group-anagrams/
 * A: https://leetcode.com/problems/group-anagrams/discuss/468575/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VVS = vector<VS>;
    using Map = unordered_map<string, VS>;
    VVS groupAnagrams(VS& A, Map m = {}, VVS ans = {}) {
        for (auto& word: A) {
            auto key{word};
            sort(key.begin(), key.end());
            m[key].push_back(word);
        }
        transform(m.begin(), m.end(), back_inserter(ans), [](auto& pair) { return pair.second; });
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VS A{"abc", "cba", "def"};
    auto ans = solution.groupAnagrams(A);
    for (auto& bucket: ans)
        copy(bucket.begin(), bucket.end(), ostream_iterator<string>(cout, " ")), cout << endl;
    return 0;
}
