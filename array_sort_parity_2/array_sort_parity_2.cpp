/*

 922. Sort Array By Parity II

 Q: https://leetcode.com/problems/sort-array-by-parity-ii/description/
 A: https://leetcode.com/problems/sort-array-by-parity-ii/discuss/182215/Concise-C++

 */

#include <iostream>
#include <vector>

using namespace std;


using VI = vector< int >;
class Solution {
public:
    VI sortArrayByParityII( VI& A, VI ans=VI(20000), int even=0, int odd=1 ){
        for( const auto value: A )
            if( value % 2 == 0 )
                ans[ even ] = value,  even += 2;
            else
                ans[ odd ] = value,  odd += 2;
        return { ans.begin(), ans.begin() + A.size() };
    }
};


/*
using VI = vector< int >;
class Solution {
public:
    VI sortArrayByParityII( VI& A, VI even={}, VI odd={}, VI ans={} ){
        for( const auto value: A )
            if( value % 2 == 0 )
                even.push_back( value );
            else
                odd.push_back( value );
        for(;  ! even.empty()  &&  ! odd.empty();  even.pop_back(), odd.pop_back()  )
            ans.push_back( even.back() ),  ans.push_back( odd.back() );
        return ans;
    }
};
*/

int main() {




    return 0;
}