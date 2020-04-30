/*
 * 1078. Occurrences After Bigram
 *
 * Q: https://leetcode.com/problems/occurrences-after-bigram/
 * A: https://leetcode.com/problems/occurrences-after-bigram/discuss/603664/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    VS findOcurrences(string text, string first, string second, VS A = {}, VS ans = {}) {
        istringstream is{ text };
        copy(istream_iterator<string>(is), istream_iterator<string>(), back_inserter(A));
        for (auto i{ 2 }; i < A.size(); ++i)
            if (A[i - 2] == first && A[i - 1] == second)
                ans.push_back(A[i]);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
