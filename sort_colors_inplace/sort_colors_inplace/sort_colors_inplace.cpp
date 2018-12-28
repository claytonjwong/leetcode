/*
 
 75. Sort Colors
 
 Q: https://leetcode.com/problems/sort-colors/description/
 A: https://leetcode.com/problems/sort-colors/discuss/143104/Straightforward-C++-using-map
 
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& A, map<int,int> m={}){
        for (auto x: A)
            ++m[x];
        int i=0; for (auto& x: m){
            int j=x.second;
            while (j--)
                A[i++]=x.first;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<int> nums{0,1,0,2,0,3};
    s.sortColors(nums);
    
    return 0;
}
