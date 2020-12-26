/*
 * 1700. Number of Students Unable to Eat Lunch
 *
 * Q: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
 * A: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/discuss/987305/Kt-Js-Py3-Cpp-Do-we-HAVE-what-we-NEED
 */

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Deque = deque<int>;
    using Map = unordered_map<int, int>;
    int countStudents(VI& A, VI& B, Map m = {}) {
        Deque need{ A.begin(), A.end() },
              have{ B.begin(), B.end() };
        for (auto x: need)
            ++m[x];
        while (have.size() && 0 < m[have[0]]) {
            if (need[0] != have[0]) {
                need.push_back(need.front()), need.pop_front();
                continue;
            }
            --m[have[0]];
            need.pop_front();
            have.pop_front();
        }
        return need.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
