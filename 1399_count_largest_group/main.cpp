/*
 * 1399. Count Largest Group
 *
 * Q: https://leetcode.com/problems/count-largest-group/
 * A: https://leetcode.com/problems/count-largest-group/discuss/565232/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<int, int>;
    int countLargestGroup(int N, Map m = {}) {
        for (auto x{ 1 }; x <= N; ++x)
            ++m[sum(x)];
        auto max = *max_element(m.begin(), m.end(), [](auto& a, auto& b) { return a.second < b.second; });
        return count_if(m.begin(), m.end(), [=](auto& pair) { return pair.second == max.second; });
    }
private:
    int sum(int x) {
        if (x == 0)
            return 0;
        return x % 10 + sum(x / 10);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
