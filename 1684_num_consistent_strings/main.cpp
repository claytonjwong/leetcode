/*
 * 1684. Count the Number of Consistent Strings
 *
 * Q: https://leetcode.com/problems/count-the-number-of-consistent-strings/
 * A: https://leetcode.com/problems/count-the-number-of-consistent-strings/discuss/969513/Kt-Js-Py3-Cpp-1-Liners
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Set = unordered_set<char>;
    using VS = vector<string>;
    int countConsistentStrings(string A, VS& words, int cnt = 0) {
        Set dict{ A.begin(), A.end() };
        for (auto& word: words)
            cnt += all_of(word.begin(), word.end(), [&](auto c) { return dict.find(c) != dict.end(); });
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
