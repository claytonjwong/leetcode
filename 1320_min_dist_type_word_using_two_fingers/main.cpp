/*
 * 1320. Minimum Distance to Type a Word Using Two Fingers
 *
 * Q: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
 * A: https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/discuss/488589/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

/*
class Solution {
public:
    int minimumDistance(string word) {
        return go(word);
    }
private:
    static constexpr char INF = -1;
    int cost(char beg, char end) {
        if (beg == INF) // first time finger used
            return 0;
        auto a = beg - 'A', // offset 'A' to 0
             b = end - 'A';
        return abs((a / 6) - (b / 6)) + abs((a % 6) - (b % 6));
    }
    int go(string& s, int i = 0, char one = INF, char two = INF) {
        if (i == s.size())
            return 0;
        return min(
            cost(one, s[i]) + go(s, i + 1, s[i], two),
            cost(two, s[i]) + go(s, i + 1, one, s[i])
        );
    }
};
*/

class Solution {
public:
    int minimumDistance(string word) {
        return go(word);
    }
private:
    static constexpr char INF = -1;
    int cost(char beg, char end) {
        if (beg == INF) // first time finger used
            return 0;
        auto a = beg - 'A', // offset 'A' to 0
             b = end - 'A';
        return abs((a / 6) - (b / 6)) + abs((a % 6) - (b % 6));
    }
    using Memo = unordered_map<string, int>;
    int go(string& s, int i = 0, char one = INF, char two = INF, Memo&& memo = {}) {
        if (i == s.size())
            return 0;
        stringstream key; key << i << "," << one << "," << two;
        if (memo.find(key.str()) != memo.end())
            return memo[key.str()];
        return memo[key.str()] = min(
            cost(one, s[i]) + go(s, i + 1, s[i], two, move(memo)),
            cost(two, s[i]) + go(s, i + 1, one, s[i], move(memo))
        );
    }
};


int main() {
    cout << Solution().minimumDistance("CAKE") << endl;
    cout << Solution().minimumDistance("HAPPY") << endl;
    return 0;
}
