/*
 * 1722. Minimize Hamming Distance After Swap Operations
 *
 * Q: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
 * A: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/discuss/1009782/Kt-Js-Py3-Cpp-Union-Find-%2B-Set-Diff
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using fun = function<int(int)>;
    using Set = multiset<int>;
    using Map = unordered_map<int, Set>;
    using Unique = unordered_set<int>;
    int minimumHammingDistance(VI& s, VI& t, VVI& A, Map m1 = {}, Map m2 = {}, int dist = 0) {
        int N = s.size();
        VI P(N); iota(P.begin(), P.end(), 0);  // 🙂  N disjoint parent representatives of unioned indices
        fun find = [&](auto x) {
            return P[x] = P[x] == x ? x : find(P[x]);
        };
        auto join = [&](auto a, auto b) {
            a = find(a);
            b = find(b);
            if (a == b)
                return;
            P[a] = b;  // 🎲 arbitrary choice
        };
        for (auto& swap: A) {
            auto [i, j] = tie(swap[0], swap[1]);
            join(i, j);
        }
        for (auto i{ 0 }; i < N; ++i) {
            auto x = find(P[i]);
            m1[x].insert(s[i]);
            m2[x].insert(t[i]);
        }
        Unique parents{ P.begin(), P.end() };
        for (auto x: parents) {
            VI diff;
            set_difference(m1[x].begin(), m1[x].end(),
                           m2[x].begin(), m2[x].end(), back_inserter(diff));
            dist += diff.size();
        }
        return dist;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
