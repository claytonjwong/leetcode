/*
 * 134. Gas Station
 *
 * Q: https://leetcode.com/problems/gas-station/
 * A: https://leetcode.com/problems/gas-station/discuss/861437/Javascript-Python3-C%2B%2B-Recursive-Brute-Force
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using fun = function<bool(int, int, int)>;
    int canCompleteCircuit(VI& gas, VI& cost) {
        int N = gas.size();
        fun go = [&](auto i, auto total, auto steps) {
            if (steps == N)
                return true;
            if ((total -= cost[i]) < 0)
                return false;
            auto j = i + 1 < N ? i + 1 : 0;
            return go(j, total + gas[j], steps + 1);
        };
        for (auto start{ 0 }; start < N; ++start)
            if (go(start, gas[start], 0))
                return start;
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
