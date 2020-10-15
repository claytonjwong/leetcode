/*
 * 253. Meeting Rooms II
 *
 * Q: https://leetcode.com/problems/meeting-rooms-ii/
 * A: https://leetcode.com/problems/meeting-rooms-ii/discuss/895910/Kt-Js-Py3-Cpp-Maximum-Overlap-via-Map
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = map<int, int>;
    int minMeetingRooms(VVI& A, Map m = {}, int overlap = 0, int maximum = 0) {
        for (auto& interval: A) {
            auto [i, j] = tie(interval[0], interval[1]);
            ++m[i];
            --m[j];
        }
        for (auto [_, x]: m)
            maximum = max(maximum, overlap += x);
        return maximum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
