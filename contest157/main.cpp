/*

 https://leetcode.com/contest/weekly-contest-157

 1 h 30 m	7/18	1:39:23	    2/4	    2077/5435

 Q1: https://leetcode.com/problems/play-with-chips/
 A1: https://leetcode.com/problems/play-with-chips/discuss/399869/Javascript-and-C%2B%2B-Solutions

 Q2: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
 A2: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/discuss/399886/Javascript-and-C%2B%2B-Solutions

 Q3: https://leetcode.com/problems/path-with-maximum-gold/
 A3: https://leetcode.com/problems/path-with-maximum-gold/discuss/399914/Javascript-and-C%2B%2B-Solutions

 Q4: https://leetcode.com/problems/count-vowels-permutation/
 A4:

 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

// class Solution {
// public:
//     int minCostToMoveChips(vector<int>& A, int even=0, int odd=0) {
//         even = count_if(A.begin(), A.end(), [](auto x){ return x % 2 == 0; });
//         odd  = count_if(A.begin(), A.end(), [](auto x){ return x % 2 == 1; });
//         return min(even, odd);
//     }
// };


//class Solution {
//public:
//    int minCostToMoveChips(vector<int>& A, int even=0, int odd=0) {
//        return min(
//            count_if(A.begin(), A.end(), [](auto x){ return x % 2 == 0; }),
//            count_if(A.begin(), A.end(), [](auto x){ return x % 2 == 1; })
//        );
//    }
//};

// this potential solution lead me to realize that I need to implement a different algorithm (union-find)
// later i found this was the wrong "realization" -- oops!  see below...

//class Solution {
//public:
//    int longestSubsequence(vector<int>& A, int d, unordered_map<int,int> m={}, int ans=0) {
//        for (auto num: A) {
//            if (m.find(num + d) == m.end()) {
//                m[num] = 1;
//                continue;
//            }
//            m[num] = m[num + d] + 1;
//        }
//        for (auto& pair: m)
//            ans = max(ans, pair.second);
//        return ans;
//    }
//};

// union-find and find max occurrence of parent representative of the set (WRONG algorithm!!! way overthinking this one!!!)
// actually i almost go this right the first time around, i should have just subtracted d from num instead of adding!!!

//class Solution {
//public:
//    using VI = vector<int>;
//    using Map = unordered_map<int,int>;
//    using Seen = unordered_set<int>;
//    int longestSubsequence(VI &A, int d, Map P={}, Seen seen={}, Map cnt={}, int ans=0) {
//        int N = A.size();
//        for (auto num: A)
//            P[num] = num;
//        for (auto num: A) {
//            if (seen.find(num - d) != seen.end()) Union(P, num, num - d);
//            seen.insert(num);
//        }
//        for (auto num: seen) {
//            ++cnt[Find(P, num)];
//        }
//        for (auto& pair: cnt)
//            ans = max(ans, pair.second);
//        return ans;
//    }
//private:
//    void Union(Map& P, int a, int b) {
//        a = Find(P, a);
//        b = Find(P, b);
//        if (a == b)
//            return;
//        P[a] = b; // arbitrary choice;
//    };
//    int Find(Map& P, int x) {
//        if (x == P[x])
//            return P[x];
//        return P[x] = Find(P, P[x]);
//    };
//};

// AC (for that "oh yeah duh" moment...)
/*
class Solution {
public:
    using VI = vector<int>;
    int longestSubsequence(VI &A, int d, unordered_map<int,int> m={}, int ans=0) {
        for (auto x: A) {
            m[x] = m[x - d] + 1;
            ans = max(ans, m[x]);
        }
        return ans;
    }
};

int main() {
    vector<int> A{1,5,7,8,5,3,4,2,1}, B{1,2,3,4}, C{3,0,-3,4,-4,7,6}, D{-54,-63,-62,-69,55,48,-67,-94,-46,-48,91,99,-3,77,-85,-52,15,57,-19,46,72,17,78,59,-26,-24,-14,-7,-37,100,-64,-77,-10,-52,68,-60,-16,-58,84,87,-3,11,-26,-62,-37,-14,-21,28,-69,54,35,10,-92,46,-15,88,-20,20,-17,-76,-54,-96,61,3,-52,4,88,-54,66,-96,-31,10,78,44,-6,-34,-97,-72,34,-93,-71,6,17,-100,32,31,-81,53,-9,17,97,44,-83,7,-20,2,73,-2,-81,-50};
    cout << Solution().longestSubsequence(A, -2) << endl;
    cout << Solution().longestSubsequence(B, 1) << endl;
    cout << Solution().longestSubsequence(C, 3) << endl;
    cout << Solution().longestSubsequence(D, 14) << endl;
    return 0;
}
*/

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int getMaximumGold(VVI& A, int ans=0) {
        for (int i=0; i < A.size(); ++i)
            for (int j=0; j < A[0].size(); ++j)
                ans = max(ans, go(A, i, j));
        return ans;
    }
private:
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    int go(VVI& A, int i, int j, Seen&& seen={}) {
        if (!(0 <= i && i < A.size() && 0 <= j && j < A[0].size()) || !A[i][j] || seen[i][j])
            return 0;
        seen[i][j] = true;
        auto ans = A[i][j] + max({ // go clockwise
            go(A, i - 1, j, move(seen)), // up
            go(A, i, j + 1, move(seen)), // right
            go(A, i + 1, j, move(seen)), // down
            go(A, i, j - 1, move(seen))  // left
        });
        seen[i][j] = false;
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VVI G{
        {1,0,7,0,0,0},
        {2,0,6,0,1,0},
        {3,5,6,7,4,2},
        {4,3,1,0,2,0},
        {3,0,5,0,20,0}};

    /*
     3 5 6 7 4
     4 3 1   2
         5   20
     */
    cout << solution.getMaximumGold(G) << endl;
    return 0;
}

