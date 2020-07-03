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
        VI pre{ A };
        for (auto day{ 0 }; day <= N; ++day) {
            all.push_back(pre); // 👀 track all seen
            // ⭐️ find pisano period to avoid TLE for large values of N
            ostringstream key; copy(pre.begin(), pre.end(), ostream_iterator<int>(key, ""));
            if (m.find(key.str()) != m.end()) {
                P = day - m[key.str()]; // 🎯 pisano period
                break;
            }
            m[key.str()] = day;
            // 🤔 generate current from previous
            VI cur(8);
            for (auto i{ 1 }; i < 7; ++i)
                cur[i] = int(pre[i - 1] == pre[i + 1]);
            swap(pre, cur);
        }
        return !P ? all[all.size() - 1]     // ❌ case 1: pisano period *not* found in N days, return N-th day's solution
             : N % P ? all[N % P] : all[P]; // ✅ case 2: pisano period found, return N-th day's solution based upon pisano period
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
