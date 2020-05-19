/*
 * 1451. Rearrange Words in a Sentence
 *
 * Q: https://leetcode.com/problems/rearrange-words-in-a-sentence/
 * A: https://leetcode.com/problems/rearrange-words-in-a-sentence/discuss/640637/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string arrangeWords(string text, vector<string> A = {}, string ans = {}) {
        text[0] = tolower(text[0]);
        istringstream is{ text };
        copy(istream_iterator<string>(is), istream_iterator<string>(), back_inserter(A));
        stable_sort(A.begin(), A.end(), [](auto& a, auto& b) { return a.size() < b.size(); });
        A[0][0] = toupper(A[0][0]);
        for_each(A.begin(), A.end(), [&](auto& word) { ans.append(word).append(" "); });
        ans.pop_back(); // remove trailing whitespace
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
