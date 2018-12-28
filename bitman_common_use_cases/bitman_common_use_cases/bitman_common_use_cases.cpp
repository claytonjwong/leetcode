/*
 
 CCI CH 5: Bit Manipulation
 
 Common uses cases for get, set, clear, and update bit
 
 */

#include <iostream>

using namespace std;

class Solution {
public:
    
    static int GetBit(int& num, int i) { return num & ( 1 << i ); }
    
    static void SetBit(int& num, int i) { num |= ( 1 << i ); }
    
    static void ClearBit(int& num, int i) { num &= ~( 1 << i ); }
    
    static void UpdateBit(int& num, int i, bool isOne) {
        
        num &= ~( 1 << i ); // take everything besides bit i
        num |= ( isOne << i ); // set bit to 1 if isOne, keep bit as 0 otherwise
    }
    
    static void FlipBit(int& num, int i){
        if (Solution::GetBit(num, i)){
            Solution::UpdateBit(num, i, false);
        } else {
            Solution::SetBit(num, i);
        }
    }
    
        
private:
        
    int val;
        
};

int main(int argc, const char * argv[]) {

    int num = 13; // 1101
    
    cout << "8 == " << Solution::GetBit(num, 3) << endl; // 1000
    cout << "0 == " << Solution::GetBit(num, 1) << endl; // 0000
    
    Solution::ClearBit(num, 1);
    cout << "13 == " << num << endl; // 1101
    
    Solution::SetBit(num, 1);
    cout << "15 == " << num << endl; // 1111
    
    Solution::UpdateBit(num, 3, false);
    cout << "7 == " << num << endl; // 0111
    
    Solution::FlipBit(num, 3);
    cout << "15 == " << num << endl; // 1111
    
    Solution::FlipBit(num, 0);
    cout << "14 == " << num << endl; // 1110
    
    return 0;
}



