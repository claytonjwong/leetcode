/*
 * 392. Is Subsequence
 *
 * Q: https://leetcode.com/problems/is-subsequence/
 * A: https://leetcode.com/problems/is-subsequence/discuss/473784/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t, int i = 0) {
        for (auto j{ 0 }; i < s.size() && j < t.size(); ++j)
            if (s[i] == t[j])
                ++i;
        return i == s.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
