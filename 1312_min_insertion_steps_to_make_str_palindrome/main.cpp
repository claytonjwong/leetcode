/*
 * 1312. Minimum Insertion Steps to Make a String Palindrome
 *
 * Q: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 * A: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/discuss/472599/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

// TLE without memoization
/*
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        return go(s, 0, n - 1);
    }
private:
    int go(const string& s, int i, int j) {
        if (i >= j)
            return 0;
        if (s[i] == s[j])
            return go(s, i + 1, j - 1);
        return 1 + min(go(s, i + 1, j), go(s, i, j - 1));
    }
};
*/

/*
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        return go(s, 0, n - 1);
    }
private:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI memo = VVI(501, VI(501, -1));
    int go(const string& s, int i, int j) {
        if (memo[i][j] > -1)
            return memo[i][j];
        if (i >= j)
            return memo[i][j] = 0;
        if (s[i] == s[j])
            return memo[i][j] = go(s, i + 1, j - 1);
        return memo[i][j] = 1 + min(go(s, i + 1, j), go(s, i, j - 1));
    }
};
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        return go(s, 0, n - 1);
    }
private:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI m = VVI(501, VI(501, -1));
    int go(const string& s, int i, int j) {
        return m[i][j] =
            m[i][j] > -1 ? m[i][j] :
            i >= j ? 0 :
            s[i] == s[j] ? go(s, i + 1, j - 1) :
            1 + min(go(s, i + 1, j), go(s, i, j - 1));
    }
};

int main() {
    Solution solution;
    cout << solution.minInsertions("a") << endl;
    cout << solution.minInsertions("aba") << endl;
    cout << solution.minInsertions("ab") << endl;
    cout << solution.minInsertions("leetcode") << endl;
    cout << solution.minInsertions("bypqsvqpzruzlagimzxuejvxjrrzcsjakirmlsyqehmndhqgzqsogrtvzpnqbpmavcqtmmfesbfpnoyzrekvtwphdgwxoovpsxusfbxbofvzenivkududlgeiqjllvuavqcjupcdztdensvntciozyjfcxsqawbajtzjbkyoadjluayyaluscgopqnkzidyzwokryhcsjlhvyyxzghdrcjjfxyjdpfe") << endl;
    return 0;
}
