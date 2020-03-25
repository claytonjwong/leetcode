/*
 * 953. Verifying an Alien Dictionary
 *
 * Q: https://leetcode.com/problems/verifying-an-alien-dictionary/
 * A: https://leetcode.com/problems/verifying-an-alien-dictionary/discuss/550428/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order, unordered_map<char, int> m = {}) {
        for (auto i{ 0 }; i < order.size(); ++i)
            m[order[i]] = i;
        auto sorted{ words };
        sort(sorted.begin(), sorted.end(), [&](auto& a, auto& b) {
            for (auto i{ 0 }; i < min(a.size(), b.size()); ++i)
                if (a[i] != b[i])
                    return m[a[i]] < m[b[i]];
            return a.size() < b.size();
        });
        for (auto i{ 0 }; i < sorted.size(); ++i)
            if (sorted[i] != words[i])
                return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
