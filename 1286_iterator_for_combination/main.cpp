/*
 * 1286. Iterator for Combination
 *
 * Q: https://leetcode.com/problems/iterator-for-combination/
 * A: https://leetcode.com/problems/iterator-for-combination/discuss/789522/Javascript-Python3-C%2B%2B-Recursive-DFS-%2B-BT
 */

#include <iostream>
#include <vector>

using namespace std;

class CombinationIterator {
    string A;
    int K, i;
    vector<string> combos;
    void go(int i = 0, string&& path = {}) {
        if (path.size() == K) {
            combos.push_back(path);
            return;
        }
        if (i == A.size())
            return;
        go(i + 1, path + A[i]);  // ✅ with A[i]
        go(i + 1, move(path));   // 🚫 without A[i]
    }
public:
    CombinationIterator(string A, int K) : A{ A }, K{ K }, i{ 0 } {
        go();
    }
    string next() {
        return combos[i++];
    }
    bool hasNext() {
        return i < combos.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
