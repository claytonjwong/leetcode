// 442. Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// O(N) mem
namespace LinearMem {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        VI findDuplicates(VI& A, Set seen = {}, VI ans = {}) {
            for (auto x: A)
                if (!seen.insert(x).second)
                    ans.push_back(x);
            return ans;
        }
    };
}

// O(1) mem by adding N onto the index corresponding to each value in A, only values seen twice exceed 2 * N
namespace ConstMem {
    class Solution {
    public:
        using VI = vector<int>;
        VI findDuplicates(VI& A, VI ans = {}) {
            auto N = A.size();
            for (auto i: A) {
                while (N < i)
                    i -= N;
                A[i - 1] += N;            // -1 for 0-based indexing
            }
            for (auto i{ 0 }; i < N; ++i)
                if (2 * N < A[i])
                    ans.push_back(i + 1); // +1 for 1-based indexing
            return ans;
        }
    };
}

int main() {
    ConstMem::Solution solution;
    ConstMem::Solution::VI A{ 4,3,2,7,8,2,3,1 };
    auto ans = solution.findDuplicates(A);
    return 0;
}
