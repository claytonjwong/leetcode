/*
 * 1604. Alert Using Same Key-Card Three or More Times in a One Hour Period
 *
 * Q: https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
 * A: https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/discuss/876799/Javascript-Python3-C%2B%2B-Map-%2B-Queue
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using Map = unordered_map<string, vector<int>>;
    using Set = set<string>;
    VS alertNames(VS& names, VS& times, Map m = {}, Set alerts = {}) {
        auto minutes = [&](auto& time, int h = 0, int m = 0, char _ = '\0') {
            stringstream stream{ time }; stream >> h >> _ >> m;
            return 60 * h + m;
        };
        for (auto i{ 0 }; i < names.size(); ++i) {
            auto name = names[i],
                 time = times[i];
            m[name].push_back(minutes(time));
        }
        for (auto& [name, times]: m) {
            sort(times.begin(), times.end());
            queue<int> q;
            for (auto time: times) {
                while (q.size() && q.front() + 60 < time)
                    q.pop();
                q.push(time);
                if (3 <= q.size()) {
                    alerts.insert(name);
                    break;
                }
            }
        }
        return { alerts.begin(), alerts.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
