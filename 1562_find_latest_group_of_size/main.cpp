/*
 * 1562. Find Latest Group of Size M
 *
 * Q: https://leetcode.com/problems/find-latest-group-of-size-m/
 * A: https://leetcode.com/problems/find-latest-group-of-size-m/discuss/810189/Javascript-Python3-C%2B%2B-Union-Find
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    using fun = function<int(int)>;
    int findLatestStep(VI& A, int T, Set seen = {}, Set ok = {}, int last = -1) {
        transform(A.begin(), A.end(), A.begin(), [](auto i) { return i - 1; });
        int N = A.size();
        VI P(N); iota(P.begin(), P.end(), 0);
        VI L(N, 1);
        fun find = [&](auto x) {
            return P[x] = x == P[x] ? P[x] : find(P[x]);
        };
        auto _union = [&](auto a, auto b) {
            a = find(a);
            b = find(b);
            P[b] = a;
            return L[a] += L[b];
        };
        auto step{ 1 };
        for (auto i: A) {
            seen.insert(i);
            if (0 < i)     ok.erase(find(P[i - 1]));
            if (i + 1 < N) ok.erase(find(P[i + 1]));
            if (seen.find(i - 1) != seen.end()) L[i] = _union(i, i - 1);
            if (seen.find(i + 1) != seen.end()) L[i] = _union(i, i + 1);
            if (L[i] == T)
                ok.insert(i);
            if (ok.size())
                last = step;
            ++step;
        }
        return last;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
