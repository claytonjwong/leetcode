/*
 * 398. Random Pick Index
 *
 * Q: https://leetcode.com/problems/random-pick-index/
 * A: https://leetcode.com/problems/random-pick-index/discuss/553004/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    Solution(VI& A) {
        for (auto i{ 0 }; i < A.size(); ++i)
            if (m.find(A[i]) == m.end())
                m[A[i]] = { i };
            else
                m[A[i]].push_back(i);
        srand(time(nullptr)); // seed for rand()
    }

    int pick(int target) {
        auto index = m[target];
        auto i = floor(rand() % index.size());
        return index[i];
    }
private:
    unordered_map<int, VI> m;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
