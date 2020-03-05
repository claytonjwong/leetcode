/*
 * 1352. Product of the Last K Numbers
 *
 * Q: https://leetcode.com/problems/product-of-the-last-k-numbers/
 * A: https://leetcode.com/problems/product-of-the-last-k-numbers/discuss/529936/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

/*

productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]

observe that if there exists a single 0 in the last K, then the product is 0

i can use a set to track the indexes of 0 values

i know there are up to K = 40,000 instructions, so i can pre-allocate another array for
pre-computing products?  maybe similar to prefix sums for O(1) lookups?

With 0 is more complicated? Start without 0 use case:

A  = 3  2  5  4
dp = 3  6 30 120
     0  1  2  3  4

come up with a formula...

let's say we want the last 3: ie. 2 * 5 * 4 = 40

k = 3

A[N - 1] / A[N - 1 - k] => (N - 1) / (N - 4)
                      =>     120 / 3 = 40

N = 3
k = 2

A[2] / A[0]

so yes indeed (prefix sums style dp computation works for O(1) lookups)

so each time a new number is added, simply multiply the last dp value by the number and push onto the back of dp array

OK, so back to 0 -- if 0 exists in the last k, then the answer is 0.
so the question is how do i determine if 0 exists in the last k digits?

we can simply keep track of the index of right-most zero

or more simply, we can truncate all of A and remember the first digit in A is "zero"
(this is a pseudo-value, since I never want to actually insert 0 into A to avoid dividing by 0)

*/

//class ProductOfNumbers {
//public:
//    ProductOfNumbers() : zero{false}, A{1} {} // use 1 as a sentinel value
//    void add(int x) {
//        if (x == 0) {
//            A.clear();
//            A.push_back(1);
//            zero = true;
//            return;
//        }
//        A.push_back(A.back() * x);
//    }
//    int getProduct(int k) {
//        int N = A.size();
//        if (zero && k >= N) // if zero flag is set, the pseudo-value of 0 exists at index 0
//            return 0;
//        return A[N - 1] / A[N - 1 - k];
//    }
//private:
//    bool zero;
//    vector<int> A;
//};

class ProductOfNumbers {
public:
    ProductOfNumbers() : A{1} {} // use 1 as a sentinel value
    void add(int x) {
        if (x == 0) {
            A.clear();
            A.push_back(1);
            return;
        }
        A.push_back(A.back() * x);
    }
    int getProduct(int k) {
        int N = A.size();
        if (k >= N) // the "pseudo-value" of 0 exists at index 0
            return 0;
        return A.back() / A[N - 1 - k];
    }
private:
    vector<int> A;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
