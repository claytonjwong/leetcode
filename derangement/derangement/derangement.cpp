/*
 
 634. Find the Derangement of An Array
 
 https://leetcode.com/problems/find-the-derangement-of-an-array/description/
 
 In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.
 
 There's originally an array consisting of n integers from 1 to n in ascending order, you need to find the number of derangement it can generate.
 
 Also, since the answer may be very large, you should return the output mod 109 + 7.
 
 Example 1:
 Input: 3
 Output: 2
 Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
 Note:
 n is in the range of [1, 106].
 
 
 Solution:
 
 https://discuss.leetcode.com/topic/102738/very-easy-to-understand-c-with-explanation
 
 The subfactorial function can be used to calculate the amount of derangements as follows:
 
 !n=(n-1)( !(n-1) + !(n-2) )
 
 Let's break this formula down into individual parts for simple and easy understanding:
 
 Part 0: !n=(n-1)( !(n-1) + !(n-2) )
 
 This part of the equation is basically just the way we refer to the subfactorial function of N. Let's create a function name d(n) such that d(n)=!n, then we can write this formula as follows with the same meaning, but instead of a leading "!", we have a leading function name "d":
 
 d(n)=(n-1)( d(n-1) + d(n-2) )
 
 Part 1: d(n)=(n-1)( d(n-1) + d(n-2) )
 
 We know by definition of a derangement, there are (N-1) possible repositions available for any arbitrary i-th position in an array from 1 to N inclusive: [1,2,3,...,N-2,N-1,N]. This is because there are N numbers, and any arbitrary i-th position is allowed to be repositioned into any of those N positions EXCEPT for the i-th position.
 
 Let's stop here and look at a simple example where N=2. For N=2, there are two elements in the array [1,2]. There are (N-1) possible repositions available. For N=2, (N-1)=(2-1)=1. That 1 position is available for each of these N numbers. That is the reason why this formula multiples by (N-1). 1 can be moved into 2's position, and 2 can be moved into 1's position:
 
 Before derangement: [1,2]
 After derangement: [2,1]
 
 There is only one derangement when N=2. We will build the base case from this example of N=2 after describing the recursive case in Part 2 below. This will soon be referred to as d(2) when discussing the base cases in part 3 below.
 
 Part 2 - Recursive Cases: d(n)=(n-1)( d(n-1) + d(n-2) )
 
 This section describes the recursive case. After we have chosen an arbitrary i-th position, that i-th position can either 1) be repositioned into the first position, or it can 2) be repositioned into any other position EXCEPT the first position.
 
 Case 1: if the i-th position is repositioned into the first position, then this can be done by swapping position 1 with position i:
 
 Before swap: [ 1, . . . , i, . . . , N ]
 After swap: [ i, . . . , 1, . . . , N ]
 
 So for this case, there are 2 set positions, position 1 is set to i, and position i is set to 1. Then there are N-2 positions to be deranged leftover, since 1 and i are already in their respective deranged positions for this use case. 1 and i are a total of 2 unique positions. N without these two positions ( 1 and i ) is formulated as N-2. These leftover N-2 positions still need to be deranged and are written in the formula as follows:
 
 d(n)=(n-1)( d(n-1) + d(n-2) )
 
 Case 2: if the i-th position is repositioned into any other position EXCEPT the first position, then we have N-1 positions to choose from (all N positions, EXCEPT for the first position). We subtract one from N, since the first position is NOT a possibility for this use case. Those N-1 positions still need to be deranged ( these N-1 positions include the arbitrary i-th position where 2<=i<=N ):
 
 d(n)=(n-1)( d(n-1) + d(n-2) )
 
 These two use cases are then added together in order to include all possible use cases in the return count of derangements.
 
 d(n)=(n-1)( d(n-1) + d(n-2) )
 
 Then the (N-1) possible repositions available for each use case is multiplied by the sum of these two use cases. This is the complete formula. All possible repositions (N-1) multiplied by the sum of all possible use cases for each reposition ( d(n-1) + d(n-2) ).
 
 d(n)=(n-1)( d(n-1) + d(n-2) )
 
 Part 3 - Base Cases:
 
 d(0) = 1
 d(1) = 0
 
 This is strange, right? To simply explain this, let's first take a look at d(1) more closely. How many possible ways can we derange an array of one: [ 1 ]? There are none. We cannot move 1 to another position other than it's original position. Therefore, d(1) = 0.
 
 Then why does d(0) = 1? Short answer: because this works and makes sense, similar to why 0 factorial = 1. Long answer: let's take a look back at our previous d(2) example:
 
 d(n)=(n-1)( d(n-1) + d(n-2) )
 
 N=2
 d(2)=(2-1)( d(2-1) + d(2-2) )
 d(2)=(1)( d(1) + d(0) )
 d(2)=d(1) + d(0)
 
 We know there is 1 derangement for an array of 2:
 
 Original arrangement: [1,2]
 After 1 derangement: [2,1]
 
 Therefore, d(2) = 1, and we also know from above that d(1) = 0. Since we know d(2), and we know d(1), we can derive d(0) as follows:
 
 d(2) = d(1) + d(0)
 1 = 0 + d(0)
 1 = d(0)
 
 Part 4 - Simple C++ Solution:
 
 This solution uses dynamic programming to build from the base cases 0,1, ... until N where curr_n is the current value of N being calculated, dn is the amount of derangements for that current value of N. And dn_minus_2 and dn_minus_1 are the two previous derangement calculations for dn.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findDerangement(int n){
        if (n==0) { return 1; }
        if (n==1) { return 0; }
        int dn=1, dn_minus_1=0, dn_minus_2=1;
        for (int curr_n=2; curr_n <= n; curr_n++){
            dn=(int)((( curr_n - 1L )*( dn_minus_1 + dn_minus_2 ))%1000000007);
            dn_minus_2=dn_minus_1;
            dn_minus_1=dn;
        }
        return dn;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    while(true){
        int n=0;
        cout << "N: ";
        cin >> n;
        cout << solution.findDerangement(n) << endl << endl;
    }
    
    
    return 0;
}



