/*
Given two sorted arrays of integers, find the intersection.

Example:
a1: [1, 5, 5, 8, 9, 30, 100], size = n
a2: [5, 5, 9, 21, 25], size = m
Output: [5, 9]
*/

// O(m + n)
  
// n>>m
// O(n)

// A is really big

// B is small

// iterate through each element of B
//   binary search on A for that element  <--- efficient
  
  
// m * log(n)
  
using VI = vector<int>;

// VI f(const VI& A, const VI& B) {
//   VI ans;
//   for (int i = 0, j = 0; i < A.size() && j < B.size(); ) {
//     if (A[i] == B[j]) {
//       if (abs.back() != A[i)
//         ans.push_back(A[i]),
//       ++i, ++j;
//     }
//     if (A[i] < B[j])
//       ++i;
//     else
//       ++j;
//   }
//   return ans;
// }


// mid = 0 +9 / 2 = 4
// mid = 0 + 4 / 2 = 2

//   mid = 4 + 9 / 2 = 6
  
// A = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//     i
//                                j
//                 i
//                       j
//                    k
                 
              
              
// B = 3, 5, 6

  
  

// bool binary_search(const VI& A, int target) {
//   auto lo = 0, hi = static_cast<int>(A.size()) - 1;
//   while (lo <= hi) {
//     int mid = (hi + lo) / 2;
//     if (A[mid] == target)
//       return true;
//     if (target < A[mid])
//       hi = mid - 1;
//     else // target > A[mid]
//       lo = mid + 1;
//   }
//   return false;
// }

// VI f(const VI& A, const VI& B) {
//   VI ans;
//   for (auto x: B) {
//     if (binary_search(A, x))
//       ans.push_back(x);
//   }
//   return ans;
// }
