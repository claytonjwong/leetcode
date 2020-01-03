#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        deque<int> A{nums.begin(),  nums.end()};
        A.push_front(numeric_limits<int>::min()), A.push_back(numeric_limits<int>::min());
        for (auto i = 1; i + 1 < A.size(); ++i)
            if (A[i - 1] < A[i] && A[i] > A[i + 1])
                return i - 1;
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> A{1,2,3};
    cout << solution.findPeakElement(A) << endl;

    return 0;
}
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        unordered_set<char> u{s.begin(), s.end()};
        if (u.size() == 1)
            return s.size() > 1;
        for (auto k = 2; k <= n / 2; ++k) {
            if (n % k) // only consider evenly divisible k
                continue;
            auto target = s.substr(0, k);
            bool ok = true;
            for (auto i = k; i + k <= s.size(); i += k) {
                if (s.substr(i, k) != target) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.repeatedSubstringPattern("babbabbabbabbab") << endl;
    return 0;
}
