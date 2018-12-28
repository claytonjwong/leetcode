/*
 
 670. Maximum Swap
 
 https://leetcode.com/contest/leetcode-weekly-contest-48/problems/maximum-swap/
 
 Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
 
 Example 1:
 Input: 2736
 Output: 7236
 Explanation: Swap the number 2 and the number 7.
 Example 2:
 Input: 9973
 Output: 9973
 Explanation: No swap.
 Note:
 The given number is in the range [0, 108]
 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        if (str.size()==1) { return num; }
        for (int i=0; i < str.size()-1; i++){
            for (int j=i+1; j < str.size(); j++) {
                string swapped = str;
                swapped[i] = str[j];
                swapped[j] = str[i];
                int new_num = stoi(swapped);
                if (new_num > num){
                    num = new_num;
                }
            }
        }
        return num;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    
    cout << solution.maximumSwap(98368) << endl;
    
    
    return 0;
}



