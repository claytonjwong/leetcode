/*
 * 791. Custom Sort String
 *
 * Q2: https://leetcode.com/problems/custom-sort-string/
 * A2: https://leetcode.com/problems/custom-sort-string/discuss/542718/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    string customSortString(string S, string T, Map m = {}) {
        for (auto i = 0; i < S.size(); ++i)
            m[S[i]] = i;
        sort(T.begin(), T.end(), [&](auto a, auto b) {
            if (m.find(a) == m.end()) return false;
            if (m.find(b) == m.end()) return true;
            return m[a] < m[b];
        });
        return T;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
