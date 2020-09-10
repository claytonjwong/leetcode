/*
 * 299. Bulls and Cows
 *
 * Q: https://leetcode.com/problems/bulls-and-cows/
 * A: https://leetcode.com/problems/bulls-and-cows/discuss/402832/Javascript-Python3-C%2B%2B-Map-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    string getHint(string A, string B, int bull = 0, int cow = 0) {
        VI first(10), second(10);
        for (auto i{ 0 }; i < A.size(); ++i)
            if (A[i] == B[i])
                ++bull;                  // case 1: same digit, increment bull
            else
                ++first[A[i] - '0'],     // case 2: diff digit, increment corresponding digit count
                ++second[B[i] - '0'];
        for (auto i{ 0 }; i < 10; ++i)
            cow += min(first[i], second[i]);
        ostringstream hint;
        hint << bull << "A"
             << cow  << "B";
        return hint.str();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
