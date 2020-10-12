/*
 * 859. Buddy Strings
 *
 * Q: https://leetcode.com/problems/buddy-strings/
 * A: https://leetcode.com/problems/buddy-strings/discuss/141769/Kt-Js-Py3-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Set = unordered_set<char>;
    bool buddyStrings(string A, string B) {
        int M = A.size(),
            N = B.size();
        if (M != N)
            return false;
        if (A == B)
            return Set{ A.begin(), A.end() }.size() < N;
        auto j = -1,
             k = -1;
        for (auto i{ 0 }; i < N; ++i)
            if (A[i] != B[i])
                j = k, k = i;
        if (j == -1 || k == -1)
            return false;
        swap(A[j], A[k]);
        return A == B;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
