/*
 * Filter Restaurants by Vegan-Friendly, Price and Distance
 *
 * Q: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/
 * A: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/discuss/490369/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Restaurant {
    int id, rank, vegan, cost, dist;
};
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using VR = vector<Restaurant>;
    VI filterRestaurants(VVI& restaurants, int veganFriendly, int maxCost, int maxDist, VI ans = {}) {
        VR R, cand;
        for (auto& r: restaurants)
            R.push_back({r[0], r[1], r[2], r[3], r[4]});
        copy_if(R.begin(), R.end(), back_inserter(cand), [=](auto& r) { return (veganFriendly ? r.vegan == 1 : true) && r.cost <= maxCost && r.dist <= maxDist; });
        sort(cand.begin(), cand.end(), [](auto& lhs, auto& rhs) { return lhs.rank == rhs.rank ? lhs.id > rhs.id : lhs.rank > rhs.rank; });
        transform(cand.begin(), cand.end(), back_inserter(ans), [](auto& r) { return r.id; });
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VVI restaurants{{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
    int veganFriendly = 1, maxCost = 50, maxDist = 10;
    auto ans = solution.filterRestaurants(restaurants, veganFriendly, maxCost, maxDist);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
