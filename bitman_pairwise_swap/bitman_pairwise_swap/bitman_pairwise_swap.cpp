/*
 
 CI CH 5.7 Pairwise Swap:  Write a program to swap odd and even bits in an integer with as few instructions as possible (e.g. bit 0 and bit 1 are swapped, bit 3 and bit 3 are swapped and so on)
 
 */

#include <iostream>

using namespace std;

class Solution{
public:
    
    /*
    
     From below swapping, we can see that even bit positions are moved 1 bit position to the left
     and odd bit positions are moved 1 bit position to the right
     
     before: 7654 3210
     after:  6745 2301
     
     
     7654 3210
     0101 0101 = 0x55 are evens which should be shifted one to the left
     
     7654 3210
     1010 1010 = 0xAA are odds which should be shifted one to the right
     
     */
    
    
    void swap_pairs(int& n){
        
        int even = (n & 0x5555) << 1;
        int odd = (n & 0xAAAA) >> 1;
        
        n = even | odd;
    }
    
};



int main(int argc, const char * argv[]) {

    // 0110 0110
    // 0101 0101 0x55
    // 0100 0100 even
    // 1000 1000 even << 1

    // 0110 0110
    // 1010 1010 0xAA
    // 0010 0010 odd
    // 0001 0001 odd << 1
    
    // 1000 1000 even << 1
    // 0001 0001 odd << 1
    // 1001 1001
    
    int test = 0x66;
    
    Solution solution;
    solution.swap_pairs(test);
    
    if (test == 0x99){
        cout << "PASS: " << test << endl;
    } else {
        cout << "FAIL: " << test << endl;
    }
    
    
    
    
    return 0;
}





