/*
 * https://leetcode.com/contest/weekly-contest-153
 * Weekly Contest 153
 * Sep 08, 2019 at 5:09 AM
 * 1 h 30 m	3/19	0:24:33	1/4	2981/4781
 *
 * Q1: https://leetcode.com/problems/distance-between-bus-stops/
 * A1: https://leetcode.com/problems/distance-between-bus-stops/discuss/377809/C%2B%2B-Solutions
 *
 * Q2: https://leetcode.com/problems/day-of-the-week/
 * A2: https://leetcode.com/problems/day-of-the-week/discuss/377802/C%2B%2B-Solution
 *
 * Q3: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
 * A3: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/discuss/380747/C%2B%2B-Solution
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <numeric>

using namespace std;

/*
 * let i == start index
 *     j == end index
 *
 * the answer is the minimum of the clockwise traversal i to j and the counter-clockwise traversal j to i
 * the cost to go clockwise from i to i+1 is distance[i]
 * the cost to go counter-clockwise from i to i-1 is distance[i-1]
 */

/*
//class Solution {
//public:
//    int distanceBetweenBusStops(vector<int>& A, int i, int j) {
//        if (j < i) {
//            swap(i, j);
//        }
//        return min(accumulate(A.begin() + i, A.begin() + j, 0), accumulate(A.begin() + j, A.end(), 0) + accumulate(A.begin(), A.begin() + i, 0));
//    }
//};

//class Solution {
//public:
//    using VI = vector<int>;
//    int distanceBetweenBusStops(VI& A, int i, int j) {
//        return j < i ? distanceBetweenBusStops(A, j, i) : min(clockwise(A, i, j), counter_clockwise(A, i, j));
//    }
//private:
//    int clockwise(const VI& A, int i, int j) {
//        return accumulate(A.begin() + i, A.begin() + j, 0);
//    }
//    int counter_clockwise(const VI& A, int i, int j) {
//        return accumulate(A.begin() + j, A.end(), 0) + accumulate(A.begin(), A.begin() + i, 0);
//    }
//};

//class Solution {
//public:
//    using VI = vector<int>;
//    int distanceBetweenBusStops(VI& A, int i, int j) {
//        if (j < i) {
//            swap(i, j);
//        }
//        auto clockwise = [&](int i, int j) {
//            return accumulate(A.begin() + i, A.begin() + j, 0);
//        };
//        auto counter_clockwise = [&](int i, int j) {
//            return accumulate(A.begin() + j, A.end(), 0) + accumulate(A.begin(), A.begin() + i, 0);
//        };
//        return min(clockwise(i, j), counter_clockwise(i, j));
//    }
//};

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& A, int i, int j) {
        if (j < i) {
            swap(i, j);
        }
        auto beg = A.begin() + i,
             end = A.begin() + j;
        return min(accumulate(beg, end, 0), accumulate(end, A.end(), 0) + accumulate(A.begin(), beg, 0));
    }
};

int main() {
    vector<int> A{
        1,2,3,4
    };
    Solution solution;
    cout << solution.distanceBetweenBusStops(A, 0, 1) << endl;
    cout << solution.distanceBetweenBusStops(A, 0, 2) << endl;
    cout << solution.distanceBetweenBusStops(A, 0, 3) << endl;
    return 0;
}
*/

/*
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) { // https://en.wikipedia.org/wiki/Zeller%27s_congruence#Implementation_in_software
        if (month < 3) {
            month += 12;
            --year;
        }
        auto q = day,
             m = month,
             K = year % 100,
             J = year / 100,
             h = q + (13 * (m + 1) / 5) + K + (K / 4) + (J / 4) + (5 * J);
        return vector<string>{"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"}[(h + 5) % 7];
    }
};

int main() {
    Solution solution;
    cout << solution.dayOfTheWeek(1, 1, 2000) << endl;
    cout << solution.dayOfTheWeek(1, 3, 2000) << endl;
    cout << solution.dayOfTheWeek(31, 8, 2019) << endl;
    cout << solution.dayOfTheWeek(18, 7, 1999) << endl;
    cout << solution.dayOfTheWeek(15, 8, 1993) << endl;
    return 0;
}
*/


/*

 for k=1 to N inclusive
    for i=0 to N-k inclusive
        calculate sum of subarray from i to i+k inclusive
        and keep track of the minimal value seen in the subarray

        if the minimal value seen is negative, then subtract that negative value from the subarray sum ( ie. add value to sum to "remove" the negative number )
        if ans < sum
           ans = sum

 */

// TLE
/*
**Naive Algorithm:**

* Calculate the sum of each sum-array of size k from 1 to N inclusive and return the maximum sum
    * If k is greater than 1, then optionally delete the smallest negative number from the sub-array sum

**Runtime:** O(N^2)
*/
/*
class Solution {
public:
    static constexpr auto INF = static_cast<int>(1e4+1);
    int maximumSum(vector<int>& A, int ans=-INF) {
        auto N = static_cast<int>(A.size());
        for (auto k=1; k <= N; ++k) {
            for (auto i=0; i <= N-k; ++i) {
                auto beg = A.begin() + i,
                    end = A.begin() + i + k;
                auto sum = accumulate(beg, end, 0),
                    min = *min_element(beg, end);
                if (k > 1 && min < 0) {
                    sum -= min; // "remove" minimum negative number from the sum
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};
*/

// Question: how to make this faster?

/*
**Synopsis:**

Use a varation of [Kadane's Algorithm](https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm) to find the maximum subarray sum with one deletion:

* Calculate the max sub-array sums in forward (left -> right) and reverse (right -> left) directions
    * the forward max sub-array sums for each i-th index represents the max sub-array sum *ending* at index i
* the reverse max sub-array sums for each i-th index represents the max sub-array sum *beginning* at index i

**Note:** while calculating the sums also keep track of the max sub-array sum with no deletions

    * Iterate once through the array and use pre-calculated sums to check if there exists a larger sum with one deletion

**Runtime:** O(N)
*/
class Solution {
public:
    static constexpr auto INF = static_cast<int>(1e4+1);
    using VI = vector<int>;
    int maximumSum(VI& A, int sum=0, int ans=-INF) {
        auto N = static_cast<int>(A.size());
        VI end(N), beg(N);
        end[0] = sum = ans = A[0]; // forward
        for (auto i=1; i < N; ++i) {
            end[i] = sum = max(A[i], sum + A[i]); // new sub-array or append to existing sub-array, whichever is maximal
            ans = max(ans, sum);
        }
        beg[N-1] = sum = A[N-1]; // reverse
        for (auto i=N-2; i >= 0; --i) {
            beg[i] = sum = max(A[i], sum + A[i]); // new sub-array or append to existing sub-array, whichever is maximal
            ans = max(ans, sum);
        }
        for (auto i=1; i+1 < N; ++i) { // use pre-calculated sums to check if there exists a larger sum with one deletion
            sum = end[i-1] + beg[i+1];
            ans = max(ans, sum);
        }
        return ans;
    }
};

int main() {
    vector<int> A{
        -1,-1,-1,-1,-1
    };
    Solution solution;
    cout << solution.maximumSum(A) << endl;
    return 0;
}

//int main() {
//    Solution solution;
//    return 0;
//}
