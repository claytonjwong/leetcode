/*
 * 278. First Bad Version
 *
 * Q: https://leetcode.com/problems/first-bad-version/
 * A: https://leetcode.com/problems/first-bad-version/discuss/527936/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

bool isBadVersion(int x) {
    return x >= 1;
}

//class Solution {
//public:
//    int firstBadVersion(int n) {
//        return go(1, n);
//    }
//private:
//    using LL = long long;
//    int go(LL i, LL j) {
//        LL k = (i + j) / 2;
//        if (isBadVersion(k)) {
//            if (k == 1 || !isBadVersion(k - 1))
//                return k;
//            return go(i, k - 1);
//        }
//        else {
//            return go(k + 1, j);
//        }
//    }
//};

class Solution {
public:
    using LL = long long;
    int firstBadVersion(int n) {
        LL i = 1, j = n;
        while (i < j) {
            auto k = (i + j) / 2;
            if (isBadVersion(k)) {
                j = k;
            } else {
                i = k + 1;
            }
        }
        return i;
    }
};

int main() {
    Solution solution;
    cout << solution.firstBadVersion(5) << endl;
    return 0;
}
