/*
 * 387. First Unique Character in a String
 *
 * Q: https://leetcode.com/problems/first-unique-character-in-a-string/
 * A: https://leetcode.com/problems/first-unique-character-in-a-string/discuss/614812/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    int firstUniqChar(string S, Map m = {}, int uniq = -1) {
        for (auto c: S)
            ++m[c];
        for_each(S.begin(), S.end(), [i = 0, &m, &uniq](auto c) mutable {
            if (uniq == -1 && m[c] == 1)
                uniq = i;
            ++i;
        });
        return uniq;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
