/*

1165. Single-Row Keyboard

Q: https://leetcode.com/problems/single-row-keyboard/
A: https://leetcode.com/problems/single-row-keyboard/discuss/397002/Javascript-and-C%2B%2B-Solutions

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word, unordered_map<char,int> m={}) {
        for (auto i=0; i < keyboard.size(); m[keyboard[i]]=i, ++i);
        auto ans = m[word[0]];
        for (auto i=1; i < word.size(); ++i)
            ans += abs(m[word[i-1]] - m[word[i]]);
        return ans;
    }
};

int main() {
    Solution solution;
    auto ans = solution.calculateTime("abcdefghijklmnopqrstuvwxyz", "cba");
    cout << ans << endl;
    return 0;
}
