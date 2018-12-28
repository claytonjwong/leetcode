/*
 
 679. 24 Game
 
 https://leetcode.com/contest/leetcode-weekly-contest-50/problems/24-game/
 
 You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.
 
 Example 1:
 Input: [4, 1, 8, 7]
 Output: True
 Explanation: (8-4) * (7-1) = 24
 Example 2:
 Input: [1, 2, 1, 2]
 Output: False
 Note:
 The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
 Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
 You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

/*
class Solution{
public:
    bool judgePoint24(vector<int>& nums){
        sort(nums.begin(),nums.end());
        do{
            if(is24(nums)) { return true; }
        } while(next_permutation(nums.begin(), nums.end()));
        return false;
    }
    
    bool is24(vector<int>& nums){
        double a=nums[0], b=nums[1], c=nums[2], d=nums[3];
        if (
            is24(a+b,c,d) || is24(a-b,c,d) || is24(a*b,c,d) || (b && is24(a/b,c,d)) ||
            is24(a,b+c,d) || is24(a,b-c,d) || is24(a,b*c,d) || (c && is24(a,b/c,d)) ||
            is24(a,b,c+d) || is24(a,b,c-d) || is24(a,b,c*d) || (d && is24(a,b,c/d))
            ){
            return true;
        }
        return false;
    }
    
    bool is24(double a, double b, double c){
        if (
            is24(a+b,c) || is24(a-b,c) || is24(a*b,c) || (b && is24(a/b,c)) ||
            is24(a,b+c) || is24(a,b-c) || is24(a,b*c) || (c && is24(a,b/c))){
            return true;
        }
        return false;
    }
    
    bool is24(double a, double b){
        if (
            is24((a+b)-24.0) || is24((a-b)-24.0) || is24((a*b)-24.0) || (b && is24((a/b)-24.0))){
            return true;
        }
        return false;
    }
    
    bool is24(double&& a){
        double offset=0.001;
        if (-offset < a && a < offset) { return true; }
        return false;
    }
};

bool plusOne(vector<int>& A){
    ++A.back();
    for (int i=(int)A.size()-1; i > 0 && A[i]==10; --i){
        ++A[i-1]; A[i]=1;
    }
    if (A[0]==10){ return false; } else { return true; }
}

int toInt(vector<int>& A){
    return
    A[0]*10*10*10
    + A[1]*10*10
    + A[2]*10
    + A[3];
}

int main(int argc, const char * argv[]) {
    
    Solution solution;
    vector<int> nums { 1,1,1,1 };
    
    set<int> not_24;
    do{
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        int answer=toInt(temp);
        if (!solution.judgePoint24(temp)){
            not_24.insert(answer);
        }
    }while(plusOne(nums));
    
    int i=1;
    for (auto& answer : not_24){
        cout << to_string(answer) + ", ";
        if (i%13==0){ cout << endl; }
        i++;
    }
    
    return 0;
}
*/

class Solution{
public:
    
    bool judgePoint24(vector<int>& nums){
        sort(nums.begin(),nums.end());
        return !NOT_24.count(nums[0]*10*10*10+nums[1]*10*10+nums[2]*10+nums[3]);
    }
    
private:
    const set<int> NOT_24 {
        1111, 1112, 1113, 1114, 1115, 1116, 1117, 1119, 1122, 1123, 1124, 1125, 1133,
        1159, 1167, 1177, 1178, 1179, 1189, 1199, 1222, 1223, 1299, 1355, 1499, 1557,
        1558, 1577, 1667, 1677, 1678, 1777, 1778, 1899, 1999, 2222, 2226, 2279, 2299,
        2334, 2555, 2556, 2599, 2677, 2777, 2779, 2799, 2999, 3358, 3467, 3488, 3555,
        3577, 4459, 4466, 4467, 4499, 4779, 4999, 5557, 5558, 5569, 5579, 5777, 5778,
        5799, 5899, 5999, 6667, 6677, 6678, 6699, 6777, 6778, 6779, 6788, 6999, 7777,
        7778, 7779, 7788, 7789, 7799, 7888, 7899, 7999, 8888, 8889, 8899, 8999, 9999,
    };
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    vector<int> nums { 1,1,1,8 };
    cout << solution.judgePoint24(nums) << endl;
    
    return 0;
}

