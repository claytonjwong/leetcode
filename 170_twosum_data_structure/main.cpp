/*
 * 170. Two Sum III - Data structure design
 *
 * Q: https://leetcode.com/problems/two-sum-iii-data-structure-design/
 * A: https://leetcode.com/problems/two-sum-iii-data-structure-design/discuss/594312/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class TwoSum {
public:
    void add(int x) {
        ++m[x];
    }
    bool find(int x) {
        for (auto [y, _]: m) {
            auto z = x - y;
            if (m.find(z) != m.end() && (y != z || m[y] > 1))
                return true;
        }
        return false;
    }
private:
    using Map = unordered_map<int, int>;
    Map m;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
