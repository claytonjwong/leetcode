/*
 * 702. Search in a Sorted Array of Unknown Size
 *
 * Q: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
 * A: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/discuss/906120/Kt-Js-Py3-Cpp-Binary-Search
 */

#include <iostream>

using namespace std;

struct ArrayReader {
    int get(int i) const;
};

class Solution {
public:
    int search(const ArrayReader& reader, int T) {
        auto i = 0,
             j = 10000;
        while (i < j) {
            auto k = (i + j) / 2;
            auto cand = reader.get(k);
            if (cand == T)
                return k;
            if (cand < T)
                i = k + 1;
            else
                j = k;
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
