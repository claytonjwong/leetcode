#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*

 Top-Down:

 assume we know the answer to the prefix of A and B except for the last characters in A and B
 then recursively consider the last chars of A and B

     * take "as is" -> either match or mismatch
     * take from A and skip B
     * take from B and skip A

 let i be the ending index of the substring in A under consideration
 let j      "     "    "     "      "      "   B   "        "

 base case occurs when i == 0 or j == 0, the return value is the remaining substring length

 */

namespace TopDown {
    class Solution {
    public:
        int editDistance(const string& A, const string& B) {
            return go(A, B, A.size(), B.size());
        }
    private:
        int go(const string& A, const string& B, int i, int j) {
            if (i == 0) return j;
            if (j == 0) return i;
            return min({
                go(A, B, i - 1, j - 1) + int(A[i - 1] != B[j - 1]),
                go(A, B, i, j - 1) + 1,
                go(A, B, i - 1, j) + 1,
            });
        }
    };
}

namespace TopDownMemo {
    class Solution {
    public:
        int editDistance(const string& A, const string& B) {
            int m = A.size(),
                n = B.size();
            return go(A, B, m, n);
        }
    private:
        using Memo = unordered_map<string, int>;
        int go(const string& A, const string& B, int i, int j, Memo&& memo={}) {
            auto key = hash(i, j);
            if (memo.find(key) != memo.end())
                return memo[key];
            if (i == 0) return memo[key] = j;
            if (j == 0) return memo[key] = i;
            return memo[key] = min({
                go(A, B, i-1, j-1, move(memo)) + int(A[i-1] != B[j-1]),
                go(A, B, i, j-1, move(memo)) + 1,
                go(A, B, i-1, j, move(memo)) + 1,
            });
        }
        string hash(int i, int j, ostringstream os=ostringstream()) {
            os << i << "," << j;
            return os.str();
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int editDistance(const string& A, const string& B) {
            int m = A.size(),
                n = B.size();
            VVI dp(m+1, VI(n+1));
            for (auto i=1; i <= m; ++i) dp[i][0] = i;
            for (auto j=1; j <= n; ++j) dp[0][j] = j;
            for (auto i=1; i <= m; ++i)
                for (auto j=1; j <= n; ++j)
                    dp[i][j] = min({
                        dp[i-1][j-1] + int(A[i-1] != B[j-1]),
                        dp[i][j-1] + 1,
                        dp[i-1][j] + 1,
                    });
            return dp[m][n];
        }
    };
}


int main() {
    string A{"shakespearean"},
           B{"shakespeople"};
    cout << BottomUp::Solution().editDistance(A, B) << endl;
    cout << TopDownMemo::Solution().editDistance(A, B) << endl;
    cout << TopDown::Solution().editDistance(A, B) << endl; // slow!
    return 0;
}
