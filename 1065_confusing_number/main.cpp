/*
 * 1056. Confusing Number
 *
 * Q: https://leetcode.com/problems/confusing-number/
 * A: https://leetcode.com/problems/confusing-number/discuss/603611/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool confusingNumber(int N) {
        deque<int> a, b; // a == N, b == rotated-N
        while (N) {
            auto x = N % 10;
            if (invalid.find(x) != invalid.end())
                return false;
            a.push_back(x), b.push_front(rotate[x]);
            N /= 10;
        }
        return a != b;
    }
private:
    unordered_set<int> invalid{ 2, 3, 4, 5, 7 };
    unordered_map<int, int> rotate{ {0, 0}, {1, 1}, {8, 8}, {6, 9}, {9, 6} };
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
