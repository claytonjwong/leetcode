/*
 * https://leetcode.com/contest/weekly-contest-152/
 *
 * Rank	        Name	                Score	Finish Time 	Q1 (3)	    Q2 (4)	    Q3 (5)	        Q4 (6)
 * 798 / 3969	claytonjwong (Virtual)	8	    1:05:24	        1:00:24		            0:59:10  *1
 *
 * Q1: https://leetcode.com/contest/weekly-contest-152/problems/prime-arrangements/
 * A1: https://leetcode.com/problems/prime-arrangements/discuss/376190/C%2B%2B-Solution-with-Explanation
 *
 * Q3: https://leetcode.com/problems/can-make-palindrome-from-substring/
 * A3: https://leetcode.com/problems/can-make-palindrome-from-substring/discuss/376184/C%2B%2B-Solution-with-Detailed-Explanation
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

/*
class Solution {
public:
    constexpr static auto MOD = static_cast<int>(1e9+7);
    int numPrimeArrangements(int n, int primes=1, long long ans=1) { // 2 if the first prime
        for (auto i=3; i <= n; ++i) {
            if (isPrime(i)) {
                ++primes;
            }
        }
        for (auto i=1; i <= primes; ++i) { // all permutations of primes == factorial of primes
            ans = ans * i % MOD;
        }
        for (auto i=1; i <= n - primes; ++i) { // all permutations of non-primes == factorial of non-primes
            ans = ans * i % MOD;
        }
        return ans;
    }
private:
    bool isPrime(int n) {
        for (auto i=2; i*i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.numPrimeArrangements(5) << endl;
    cout << solution.numPrimeArrangements(100) << endl;

    return 0;
}
*/


// TLE
//class Solution {
//public:
//    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries, vector<bool> ans={}) {
//        for (auto query: queries) {
//            auto L = query[0],
//                 R = query[1],
//                K = query[2];
//            unordered_map<char, int> cnt;
//            for (auto i=L; i <= R; ++i) {
//                ++cnt[s[i]];
//            }
//            auto odd = 0;
//            for (auto& pair: cnt) {
//                if (pair.second % 2) {
//                    ++odd;
//                }
//            }
//            ans.push_back(odd / 2 <= K);
//        }
//        return ans;
//    }
//};

//class Solution {
//public:
//    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries, vector<bool> ans={}) {
//        vector<vector<int>> cnt(s.size()+1, vector<int>(123, 0));
//        for (auto i=1; i <= s.size(); ++i) {
//            cnt[i][s[i-1]] = 1;
//            for (auto j=97; j < 123; ++j) {
//                cnt[i][j] += cnt[i-1][j];
//            }
//        }
//        for (auto query: queries) {
//            auto L = query[0],
//                 R = query[1],
//                 K = query[2];
//            vector<int> diff(123, 0);
//            for (auto j=97; j < 123; ++j) {
//                diff[j] = cnt[R + 1][j] - cnt[L + 1][j];
//            }
//            ++diff[s[L]]; // left-inclusive
//            auto odd = 0;
//            for (auto j=97; j < 123; ++j) {
//                if (diff[j] % 2) {
//                    ++odd;
//                }
//            }
//            ans.push_back(odd / 2 <= K);
//        }
//        return ans;
//    }
//};

class Solution {
public:
    using Answer = vector<bool>;
    using VI = vector<int>;
    using VVI = vector<VI>;
    Answer canMakePaliQueries(string s, VVI& queries, Answer ans={}) {
        VVI cnt(1, VI(123, 0));
        for (auto i=1; i <= s.size(); ++i) {
            cnt.push_back(cnt.back());
            ++cnt[i][s[i-1]];
        }
        for (auto q: queries) {
            auto [L, R, K] = tie(q[0], q[1], q[2]);
            auto odd = 0;
            for (auto j=97; j < 123; ++j) {
                odd += (cnt[R + 1][j] - cnt[L][j]) % 2; // # odd chars in s from L to R inclusive ( in order for L to be inclusive, do NOT add 1 onto L )
            }
            ans.push_back(odd / 2 <= K);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> queries {
        {3, 3, 0},
        {1, 2, 0},
        {0, 3, 1},
        {0, 3, 2},
        {0, 4, 1},
    };
    Solution solution;
    auto ans = solution.canMakePaliQueries("abcda", queries);
    copy(ans.begin(), ans.end(), ostream_iterator<bool>(cout, " ")); cout << endl;
    return 0;
}
