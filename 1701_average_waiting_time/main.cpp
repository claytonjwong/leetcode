/*
 * 1701. Average Waiting Time
 *
 * Q: https://leetcode.com/problems/average-waiting-time/
 * A: https://leetcode.com/problems/average-waiting-time/discuss/987309/Kt-Js-Py3-Cpp-Average-Wait-Time
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    double averageWaitingTime(VVI& A, int time = 0, int last = 0, VI wait = {}) {
        for (auto& customer: A) {
            auto [i, j] = tie(customer[0], customer[1]);
            time = max(i, last);
            last = time + j;
            wait.push_back(last - i);
        }
        return accumulate(wait.begin(), wait.end(), 0.0) / wait.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
