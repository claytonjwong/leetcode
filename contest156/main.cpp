/*

 https://leetcode.com/contest/weekly-contest-156

 Rank	        Name	        Score       Finish Time 	Q1 (3)	    Q2 (4)	    Q3 (5)	    Q4 (7)
 2131 / 6764	claytonjwong 	8	        0:34:51	        0:05:24		            0:34:51

 */


#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

/*
class Solution {
public:
    bool uniqueOccurrences(vector<int>& A, unordered_map<int,int> cnt={}, unordered_set<int> seen={}) {
        for (auto num: A)
            ++cnt[num];
        for (auto& pair: cnt)
            if (!seen.insert(pair.second).second)
                return false;
        return true;
    }
};


int main() {
    Solution solution;
    vector<int> A{-3,0,1,-3,1,1,1,-3,10,0};
    cout << solution.uniqueOccurrences(A) << endl;
    return 0;
}
*/


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost, int cost=0, int ans=0) {
        int n = s.size();
        for (int i=0, j=0; i < n && j < n; ++j) {
            cost += abs(s[j] - t[j]);
            for (; i <= j && cost > maxCost; ++i)
                cost -= abs(s[i] - t[i]);
            ans = max(ans, j-i+1); // +1 since we are counting i..j inclusive
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.equalSubstring("abcd", "bcdf", 3) << endl;
    cout << solution.equalSubstring("abcd", "cdef", 1) << endl;
    cout << solution.equalSubstring("abcd", "acde", 0) << endl;
    cout << solution.equalSubstring("krpgjbjjznpzdfy", "nxargkbydxmsgby", 14) << endl;
    return 0;
}

/*
class Solution {
public:
    string removeDuplicates(string s, int k, string u={}, string v={}) {
        for (u = go(s, k), v = go(u, k); u != v; u = go(v, k), v = go(u, k));
        return u;
    }
private:
    string go(string s, int k, string stack={}) {
        int cnt = 0;
        char last = '\0';
        for (auto c: s) {
            stack.push_back(c);
            cnt = c == last ? cnt+1 : 0;
            last = c;
            if (cnt == k-1) {
                stack.resize(stack.size() - k);
                last = !stack.empty() ? stack.back() : '\0';
                cnt = 0;
            }
        }
        return stack;
    }
};

int main() {
    cout << Solution().removeDuplicates("abcd", 2) << endl;
    cout << Solution().removeDuplicates("deeedbbcccbdaa", 3) << endl;
    cout << Solution().removeDuplicates("pbbcggttciiippooaais", 2) << endl;
    return 0;
}
*/
