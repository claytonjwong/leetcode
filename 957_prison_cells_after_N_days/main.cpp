/*
 * 957. Prison Cells After N Days
 *
 * Q: https://leetcode.com/problems/prison-cells-after-n-days/
 * A: https://leetcode.com/problems/prison-cells-after-n-days/discuss/717917/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = unordered_map<string, int>;
    VI prisonAfterNDays(VI& A, int N, VVI all = {}, Map m = {}, int P = 0) {
        VI cur{ A },
           pre{ A };
        for (auto day{ 0 }; day <= N; ++day) {
            all.push_back(pre); // 👀  track all cells seen
            // ⭐️ find pisano period to avoid TLE for large values of N
            ostringstream key; copy(pre.begin(), pre.end(), ostream_iterator<int>(key, ""));
            if (m.find(key.str()) != m.end()) {
                P = day - m[key.str()]; // 🎯 pisano period
                break;
            }
            m[key.str()] = day;
            // 🤔 generate current from previous
            cur[0] = cur[7] = 0; // first and last are always set to 0
            for (auto i{ 1 }; i < 7; ++i)
                cur[i] = int(pre[i - 1] == pre[i + 1]);
            swap(pre, cur);
        }
        return pre == cur ? cur             // case 1: if previous equals current, then pattern is immutable until N-th day
             : !P ? all.back()              // case 2: pisano period not reached in N days, return N-th day's solution
             : N % P ? all[N % P] : all[P]; // case 3: return N-th day's solution based upon the pisano period
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
