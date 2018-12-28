/*
 
 38. Count and Say
 
 https://leetcode.com/problems/count-and-say/description/
 
 The count-and-say sequence is the sequence of integers with the first five terms as following:
 
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth term of the count-and-say sequence.
 
 Note: Each term of the sequence of integers will be represented as a string.
 
 Example 1:
 
 Input: 1
 Output: "1"
 Example 2:
 
 Input: 4
 Output: "1211"
 
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string curr("1"),next;
        while (--n){
            for (int i=0,j=0; i<curr.size(); i=j){
                while (j<curr.size() && curr[i]==curr[j]) ++j;
                next+=to_string(j-i)+curr[i];
            }
            curr=next;
            next.clear();
        }
        return curr;
    }
};

int main(int argc, const char * argv[]) {
    
    int n=5;
    Solution s;
    cout << s.countAndSay(n) << endl;
    
    
    return 0;
}


