/*
 * 1324. Print Words Vertically
 *
 * Q: https://leetcode.com/problems/print-words-vertically/
 * A: https://leetcode.com/problems/print-words-vertically/discuss/485298/Javascript-Python3-C%2B%2B-Straightforward-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    VS printVertically(string s, VS ans = {}) {
        istringstream stream{ s };
        VS A{ istream_iterator<string>(stream), istream_iterator<string>() };
        int N = A.size(),
            K = 0;
        for (auto& word: A)
            K = max(K, int(word.size()));
        for (auto& word: A)
            while (word.size() < K)
                word.push_back(' ');
        for (auto j{ 0 }; j < K; ++j) {
            string word;
            for (auto i{ 0 }; i < N; ++i)
                word.push_back(A[i][j]);
            while (word.back() == ' ')
                word.pop_back();
            ans.emplace_back(word);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
