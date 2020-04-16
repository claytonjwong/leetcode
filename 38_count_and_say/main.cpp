/*
 * 38. Count and Say
 *
 * Q: https://leetcode.com/problems/count-and-say/
 * A: https://leetcode.com/problems/count-and-say/discuss/581589/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int N) {
        string cur = "1", next;
        while (--N) {
            for (auto i{ 0 }, j{ 0 }; i < cur.size(); i = j) {
                for (j = i + 1; j < cur.size() && cur[j - 1] == cur[j]; ++j);
                next.push_back('0' + (j - i)), next.push_back(cur[i]); // cnt, val
            }
            cur = next, next.clear();
        }
        return cur;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
