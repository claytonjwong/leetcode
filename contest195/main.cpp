/*
 * https://leetcode.com/contest/weekly-contest-195/ranking/26/
 *
 * Rank          Name           Score    Finish Time    Q1 (3)	      Q2 (4)     Q3 (6)    Q4 (7)
 * 626 / 8068    claytonjwong   7        0:52:46        0:32:56 *3	  0:37:46
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

/*
 * 1496. Path Crossing
 *
 * Q: https://leetcode.com/problems/path-crossing/
 * A: https://leetcode.com/problems/path-crossing/discuss/709194/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using Set = unordered_set<string>;
        bool isPathCrossing(string A, int i = 0, int j = 0, Set seen = {"0,0"}) {
            for (auto c: A) {
                if (c == 'N') --i; if (c == 'W') --j; // -1 for 👆 north or 👈 west
                if (c == 'S') ++i; if (c == 'E') ++j; // +1 for 👇 south or 👉 east
                ostringstream key; key << i << "," << j;
                if (!seen.insert(key.str()).second) // path seen? 👀
                    return true;
            }
            return false; // path not seen 👀
        }
    };
}

/*
 * 1497. Check If Array Pairs Are Divisible by k
 *
 * Q: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
 * A: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/discuss/709199/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 { // INCORRECT ALGORITHM!!!
    class Solution {
    public:
        using VI = vector<int>;
        bool canArrange(VI& A, int K) {
            return !(accumulate(A.begin(), A.end(), 0LL) % K);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
