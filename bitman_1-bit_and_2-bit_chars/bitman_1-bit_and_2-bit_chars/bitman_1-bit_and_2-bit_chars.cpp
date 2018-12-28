/*
 
 We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).
 
 Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.
 
 Example 1:
 Input:
 bits = [1, 0, 0]
 Output: True
 Explanation:
 The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
 Example 2:
 Input:
 bits = [1, 1, 1, 0]
 Output: False
 Explanation:
 The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
 
 1 <= len(bits) <= 1000.
 bits[i] is always 0 or 1.
 
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits.size()<=0) return false;
        if (bits.size()==1) return true;
        int n=(int)bits.size();
        if (bits[n-2]==bits[n-1] && bits[n-1]==0) return true;
        int cnt=0;
        for (int i=n-2; i>=0 && bits[i]==1; --i){
            ++cnt;
        }
        return cnt%2==0 ? true : false;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    vector<int> bits { 1,1,1,0 };
    cout << solution.isOneBitCharacter(bits) << endl;
    
    
    return 0;
}



