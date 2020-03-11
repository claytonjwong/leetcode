/*
 * 1374. Generate a String With Characters That Have Odd Counts
 *
 * Q: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
 * A: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/discuss/534703/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

//class Solution {
//public:
//    string generateTheString(int N, string ans = {}) {
//        fill_n(back_inserter(ans), N - 1, 'a');
//        ans.push_back(N % 2 ? 'a' : 'b');
//        return ans;
//    }
//};

class Solution {
public:
    string generateTheString(int N) {
        return string(N - 1, 'a') + (N % 2 ? 'a' : 'b');
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
