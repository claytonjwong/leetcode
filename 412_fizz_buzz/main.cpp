/*
 * 412. Fizz Buzz
 *
 * Q: https://leetcode.com/problems/fizz-buzz/
 * A: https://leetcode.com/problems/fizz-buzz/discuss/812833/Javascript-Python3-C%2B%2B-1-Liners
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    VS fizzBuzz(int N, VS ans = {}) {
        for (auto i{ 1 }; i <= N; ++i)
            if (!(i % 3) && !(i % 5)) ans.emplace_back("FizzBuzz");
            else if (!(i % 3))        ans.emplace_back("Fizz");
            else if (!(i % 5))        ans.emplace_back("Buzz");
            else                      ans.emplace_back(to_string(i));
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
