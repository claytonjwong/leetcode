/*
 * 252. Meeting Rooms
 *
 * Q: https://leetcode.com/problems/meeting-rooms/
 * A: https://leetcode.com/problems/meeting-rooms/discuss/919342/Kt-Js-Py3-Cpp-Sort-%2B-Scan
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    bool canAttendMeetings(VVI& A, int last = 0) {
        sort(A.begin(), A.end());
        for (auto& meeting: A) {
            auto [i, j] = tie(meeting[0], meeting[1]);
            if (!(last <= i))
                return false;
            last = j;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
