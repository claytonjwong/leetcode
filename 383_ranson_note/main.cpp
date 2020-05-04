/*
 * 383. Ransom Note
 *
 * Q: https://leetcode.com/problems/ransom-note/
 * A: https://leetcode.com/problems/ransom-note/discuss/611792/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    bool canConstruct(string A, string B, Map need = {}, Map have = {}) {
        for (auto c: A) ++need[c];
        for (auto c: B) ++have[c];
        return all_of(A.begin(), A.end(), [&](auto c) { return need[c] <= have[c]; });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
