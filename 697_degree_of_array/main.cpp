/*
 * 697. Degree of an Array
 *
 * Q: https://leetcode.com/problems/degree-of-an-array/
 * A: https://leetcode.com/problems/degree-of-an-array/discuss/588249/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int findShortestSubArray(VI& A, Map m = {}, Map L = {}, Map R = {}, VI cands = {}, int min = 50001) {
        for (auto i{ 0 }; i < A.size(); ++i) {
            auto x = A[i];
            ++m[x];
            if (L.find(x) == L.end())
                L[x] = i; // 👈 (L)eft-most index
            R[x] = i;     // 👉 (R)ight-most index
        }
        auto [_, max] = *max_element(m.begin(), m.end(), [](auto& a, auto& b) { return a.second < b.second; });
        for (auto [x, cnt]: m)
            if (cnt == max)
                cands.push_back(x);
        for (auto x: cands)
            min = std::min(min, R[x] - L[x] + 1); // +1 for L..R inclusive
        return min;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
