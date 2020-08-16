/*
 * 884. Uncommon Words from Two Sentences
 *
 * Q: https://leetcode.com/problems/uncommon-words-from-two-sentences/
 * A: https://leetcode.com/problems/uncommon-words-from-two-sentences/discuss/159907/Javascript-Python3-C%2B%2B-Word-Counter
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Map = unordered_map<string, int>;
    VS uncommonFromSentences(string A, string B, Map m = {}, string word = {}, VS ans = {}) {
        istringstream isA{ A }; while (isA >> word) ++m[word];
        istringstream isB{ B }; while (isB >> word) ++m[word];
        for (auto [word, cnt]: m)
            if (cnt == 1)
                ans.push_back(word);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
