/*
 * 1345. Jump Game IV
 *
 * Q: https://leetcode.com/problems/jump-game-iv/
 * A: https://leetcode.com/problems/jump-game-iv/discuss/519535/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, VI>;
    using Q = queue<int>;
    using S = unordered_set<int>;
    int minJumps(VI& A, Map m = {}, Q q = Q({0}), S seen = S{0}, int hops = 0) {
        int N = A.size();
        for (auto i = 0; i < N; ++i)
            m[A[i]].push_back(i);
        while (!q.empty()) {
            auto K = q.size();
            while (K--) {
                auto i = q.front(), x = A[i]; q.pop();
                if (i + 1 == N)
                    return hops;
                m[x].push_back(i - 1);
                m[x].push_back(i + 1);
                for (auto j: m[x])
                    if (0 <= j && j < N && seen.insert(j).second)
                        q.push(j);
                m[x] = {}; // avoid TLE by only jumping once per unique value
            }
            ++hops;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    Solution::VI A{100,-23,-23,404,100,23,23,23,3,404};
    Solution::VI B{7};
    Solution::VI C{7,6,6,9,6,9,7};
    Solution::VI D{1,2,3};
    Solution::VI E{11,22,7,7,7,7,7,7,7,22,13};
    assert(solution.minJumps(A) == 3);
    assert(solution.minJumps(B) == 0);
    assert(solution.minJumps(C) == 1);
    assert(solution.minJumps(D) == 2);
    assert(solution.minJumps(E) == 3);
    //              0                                                                  1   2               4   3                                                            5
    Solution::VI F{68, -94, -44, -18, -1, 18, -87, 29, -6, -87, -27, 37, -57,  7, 18, 68,-59, 29,  7, 53,-27,-59, 18, -1, 18,-18,-59,-1,-18,-84,-20, 7, 7,-87,-18,-84,-20,-27};
    //              0    1    2    3   4   5    6   7   8    9   10  11   12  13  14  15  16  17  18  19  20  21  22  23  24  25  26 27  28  29  30 31  32 33  34  35  36  37
    //             0,0
    //                 1,1                                                           *15,1*
    //                       2,2                                                  14,2     *16,2*
    //                            3,3                                          13,3            17,3          *21,3*          24,3  26,3
    //                                 4,4                                12,4                            *20,4*                                          32,4   34,4
    //                                                                                                                                                                      *37,5*
    assert(solution.minJumps(F) == 5);
    return 0;
}
