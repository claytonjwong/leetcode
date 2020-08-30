/*
 * 952. Largest Component Size by Common Factor
 *
 * Q: https://leetcode.com/problems/largest-component-size-by-common-factor/
 * A: https://leetcode.com/problems/largest-component-size-by-common-factor/discuss/204260/Javascript-Python3-C%2B%2B-Union-Find
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    using fun = function<int(int)>;
    int largestComponentSize(VI& A, int N = 100001, Map m = {}) {
        VI P(N); iota(P.begin(), P.end(), 0);               // 🙂 parent representative of disjoint sets
        VI L(N, 1);                                         // 🤥 length of parent representative's set
        fun find = [&](auto x) { return P[x] = x == P[x] ? P[x] : find(P[x]); };
        auto _union = [&](auto a, auto b) {
            a = find(a);
            b = find(b);
            if (a == b)
                return;
            P[b] = a;  // arbitrary choice
            L[a] += L[b];
        };
        for (auto x: A) {
            if (m[x]) _union(m[x], x); else m[x] = x;      // case 1: x as a factor of itself
            for (auto i{ 2 }; i * i <= x; ++i) {
                if (x % i)
                    continue;
                auto j = x / i;
                if (m[i]) _union(m[i], x); else m[i] = x;  // case 2: i-th factor of x
                if (m[j]) _union(m[j], x); else m[j] = x;  // case 3: j-th factor of x
            }
        }
        return *max_element(L.begin(), L.end());           // 🎯 maximum length of any parent representative's set
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
