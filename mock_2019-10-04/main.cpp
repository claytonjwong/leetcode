/*

1079. Letter Tile Possibilities

 Q:
 A:

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <iterator>
#include <deque>

using namespace std;

/*
class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end()); // needed for test cases such as "CDC"
        return go(tiles) - 1; // -1 for the empty string
    }
private:
    int perms(const string& s, vector<int> fact={1,1,2,6,24,120,720,5040}, unordered_map<char,int> freq={}) {
        for (auto c: s)
            ++freq[c];
        auto res = fact[s.size()];
        for (auto [_, val]: freq)
            res /= fact[val];
        return res;
    }
    int go(const string& s, string&& cur={}, unordered_set<string>&& seen={}, int i=0) {
        if (i == s.size())
            return seen.insert(cur).second ? perms(cur) : 0;
        return go(s, move(cur), move(seen), i+1) + go(s, cur + s[i], move(seen), i+1);
    }
};

int main() {
    Solution solution;
//    cout << solution.numTilePossibilities("AAB") << endl;
//    cout << solution.numTilePossibilities("AAABBC") << endl;
    cout << solution.numTilePossibilities("CDC") << endl;


    return 0;
}
*/

// wrong algorithm
//class Solution {
//public:
//    int totalFruit(vector<int>& tree, int run=2, int ans=2) {
//        int n = tree.size();
//        if (n <= 2)
//            return n;
//        deque<int> q{tree[0], tree[1]};
//        for (auto i=2; i < n; ++i) {
//            if (tree[i] == q.front() || tree[i] == q.back()) {
//                ans = max(ans, ++run);
//                continue;
//            }
//            if (q.front() == q.back())
//                ans = max(ans, ++run);
//            else
//                run = 2;
//            q.pop_front(), q.push_back(tree[i]);
//        }
//        return ans;
//    }
//};

/*
// Naive TLE
class Solution {
public:
    int totalFruit(vector<int>& tree, int ans=0) {
        int n = tree.size();
        for (auto i=0; i < n; ++i) {
            unordered_set<int> seen={};
            for (auto j=i, run=0; j < n; ++j) {
                seen.insert(tree[j]);
                if (seen.size() > 2)
                    break;
                ans = max(ans, ++run);
            }
        }
        return ans;
    }
};
*/

// wrong algorithm
//class Solution {
//public:
//    int totalFruit(vector<int>& t, int run=2, size_t ans=2) {
//        int n = t.size();
//        if (n <= 2)
//            return n;
//        unordered_set<int> unique{t[0], t[1]};
//        multiset<int> seen{t[0], t[1]};
//        for (auto i=2; i < n; ++i) {
//            unique.insert(t[i]), seen.insert(t[i]);
//            cout << "seen (" << seen.size() << "): "; copy(seen.begin(), seen.end(), ostream_iterator<int>(cout, " ")); cout << endl;
//            if (unique.size() > 2) {
//                auto [beg, end] = seen.equal_range(t[i-1]);
//                seen = {beg, end};
//                unique = {*beg};
//                continue;
//            }
//            ans = max(ans, seen.size());
//        }
//        return ans;
//    }
//};

int main() {
    vector<int> tree{1,0,1,4,1,4,1,2,3};
    cout << Solution().totalFruit(tree) << endl;
    return 0;
}
