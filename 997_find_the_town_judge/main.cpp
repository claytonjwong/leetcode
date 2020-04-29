/*
 * 997. Find the Town Judge
 *
 * Q: https://leetcode.com/problems/find-the-town-judge/
 * A: https://leetcode.com/problems/find-the-town-judge/discuss/602364/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Trust = unordered_set<int>;
    using Trusts = unordered_map<int, Trust>;
    int findJudge(int N, VVI& A, Trusts T = {}, Trust all = {}) {
        for (auto& t: A) {
            auto [a, b] = tie(t[0], t[1]);
            all.insert(a); // all whom have trust
            T[b].insert(a); // b is trusted by a
        }
        for (auto [x, t]: T)
            if (all.find(x) == all.end() && t.size() == N - 1) // x trusts no one and is trusted by N - 1 others 🎯
                return x;
        return N == 1 ? 1 : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
