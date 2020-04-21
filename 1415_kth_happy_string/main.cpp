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
public:
    using VS = vector<string>;
    string getHappyString(int N, int K, VS happy = {}) {
        go(happy, N);
        if (happy.size() >= K)
            return happy[K - 1]; // -1 for 0-based index 🎯
        return {};
    }
private:
    void go(VS& happy, int chars, string&& S = {}) {
        if (chars == 0) {
            happy.push_back(S);
            return;
        }
        for (auto c: string{"abc"}) {
            if (!S.empty() && c == S.back())
                continue; // not a happy string ❌
            S.push_back(c);
            go(happy, chars - 1, move(S));
            S.pop_back();
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
