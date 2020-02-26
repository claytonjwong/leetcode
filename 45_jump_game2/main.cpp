/*
 * 45. Jump Game II
 *
 * Q: https://leetcode.com/problems/jump-game-ii/
 * A: https://leetcode.com/problems/jump-game-ii/discuss/520743/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

//class Solution {
//public:
//    using VI = vector<int>;
//    using Queue = queue<int>;
//    using Set = unordered_set<int>;
//    int jump(VI& A, Set seen = Set{0}, int i = 1, int reach = 1, int hops = 0) {
//        int N = A.size();
//        Queue q{{A[0]}};
//        while (i < N) {
//            int K = q.size();
//            while (K--) {
//                auto next = q.front(); q.pop();
//                for (reach = max(reach, next); i <= min(reach, N - 1); ++i)
//                    if (seen.insert(i).second)
//                        q.push(i + A[i]);
//            }
//            ++hops;
//        }
//        return hops;
//    }
//};

class Solution {
public:
    using VI = vector<int>;
    int jump(VI& A) {
        int N = A.size(), hops = 0, reach = A[0], next = -1;
        for (auto i = 1; i < N; ++hops, reach = next)
            for (next = reach; i <= min(reach, N - 1); ++i)
                next = max(next, i + A[i]);
        return hops;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
