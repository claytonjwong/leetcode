/*
 * Weekly Contest 171
 *
 * https://leetcode.com/contest/weekly-contest-171/ranking/35/
 *
 * Rank	        Name	        Score	Finish Time 	Q1 (3)	    Q2 (4)	    Q3 (5)	    Q4 (7)
 * 867 / 7189	claytonjwong 	12	    0:33:15	        0:06:46	    0:16:28	    0:33:15
 *
 * Q1: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
 * A1: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/discuss/477795/Javascript-and-C%2B%2B-solutions
 *
 * Q2: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 * A2: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/discuss/477794/Javascript-and-C%2B%2B-solutions
 *
 * Q3: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
 * A3: https://leetcode.com/problems/number-of-operations-to-make-network-connected/discuss/477783/Javascript-and-C%2B%2B-solutions
 *
 * Q4:
 * A4:
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int makeConnected(int N, VVI& connections, int same = 0) {
        generate_n(back_inserter(P), N, [i = -1]() mutable { return ++i; });
        for (auto& c: connections)
            same += join(c[0], c[1]);
        for (auto i = 0; i < N; ++i)
            find(i);
        auto K = set<int>{P.begin(), P.end()}.size() - 1;
        cout << K << endl;
        cout << same << endl;
        if (same >= K)
            return K;
        return -1;
    }
private:
    VI P;
    int find(int x) {
        if (P[x] == x)
            return P[x];
        return P[x] = find(P[x]);
    }
    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return true;
        P[a] = b; // arbitrary choice
        return false;
    }
};

int main() {


    return 0;
}
