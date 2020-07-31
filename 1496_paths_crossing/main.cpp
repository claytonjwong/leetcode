/*
 * 1496. Path Crossing
 *
 * Q: https://leetcode.com/problems/path-crossing/
 * A: https://leetcode.com/problems/path-crossing/discuss/709194/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Set = unordered_set<string>;
    bool isPathCrossing(string A, int i = 0, int j = 0, Set seen = {"0,0"}) {
        for (auto c: A) {
            if (c == 'N') --i; if (c == 'W') --j; // -1 for 👆 North or 👈 West
            if (c == 'S') ++i; if (c == 'E') ++j; // +1 for 👇 South or 👉 East
            ostringstream key; key << i << "," << j;
            if (!seen.insert(key.str()).second) // 🚫 path seen 👀
                return true;
        }
        return false;                           // ✅ path *not* seen 👀
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
