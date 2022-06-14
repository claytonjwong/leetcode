/*
 * 2306. Naming a Company
 *
 * https://leetcode.com/problems/naming-a-company/
 */

/*

"game plan" -- reverse each string of the input array `A` and place into a trie:

A = ["coffee","donuts","time","toffee"]

               _
             /   \
            e     s
           / \     \
          e   m     t
         /     \     \
        f       i     u
       /         \     \
      f           t     n
     /                   \
    o                     o
   / \                     \
  c   t                     d

toffee <--> donuts   2x, ie. bi-directional
coffee <--> donuts   2x, ie. bi-directional
time <--> donuts     2x, ie. bi-directional

so for each set of leaf nodes, create unique combos

{c, t}     ->     {c, d}, {t, d}

{t}        ->     {t, d}

{d}        ->     {c, d}, {t, d}, {t, d}

and we can use rule-of-product to count those to avoid TLE, given N = 50,000


question: why do we need a trie?

just use a map, ie. the key would be the reversed suffix not including the last character
the value would be that last character inclusive-or'ed as a bitmask for quadratic i,j pair diffs

                          bitmask representation of a..z inclusive as bits 0..25 inclusive
                          vvvvvvvvvvvvvvvvvvvvvvvvvv
                          abcdefghijklmnopqrstuvwxyz
"coffee" -> m["eeffo"] -> 00100000000000000000000000
"toffee" -> m["eeffo"] -> 00100000000000000001000000

etc.

then we can bitwise AND each set to ensure they are mutually exclusive,
and accumulate the bits to multiply each i,j pair to accumulate the answer via rule-of-product

*/


// class Solution {
// public:
//     using LL = long long;
//     using VS = vector<string>;
//     using Map = unordered_map<string, int>;
//     LL distinctNames(VS& A, Map m = {}, LL cnt = 0) {
//         for (auto& s: A) {
//             string t{ s.rbegin(), s.rend() };
//             auto k = t.size() - 1;
//             m[t.substr(0, k)] |= (1 << t[k] - 'a');
//         }
//         for (auto [s, x]: m) {
//             for (auto [t, y]: m) {
//                 if (s == t || x & y)
//                     continue;
//                 cnt += __builtin_popcount(x) * __builtin_popcount(y);
//             }
//         }
//         return cnt;
//     }
// };

/*

well something's not quite right here...

Submission Detail
34 / 89 test cases passed.

Status: Wrong Answer

Submitted: 0 minutes ago

Input:
["aaa","baa","caa","bbb","cbb","dbb"]

Output:
0

Expected:
2

m["aa"] -> a,b,c

m["bb"] -> b,c,d

oops, ok so its the bitwise difference, we can xor them, then take out the same bits in common

*/

// class Solution {
// public:
//     using LL = long long;
//     using VS = vector<string>;
//     using Map = unordered_map<string, int>;
//     LL distinctNames(VS& A, Map m = {}, LL cnt = 0) {
//         for (auto& s: A) {
//             string t{ s.rbegin(), s.rend() };
//             auto k = t.size() - 1;
//             m[t.substr(0, k)] |= (1 << t[k] - 'a');
//         }
//         for (auto& [s, x]: m) {
//             for (auto& [t, y]: m) {
//                 if (s != t && (x ^ y)) {
//                     auto same = x & y;
//                     cnt += __builtin_popcount(x ^ same) * __builtin_popcount(y ^ same);
//                 }
//             }
//         }
//         return cnt;
//     }
// };

/*

well quadratic i,j considerations results in TLE 💩

Submission Detail
76 / 89 test cases passed.
Status: Time Limit Exceeded
Submitted: 0 minutes ago

*/

// 3:23pm - 3:46pm => ~23 minutes for implementation which was wrong, then I fixed and is AC now, yay! 🥳🥳🥳
/*

think inversion?  since there's only 26 characters in the English Latin alphabet,
maybe we can just swap the key/value?  I think that's the same with less keys and more values

well something's not quite right... 💩💩💩

35 / 89 test cases passed.
Status: Wrong Answer
Submitted: 0 minutes ago
Input:
["sfuzder","spklurny","kvdolme","kbbdklkpgk","za","mdbsmnjiu","pzydbfwiw","lvvyshmd","ow","ssipb","jucpsquexm","ffuzder","uftruik","ringlxh","jz","sjlxouiv","csdbtsvg","openygbaix","dcn","r","hwql","ok","y","sze","ttptd","atxp","ejfpsea","vjfpsea","lj","drmvufbt","zxambug","ozpxq","qzydbfwiw","lqxik","bjo","rrmvufbt","jvl","rzxaaa","nmfydhawa","shlwkf","rcl","hhn","yrmcsc","yieuzizaeh","nrmvufbt","rinsldgdpp","wqg","tyhkgqcu","rsdbtsvg","zvehtqiqxa","jtz","mjaguebiy","fztbpozhf","zzpxq","ue","foktqxiqe","ztf","dn","lxambug","kinsldgdpp","jhn","k","i","qxtava","roktqxiqe","hr","bwzw","mot","cadj","x","bcep","u","kzydbfwiw","ahku","ijo"]
Output:
4588
Expected:
4934

*/

// class Solution {
// public:
//     using LL = long long;
//     using VS = vector<string>;
//     using Set = unordered_set<string>;
//     using Map = unordered_map<char, Set>;
//     LL distinctNames(VS& A, Map m = {}, LL cnt = 0) {
//         for (auto& s: A)
//             m[s[0]].insert(s.substr(1));
//         for (auto i{ 'a' }; i <= 'z'; ++i)
//             for (auto j{ i + 1 }; j <= 'z'; ++j)
//                 cnt += all_of(m[i].begin(), m[i].end(), [&](auto& s) {
//                     return all_of(m[j].begin(), m[j].end(), [&](auto& t) { return s != t; });
//                 }) ? m[i].size() * m[j].size() : 0;
//         return 2 * cnt;
//     }
// };

// what would coach do?... think inversion...

class Solution {
public:
    using LL = long long;
    using VS = vector<string>;
    using Set = set<string>;
    using Map = unordered_map<char, Set>;
    LL distinctNames(VS& A, Map m = {}, LL cnt = 0) {
        for (auto& s: A)
            m[s[0]].insert(s.substr(1));
        for (auto i{ 'a' }; i <= 'z'; ++i) {
            for (auto j{ i + 1 }; j <= 'z'; ++j) {
                Set same;
                set_intersection(m[i].begin(), m[i].end(),
                                 m[j].begin(), m[j].end(), inserter(same, same.end()));
                auto K = same.size();
                cnt += 2 * (m[i].size() - K) * (m[j].size() - K);
            }
        }
        return cnt;
    }
};

