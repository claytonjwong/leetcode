/*
 * 933. Number of Recent Calls
 *
 * Q: https://leetcode.com/problems/number-of-recent-calls/
 * A: https://leetcode.com/problems/number-of-recent-calls/discuss/189233/Javascript-Python3-C%2B%2B-Queue-solutions
 */

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
    queue<int> q;
public:
    int ping(int t) {
        while (q.size() && q.front() < t - 3000)
            q.pop();
        q.push(t);
        return q.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
