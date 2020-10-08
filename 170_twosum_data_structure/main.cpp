/*
 * 170. Two Sum III - Data structure design
 *
 * Q: https://leetcode.com/problems/two-sum-iii-data-structure-design/
 * A: https://leetcode.com/problems/two-sum-iii-data-structure-design/discuss/594312/Javascript-Python3-C%2B%2B-Map-Count-of-X
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class TwoSum {
    using Map = unordered_map<int, int>;
    Map m;
public:
    void add(int x) {
        ++m[x];
    }
    bool find(int x) {
        for (auto [y, cnt]: m) {
            auto t = x - y;
            if (m.find(t) != m.end() && (t != y || 1 < cnt))
                return true;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
