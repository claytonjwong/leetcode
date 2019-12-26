/*
 * 1298. Maximum Candies You Can Get from Boxes
 *
 * Q: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/
 * A: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/discuss/461625/Javascript-and-C%2B%2B-solutions
 */
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Set = unordered_set<int>;
    int maxCandies(VI& unlocked, VI& candies, VVI& keys, VVI& has, VI& init, Set seen = {}, Set explored = {}, int total = 0) {
        queue<int> q{{init.begin(), init.end()}};
        while (!q.empty()) {
            auto i = q.front(); q.pop();
            seen.insert(i);
            if (!unlocked[i] || !explored.insert(i).second)
                continue; // skip if i-th box is locked or already explored once
            total += candies[i];
            for (auto j: keys[i]) {
                unlocked[j] = 1; // immediately unlock j-th box
                if (seen.find(j) != seen.end())
                    q.push(j); // we have seen this j-th box, but did *not* have a key when we saw it
            }
            for (auto j: has[i])
                q.push(j); // add all contained boxes to queue for processing
        }
        return total;
    }
};

int main() {
    Solution solution;
    Solution::VI status{1,0,1,0}, candies{7,5,4,100}, initialBoxes{0};
    Solution::VVI keys{{},{},{1},{}}, containedBoxes{{1,2},{3},{},{}};
    cout << solution.maxCandies(status, candies, keys, containedBoxes, initialBoxes) << endl;
    return 0;
}
