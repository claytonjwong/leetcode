/*
 * 1118. Number of Days in a Month
 *
 * Q: https://leetcode.com/problems/number-of-days-in-a-month/
 * A: https://leetcode.com/problems/number-of-days-in-a-month/discuss/603836/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfDays(int Y, int M) {
        switch (M) {
            case 2:
                return (Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0)) ? 29 : 28;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            default:
                break;
        }
        return 31;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
