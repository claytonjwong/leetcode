/*
 * 1089. Duplicate Zeros
 *
 * Q: https://leetcode.com/problems/duplicate-zeros/
 * A: https://leetcode.com/problems/duplicate-zeros/discuss/603769/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Queue = queue<int>;
    void duplicateZeros(VI& A, Queue q = {}) {
        for (auto i{ 0 }; i < A.size(); ++i) {
            if (!A[i])
                q.push(0),
                q.push(0);
            else
                q.push(A[i]);
            A[i] = q.front(); q.pop();
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
