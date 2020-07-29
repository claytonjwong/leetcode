/*
 * 1415. The k-th Lexicographical String of All Happy Strings of Length n
 *
 * Q: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
 * A: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/discuss/589380/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    string ans;
    int N, K;
    void go(int i = 0, string&& path = {}) {
        if (!K)
            return;
        if (i == N) {
            if (!--K)
                ans = path; // 🎯 K-th happy string
            return;
        }
        for (auto c: string{ "abc" })
            if (path.empty() || c != path.back())
                path.push_back(c),     // 👀 ✅ path forward-tracking
                go(i + 1, move(path)), // 🚀 DFS explore path
                path.pop_back();       // 👀 🚫 path back-tracking
    }
public:
    string getHappyString(int N_, int K_) {
        N = N_;
        K = K_;
        go();
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
