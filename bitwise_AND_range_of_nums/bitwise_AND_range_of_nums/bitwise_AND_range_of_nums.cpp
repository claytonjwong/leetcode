/*
 
 201. Bitwise AND of Numbers Range
 
 https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/
 
 Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
 
 For example, given the range [5, 7], you should return 4.
 
 
 */

 
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    int rangeBitwiseAnd(int m, int n) {
        
        /*
         
         check and set bits from right to left based on the bitwise pattern
         found while incrementing the numbers in a range.  The pattern is "chunks"
         of 1s and 0s:
         
         3210=bit_pos
         X  F842=mod_by=2^(bit_pos+1)   ( F is 16 in this small example of values )
         0  0000
         1  0001
         2  0010
         3  0011
         4  0100
         5  0101
         6  0110
         7  0111
         8  1000
         9  1001
         10 1010
         11 1011
         12 1100
         13 1101
         14 1110
         15 1111
         
         Notice how the "chunks" of 0s and 1s change as the range number X is incremented.
         If this is hard to imagine, try looking at the above 4 columns as 4 rows:
         
         X=0123456789ABCDEF
         bit position 0 has chunks of one   0  and one   1  ==> 0101010101010101 etc...
         bit position 1 has chunks of two   0s and two   1s ==> 0011001100110011 etc...
         bit position 2 has chunks of four  0s and four  1s ==> 0000111100001111 etc...
         bit position 3 has chunks of eight 0s and eight 1s ==> 0000000011111111 etc...
         
         It follows then that the buckets ( chunks of bits above ) which m and n reside
         in for each bit position is found by:
         
         m % mod_by
         n % mod_by
         
         
         Each bucket (chunk of bits):
         
         has of size mod_by / 2
         starts at mod_by / 2
         ends at mod_by -1
         
         
         */
        int result = 0;
        
        uint bit_pos = 0;
        uint mod_by = 0;
        while (bit_pos < 31){ // mod_by < 2^32
            
            mod_by = pow(2, bit_pos + 1);
            
            // calculate the current bucket size and range
            uint mod_bucket_size = mod_by / 2;
            uint lower_mod_range = mod_by / 2;
            uint upper_mod_range = mod_by - 1;
            
            // calculate the mod by buckets for m and n
            uint m_mod_bucket = m % mod_by;
            uint n_mod_bucket = n % mod_by;
            
            /*
             range check
             
             if:
             lower <= m <= upper
             lower <= n <= upper
             then:
             m and n are in the same mod bucket
             
             also ensure that abs(m-n) is less than the mod bucket size
             to ensure that m and n are in the same actual bucket
             */
            if ((( lower_mod_range <= m_mod_bucket ) && ( m_mod_bucket <= upper_mod_range )) &&
                (( lower_mod_range <= n_mod_bucket ) && ( n_mod_bucket <= upper_mod_range )) &&
                ( abs(m-n) < mod_bucket_size ) )
            {
                result |= 1 << bit_pos;
            }
            
            bit_pos++; // iterate to the next bit position
        }
        
        return result;
    }
    
};





int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    int result = solution.rangeBitwiseAnd(2147483647,2147483647);
    
    cout << "result: " << result << endl;
    
    
    return 0;
}
