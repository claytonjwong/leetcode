/*
 * 346. Moving Average from Data Stream
 *
 * Q: https://leetcode.com/problems/moving-average-from-data-stream/
 * A: https://leetcode.com/problems/moving-average-from-data-stream/discuss/125631/Javascript-Python3-C%2B%2B-Queue-solutions
 */

#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
    int N, sum;
    queue<int> q;
public:
    MovingAverage(int N) : N{ N }, sum{ 0 } {}
    double next(int x) {
        if (q.size() == N)
            sum -= q.front(), q.pop();
        sum += x, q.push(x);
        return double(sum) / q.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
