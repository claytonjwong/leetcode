/*
 * 1046. Last Stone Weight
 *
 * Q: https://leetcode.com/problems/last-stone-weight/
 * A: https://leetcode.com/problems/last-stone-weight/discuss/577600/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int lastStoneWeight(VI& A) {
        priority_queue<int, VI, ::less<int>> q{A.begin(), A.end()};
        while (!q.empty()) {
            auto y = q.top(); q.pop();
            if (q.empty())
                return y;
            auto x = q.top(); q.pop();
            if (y - x > 0)
                q.push(y - x);
        }
        return 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
