/*
 * 1346. Check If N and Its Double Exist
 *
 * Q: https://leetcode.com/problems/check-if-n-and-its-double-exist/
 * A: https://leetcode.com/problems/check-if-n-and-its-double-exist/discuss/509104/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Seen = unordered_set<double>;
    bool checkIfExist(VI& A, Seen seen = {}) {
        for (auto x: A) {
            if (seen.find(x / 2.0) != seen.end() || seen.find(x * 2) != seen.end())
                return true;
            seen.insert(x);
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
