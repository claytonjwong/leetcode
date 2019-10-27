/*

 1213. Intersection of Three Sorted Arrays

 Q1: https://leetcode.com/problems/intersection-of-three-sorted-arrays/
 A1: https://leetcode.com/problems/intersection-of-three-sorted-arrays/discuss/400502/C%2B%2B-Solutions

 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

//class Solution {
//public:
//    using VI = vector<int>;
//    VI arraysIntersection(VI& A, VI& B, VI& C, VI ans={}) {
//        copy_if(A.begin(), A.end(), back_inserter(ans), [&](auto x){
//            return binary_search(B.begin(), B.end(), x) &&
//                   binary_search(C.begin(), C.end(), x);
//        });
//        return ans;
//    }
//};
//
//class Solution {
//public:
//    using VI = vector<int>;
//    using Seen = set<int>;
//    VI arraysIntersection(VI& A, VI& B, VI& C, VI ans={}) {
//        Seen seen_B{B.begin(), B.end()},
//            seen_C{C.begin(), C.end()};
//        copy_if(A.begin(), A.end(), back_inserter(ans), [&](auto x){
//            return seen_B.find(x) != seen_B.end() &&
//                   seen_C.find(x) != seen_C.end();
//        });
//        return ans;
//    }
//};

class Solution {
public:
    using VI = vector<int>;
    VI arraysIntersection(VI& A, VI& B, VI& C, VI D={}, VI E={}) {
        set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(D));
        set_intersection(C.begin(), C.end(), D.begin(), D.end(), back_inserter(E));
        return E;
    }
};

int main() {


    return 0;
}