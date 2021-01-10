/*
 * 1720. Decode XORed Array
 *
 * Q: https://leetcode.com/problems/decode-xored-array/
 * A: https://leetcode.com/problems/decode-xored-array/discuss/1009766/Kt-Js-Py3-Cpp-XOR-Last
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI decode(VI& A, int K) {
        VI ans{ K };
        for (auto x: A)
            ans.push_back(x ^ ans.back());
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
