/*
 * 1370. Increasing Decreasing String
 *
 * Q: https://leetcode.com/problems/increasing-decreasing-string/
 * A: https://leetcode.com/problems/increasing-decreasing-string/discuss/535626/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    using Map = map<char, int>;
    string sortString(string s, Map m = {}, string ans = {}) {
        for (auto c: s)
            ++m[c];
        auto L = [&](string res = {}) { // forwards from (L)eft-to-right 👉
            for (auto it = m.begin(); it != m.end(); ++it)
                if (it->second)
                    res.push_back(it->first), --it->second;
            return res;
        };
        auto R = [&](string res = {}) { // backwards from 👈 (R)ight-to-left
            for (auto it = m.rbegin(); it != m.rend(); ++it)
                if (it->second)
                    res.push_back(it->first), --it->second;
            return res;
        };
        for (auto turn = 1;; turn ^= 1) {
            string next = turn ? L() : R();
            if (next.empty())
                break;
            ans.append(next);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
