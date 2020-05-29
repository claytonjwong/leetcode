/*
 * 207. Course Schedule
 *
 * Q: https://leetcode.com/problems/course-schedule/
 * A: https://leetcode.com/problems/course-schedule/discuss/658707/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    using Set = unordered_set<int>;
    using Map = unordered_map<int, Set>;
    Map m;
    Set look, seen;
    bool go(int i) {
        if (look.find(i) != look.end()) return false;
        if (seen.find(i) != seen.end()) return true;
        look.insert(i);
        for (auto j: m[i])
            if (!go(j))
                return false;
        look.erase(i);
        seen.insert(i);
        return true;
    }
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    bool canFinish(int N, VVI& A, Set look = {}, Set seen = {}) {

        for (auto i{ 0 }; i < N; ++i)
            if (!go(i))
                return false;
        return true;
    }
};

int main() {
    Solution solution;
    Solution::VVI A{
        {0, 1},
        {1, 0}
    };
    cout << solution.canFinish(2, A) << endl;
    return 0;
}
