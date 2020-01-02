/*
 * 684. Redundant Connection
 *
 * Q: https://leetcode.com/problems/redundant-connection/
 * A: https://leetcode.com/problems/redundant-connection/discuss/468028/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI findRedundantConnection(VVI& edges) {
        generate_n(back_inserter(P), 1001, [i = -1]() mutable { return ++i; });
        for (auto& edge: edges) {
            auto [u, v] = tie(edge[0], edge[1]);
            if (!join(u, v))
                return {u, v};
        }
        return {};
    }
private:
    VI P;
    int find(int x) {
        if (P[x] == x)
            return x;
        return P[x] = find(P[x]);
    }
    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        P[a] = b; // arbitrary choice
        return true;
    }
};

int main() {

    return 0;
}
