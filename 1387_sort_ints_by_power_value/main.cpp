/*
 * 1387. Sort Integers by The Power Value
 *
 * Q: https://leetcode.com/problems/sort-integers-by-the-power-value/
 * A: https://leetcode.com/problems/sort-integers-by-the-power-value/discuss/554082/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    using Map = map<int, vector<int>>;
    int getKth(int lo, int hi, int k, Map map = {}, int dist = 0) {
        for (auto i{ lo }; i <= hi; ++i)
            map[powVal(i)].push_back(i);
        for (auto i = map.begin(); i != map.end(); ++i) {
            auto set = i->second; // first = powVal, second = each "set" of i-th values from [lo..hi]
            for (auto j = set.begin(); j != set.end(); ++j)
                if (++dist == k) // target 🎯
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
