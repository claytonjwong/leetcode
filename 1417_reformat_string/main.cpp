/*
 * 1417. Reformat The String
 *
 * Q: https://leetcode.com/problems/reformat-the-string/
 * A: https://leetcode.com/problems/reformat-the-string/discuss/586472/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string reformat(string S, string letters = {}, string digits = {}, string ans = {}) {
        copy_if(S.begin(), S.end(), back_inserter(letters), [](auto c) { return isalpha(c); });
        copy_if(S.begin(), S.end(), back_inserter(digits), [](auto c) { return isdigit(c); });
        if (abs(int(letters.size()) - int(digits.size())) > 1)
            return {};
        auto N = letters.size() + digits.size();
        auto turn = letters.size() >= digits.size() ? 0 : 1; // 0 == letters first  1 == digits first
        for (auto i{ 0 }, j{ 0 }, k{ 0 }; i < N; ++i)
            if (i % 2 == turn)
                ans.push_back(letters[j++]);
            else
                ans.push_back(letters[k++]);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
