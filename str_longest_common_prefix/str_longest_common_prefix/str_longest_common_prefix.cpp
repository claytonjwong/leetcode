/*
 
 14. Longest Common Prefix
 
 Write a function to find the longest common prefix string amongst an array of strings.
 
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string common = "";
        
        if (strs.empty()){
            return common;
        }
        
        for (int col=0; col < strs[0].size(); col++){
            
            // ensure char at this column matches for all rows
            for (int row=1; row <= strs.size() - 1; row++){
                
                if ( strs[row-1][col] != strs[row][col] ){
                    return common;
                }
            }
            
            // char at this column matches for all rows, append char onto common
            common += strs[0][col];
            
        }
        
        return common;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<string> strs = { "a", "b" };
    
    Solution solution;
    string result = solution.longestCommonPrefix(strs);
    
    cout << result << endl;
    
    return 0;
}
