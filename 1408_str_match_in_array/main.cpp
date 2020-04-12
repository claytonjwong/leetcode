/*
 * 1408. String Matching in an Array
 *
 * Q: https://leetcode.com/problems/string-matching-in-an-array/
 * A: https://leetcode.com/problems/string-matching-in-an-array/discuss/575927/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Set = unordered_set<string>;
    VS stringMatching(VS& words, Set ans = {}) {
        for (auto& word: words)
            for (auto& sub: words)
                if (word != sub && word.find(sub) != string::npos)
                    ans.insert(sub);
        return { ans.begin(), ans.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
