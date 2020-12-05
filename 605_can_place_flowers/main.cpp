/*
 * 605. Can Place Flowers
 *
 * Q: https://leetcode.com/problems/can-place-flowers/
 * A: https://leetcode.com/problems/can-place-flowers/discuss/103899/Kt-Js-Py3-Cpp-Greedy-Linear-Scan
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool canPlaceFlowers(VI& A, int K) {
        int N = A.size();
        if (!K) return true;
        if (!N) return false;
        if (N == 1) return !A[0] && K == 1;
        auto plant = [&](auto i) { A[i] = 1, --K; };
        if (!A[0] & !A[1])
            plant(0);                           // 🌸 👈 left-most position 0
        for (auto i{ 1 }; i + 1 < N; ++i)
            if (!A[i - 1] & !A[i] & !A[i + 1])
                plant(i);                       // 👉 🌸 👈 middle positions 1..N - 2
        if (!A[N - 2] && !A[N - 1])
            plant(N - 1);                       // 👉 🌸 right-most position N - 1
        return K <= 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
