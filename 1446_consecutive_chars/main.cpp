/*
 * 1446. Consecutive Characters
 *
 * Q: https://leetcode.com/problems/consecutive-characters/
 * A: https://leetcode.com/problems/consecutive-characters/discuss/639815/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxPower(string s, int max = 1) {
        for (auto i{ 1 }, same{ 1 }; i < s.size(); ++i)
            if (s[i - 1] == s[i])
                max = std::max(max, ++same);
            else
                same = 1;
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
