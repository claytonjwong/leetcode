/*
 * 1418. Display Table of Food Orders in a Restaurant
 *
 * Q: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
 * A: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/discuss/586639/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VVS = vector<VS>;
    using Map = unordered_map<int, unordered_map<string, int>>;
    using Items = set<string>;
    using Tables = set<int>;
    VVS displayTable(VVS& orders, Map T = {}, Items items = {}, Tables tables = {}) {
        for (auto& order: orders) {
            auto [_, table, item] = tie(order[0], order[1], order[2]);
            items.insert(item);
            tables.insert(stoi(table));
            ++T[stoi(table)][item];
        }
        VVS ans{{"Table"}};
        ans.back().insert(ans.back().end(), items.begin(), items.end());
        for (auto table = tables.begin(); table != tables.end(); ++table) {
            VS next{ to_string(*table) };
            for (auto item = items.begin(); item != items.end(); ++item)
                next.push_back(T[*table][*item] ? to_string(T[*table][*item]) : "0");
            ans.emplace_back(next);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
