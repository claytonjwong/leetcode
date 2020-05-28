/*
 * Google- Online Assessment
 * Completed May 27, 2020 6:04 PM
 * Time Spent: 10 minutes 53 seconds
 * Time Allotted: 1 hour
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 551. Student Attendance Record I
 *
 * Q: https://leetcode.com/problems/student-attendance-record-i/
 * A: https://leetcode.com/problems/student-attendance-record-i/discuss/596959/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        bool checkRecord(string S) {
            return count_if(S.begin(), S.end(), [](auto c) { return c == 'A'; }) <= 1 && S.find("LLL") == string::npos;
        }
    };
}

/*
 * 743. Network Delay Time
 *
 * Q: https://leetcode.com/problems/network-delay-time/
 * A: https://leetcode.com/problems/network-delay-time/discuss/656011/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int networkDelayTime(VVI& E, int N, int K, int INF = 1e9 + 7) {
            VI dist(N + 1, INF); // +1 for 1-based indexing
            dist[K] = 0;
            while (--N) {
                for (auto& edge: E) {
                    auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
                    if (dist[v] > dist[u] + w)
                        dist[v] = dist[u] + w;
                }
            }
            auto max = *max_element(dist.begin() + 1, dist.end()); // +1 to exclude sentinel at index 0
            return max < INF ? max : -1;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
