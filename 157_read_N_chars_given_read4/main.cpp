/*
 * 157. Read N Characters Given Read4
 *
 * Q: https://leetcode.com/problems/read-n-characters-given-read4/
 * A: https://leetcode.com/problems/read-n-characters-given-read4/discuss/573173/Javascript-Python3-C%2B%2B-read-next-%2B-write-to-buf
 */

#include <iostream>

using namespace std;

int read4(char*); // forward declaration

class Solution {
public:
    int read(char *buf, int N, int k = 0, int write = 0) {
        do {
            char next[4];
            k = read4(next);
            for (auto i{ 0 }; i < k && write < N; ++i)
                buf[write++] = next[i];
        } while (k && write < N);
        return write;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
