/*
 * 731. My Calendar II
 *
 * Q: https://leetcode.com/problems/my-calendar-ii/
 * A: https://leetcode.com/problems/my-calendar-ii/discuss/739642/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <map>

using namespace std;

class MyCalendarTwo {
    using Map = map<int, int>;
    Map m;
public:
    bool book(int i, int j, int bookings = 0) {
        ++m[i]; // add candidate booking [i..j)
        --m[j];
        for (auto [time, cnt]: m) { // ⭐️ linear scan from beginning to accumulate existing bookings
            if (j <= time) // ✅ time exceeds the [i..j) interval
                break;
            if (2 < (bookings += cnt)) { // ❌ 2 bookings exceeded
                --m[i];
                ++m[j];
                return false; // 🚫 candidate booking [i..j) failure, remove candidate and return false
            }
        }
        return true; // ✅ candidate booking [i..j) success, keep candidate and return true
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
