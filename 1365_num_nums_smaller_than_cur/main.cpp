/*
 * 1365. How Many Numbers Are Smaller Than the Current Number
 *
 * Q: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
 * A: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/discuss/526057/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    using VI = vector<int>;
//    VI smallerNumbersThanCurrent(VI& A) {
//        int N = A.size();
//        VI ans(N);
//        for (auto i = 0; i < N; ++i)
//            for (auto j = 0; j < N; ++j)
//                if (i != j && A[i] > A[j])
//                    ++ans[i];
//        return ans;
//    }
//};

//class Solution {
//public:
//    using VI = vector<int>;
//    VI smallerNumbersThanCurrent(VI& A, VI cnt = VI(101), VI ans = {}) {
//        for (auto x: A)
//            ++cnt[x];
//        for (auto i = 1; i < cnt.size(); ++i)
//            cnt[i] += cnt[i - 1];
//        for (auto x: A)
//            ans.push_back(x == 0 ? 0 : cnt[x - 1]);
//        return ans;
//    }
//};

//class Solution {
//public:
//    using VI = vector<int>;
//    using Set = multiset<int>;
//    VI smallerNumbersThanCurrent(VI& A, VI ans = {}) {
//        Set S{A.begin(), A.end()};
//        for (auto x: A)
//            ans.push_back(distance(S.begin(), S.find(x)));
//        return ans;
//    }
//};

class Solution {
public:
    using VI = vector<int>;
    using Set = multiset<int>;
    using Map = unordered_map<int, int>;
    VI smallerNumbersThanCurrent(VI& A, Map m = {}, VI ans = {}) {
        Set S{A.begin(), A.end()};
        for (auto it = S.begin(); it != S.end(); ++it)
            if (m.find(*it) == m.end())
                m[*it] = distance(S.begin(), it);
        for (auto x: A)
            ans.push_back(m[x]);
        return ans;
    }
};

int main() {
    return 0;
}