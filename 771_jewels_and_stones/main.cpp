/*
 * 771. Jewels and Stones
 *
 * Q: https://leetcode.com/problems/jewels-and-stones/
 * A: https://leetcode.com/problems/jewels-and-stones/discuss/113587/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    using Set = set<char>;
    int numJewelsInStones(string jewels, string S) {
        Set J{ jewels.begin(), jewels.end() };
        return count_if(S.begin(), S.end(), [&](auto c) { return J.find(c) != J.end(); });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
