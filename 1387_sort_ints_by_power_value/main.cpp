/*
 * 1387. Sort Integers by The Power Value
 *
 * Q: https://leetcode.com/problems/sort-integers-by-the-power-value/
 * A: https://leetcode.com/problems/sort-integers-by-the-power-value/discuss/554082/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    using Map = map<int, set<int>>;
    int getKth(int lo, int hi, int k, Map map = {}, int dist = 0) {
        for (auto i{ lo }; i <= hi; ++i) {
            auto val = powVal(i);
            if (map.find(val) == map.end())
                map[val] = { i };
            else
                map[val].insert(i);
        }
        for (auto i = map.begin(); i != map.end(); ++i) {
            auto set = i->second;
            for (auto j = set.begin(); j != set.end(); ++j)
                if (++dist == k)
                    return *j;
        }
        return -1;
    }
private:
    int powVal(int x) {
        return x == 1 ? 0 : x % 2 == 0 ? 1 + powVal(x / 2) : 1 + powVal(3 * x + 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
