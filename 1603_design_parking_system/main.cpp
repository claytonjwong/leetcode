/*
 * 1603. Design Parking System
 *
 * Q: https://leetcode.com/problems/design-parking-system/
 * A: https://leetcode.com/problems/design-parking-system/discuss/876790/Javascript-Python3-C%2B%2B-Concise-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class ParkingSystem {
    using VI = vector<int>;
    VI A;
public:
    ParkingSystem(int a, int b, int c) : A{ 0, a, b, c } {}
    bool addCar(int x) {
        if (!A[x])
            return false;
        --A[x];
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
