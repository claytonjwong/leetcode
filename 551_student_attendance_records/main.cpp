/*
 * 551. Student Attendance Record I
 *
 * Q: https://leetcode.com/problems/student-attendance-record-i/
 * A: https://leetcode.com/problems/student-attendance-record-i/discuss/596959/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkRecord(string S) {
        return count_if(S.begin(), S.end(), [](auto c) { return c == 'A'; }) <= 1 && S.find("LLL") == string::npos;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
