/*
 * 1656. Design an Ordered Stream
 *
 * Q: https://leetcode.com/problems/design-an-ordered-stream/
 * A: https://leetcode.com/problems/design-an-ordered-stream/discuss/947961/Kt-Js-Py3-Cpp-Array
 */

#include <iostream>
#include <vector>

using namespace std;

class OrderedStream {
    using VS = vector<string>;
    int i, N;
    VS A;
public:
    OrderedStream(int N) : i{ 0 }, N{ N }, A(N) {}
    VS insert(int k, string value, VS res = {}) {
        A[k - 1] = value;  // -1 for 0-based indexing
        while (i < N && !A[i].empty())
            res.push_back(A[i++]);
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
