/*
 * 1361. Validate Binary Tree Nodes
 *
 * Q: https://leetcode.com/problems/validate-binary-tree-nodes/
 * A: https://leetcode.com/problems/validate-binary-tree-nodes/discuss/517576/Javascript-and-C%2B%2B-solutions
 */

#include <vector>

using namespace std;

//    class Solution {
//    public:
//        using VI = vector<int>;
//        using Q = queue<int>;
//        using Seen = unordered_set<int>;
//        bool validateBinaryTreeNodes(int N, VI& L, VI& R, Q q = Q{{0}}, Seen seen = Seen{0}) {
//            while (!q.empty()) {
//                auto cur = q.front(); q.pop();
//                auto l = L[cur],
//                     r = R[cur];
//                if ((l > -1 && seen.find(l) != seen.end()) || (r > -1 && seen.find(r) != seen.end()))
//                    return false;
//                if (l > -1) q.push(l), seen.insert(l);
//                if (r > -1) q.push(r), seen.insert(r);
//            }
//            return seen.size() == N;
//        }
//    };

class Solution {
public:
    using VI = vector<int>;
    bool validateBinaryTreeNodes(int N, VI& L, VI& R, VI P = {}) {
        generate_n(back_inserter(P), N, [i = -1]() mutable { return ++i; });
        auto join = [&](auto a, auto b) {
            a = find(P, a);
            b = find(P, b);
            if (a == b)
                return false;
            P[a] = b; // arbitrary choice
            return true;
        };
        for (auto i = 0; i < N; ++i) {
            if (L[i] > -1 && !join(i, L[i])) return false;
            if (R[i] > -1 && !join(i, R[i])) return false;
        }
        auto rep = find(P, 0);
        for (auto i = 1; i < N; ++i)
            if (rep != find(P, i)) return false;
        return true;
    }
private:
    int find(VI& P, int x) { return P[x] = P[x] == x ? P[x] : find(P, P[x]); };
};
