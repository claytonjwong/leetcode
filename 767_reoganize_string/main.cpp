/*
 * 767. Reorganize String
 *
 * Q: https://leetcode.com/contest/weekly-contest-68/problems/reorganize-string/
 * A: https://leetcode.com/problems/reorganize-string/discuss/113426/C%2B%2B-priority_queue-with-explanation-(EASY-to-understand)
 */

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    using Pair = pair<char, int>;
    struct Cmp {
        bool operator()(const Pair& a, const Pair& b) const {
            return a.second < b.second;
        }
    };
    using Queue = priority_queue<Pair, vector<Pair>, Cmp>;
    string reorganizeString(string s, string t = {}, Map m = {}) {
        for (auto c: s)
            ++m[c];
        Queue q{ m.begin(), m.end() };
        while (1 < q.size()) {
            auto [a, cnt_a] = q.top(); q.pop();
            auto [b, cnt_b] = q.top(); q.pop();
            t.push_back(a); if (--cnt_a) q.push({ a, cnt_a });
            t.push_back(b); if (--cnt_b) q.push({ b, cnt_b });
        }
        if (!q.empty())
            t.push_back(q.top().first);
        return s.size() == t.size() ? t : "";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
