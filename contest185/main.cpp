/*
 * https://leetcode.com/contest/weekly-contest-185/
 *
 * Rank            Name            Score    Finish Time     Q1 (3)       Q2 (4)      Q3 (5)        Q4 (6)
 * 2666 / 14208    claytonjwong    12       1:23:20         0:10:28 *1   0:41:44     1:13:20 *1
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

/*
 * 1417. Reformat The String
 *
 * Q: https://leetcode.com/problems/reformat-the-string/
 * A: https://leetcode.com/problems/reformat-the-string/discuss/586472/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        string reformat(string S, string letters = {}, string digits = {}, string ans = {}) {
            copy_if(S.begin(), S.end(), back_inserter(letters), [](auto c) { return isalpha(c); });
            copy_if(S.begin(), S.end(), back_inserter(digits), [](auto c) { return isdigit(c); });
            if (abs(int(letters.size()) - int(digits.size())) > 1)
                return {};
            auto N = letters.size() + digits.size();
            auto turn = letters.size() >= digits.size() ? 0 : 1; // 0 == letters first  1 == digits first
            for (auto i{ 0 }, j{ 0 }, k{ 0 }; i < N; ++i)
                if (i % 2 == turn)
                    ans.push_back(letters[j++]);
                else
                    ans.push_back(letters[k++]);
            return ans;
        }
    };
}

/*
 * 1418. Display Table of Food Orders in a Restaurant
 *
 * Q: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
 * A: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/discuss/586639/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
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
}

/*
 * 1419. Minimum Number of Frogs Croaking
 *
 * Q: https://leetcode.com/problems/minimum-number-of-frogs-croaking/
 * A: https://leetcode.com/problems/minimum-number-of-frogs-croaking/discuss/586488/Javascript-and-C%2B%2B-solutions
 */
namespace Question3_Hardcoded {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        int minNumberOfFrogs(string S, Map cnt = Map{{'c', 0},{'r',0},{'o',0},{'a',0},{'k',0}}, int max = -1e9) {
            auto ok = [&]() { return cnt['c'] >= cnt['r'] && cnt['r'] >= cnt['o'] && cnt['o'] >= cnt['a'] && cnt['a'] >= cnt['k']; };
            for (auto c: S) {
                if (!ok())
                    return -1;
                ++cnt[c];
                if (c == 'k')
                    max = std::max(max, 1 + std::max({cnt['c'] - cnt['k'], cnt['r'] - cnt['k'], cnt['o'] - cnt['k'], cnt['a'] - cnt['k']}));
            }
            return cnt['c'] == cnt['r'] && cnt['r'] == cnt['o'] && cnt['o'] == cnt['a'] && cnt['a'] == cnt['k'] ? max : -1;
        }
    };
}
namespace Question3_CountArray {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<char, int>;
        int minNumberOfFrogs(string S, string order = "croak", int max = 0) {
            VI cnt(5);
            auto ok = [&]() {
                for (auto i{ 1 }; i < cnt.size(); ++i)
                    if (cnt[i - 1] < cnt[i])
                        return false;
                return true;
            };
            for (auto c: S) {
                if (!ok())
                    return -1;
                ++cnt[order.find(c)];
                if (c == 'k')
                    for (auto pre: string("croa"))
                        max = std::max(max, 1 + cnt[order.find(pre)] - cnt[order.find(c)]);
            }
            return all_of(cnt.begin(), cnt.end(), [&](auto x) { return x == cnt[0]; }) ? max : -1;
        }
    };
}

int main() {
    std::cout << "Hello World" << std::endl;
    return 0;
}
