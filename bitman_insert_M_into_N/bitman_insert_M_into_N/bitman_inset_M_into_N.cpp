/*
 
 CCI 5.1 Insertion: You are give two 32-bit numbers, N and M, ad two bit positions, i and j.  Write a method to insert m into N such that M starts at bit j and ends at bit i.  You can assume that the bits j through i have enough space to fit all of M.  That is, if M = 10011, you can assume that there are at least 5 bits between j and i.  You would not for example, have j=3 and i=2, because M could not fully fit between bit 3 and bit 2
 
 EXAMPLE:
 
 N=160
 M=19
 i=2
 j=6
 
              j   i
             76543210
   160 = N = 10100000
    19 = M = 00010011
             01111100 = mask
             10000011 = ~mask
             01001100 = M << i
             11001100 = N with M inserted into N

 
 */

#include <iostream>


using namespace std;

class Solution{
public:
    static void InsertMintoN(int& M, int& N, int i, int j){
        
        // for example i=2 j=6, mask is 2^5-1 = 11111
        int mask = (1 << (j-i+1)) - 1;
        
        // shift mask by i
        mask <<= i;
        
        N &= ~mask; // set this chunk to all 0s
        
        N |= M << i; // bitwise OR M on top of this chunk of 0s
        
    }
};

int main(int argc, const char * argv[]) {
    
    int m = 19;
    int n = 160;
    
    Solution::InsertMintoN(m,n,2,6);
    cout << "204 == " << n << endl;
    
    return 0;
}
