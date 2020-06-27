/*
 * 759. Employee Free Time
 *
 * Q: https://leetcode.com/problems/employee-free-time/
 * A: https://leetcode.com/problems/employee-free-time/discuss/119418/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Interval {
    int start, end;
    Interval(int start, int end) : start{ start }, end{ end } {}
};

class Solution {
public:
    using VI = vector<Interval>;
    using VVI = vector<VI>;
    using Map = map<int, int>;
    VI employeeFreeTime(VVI A, Map m = {}, VI ans = {}) {
        for (auto& employee: A)
            for (auto& i: employee)
                m[i.start] = max(m[i.start], i.end);
        auto pre = m.size() ? m.begin()->first : 0; // init previous end to current begin
        for (auto [cur, end]: m) {
            if (pre < cur)
                ans.emplace_back(Interval(pre, cur)); // gap [previous end 👉 current begin] 🎯
            pre = max(pre, end); // previous end is maximum end seen so far
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
