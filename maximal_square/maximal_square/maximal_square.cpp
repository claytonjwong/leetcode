/*
 
 221. Maximal Square
 
 https://leetcode.com/problems/maximal-square/description/
 
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 
 For example, given the following matrix:
 
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 Return 4.
 
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        int maxlen=0;
        for (int i=0; i<m.size(); ++i){
            for (int j=0; j<m[0].size(); ++j){
                int len=0;
                while (canExpand(m,i,j,len)) ++len;
                maxlen=max(maxlen,len);
            }
        }
        return maxlen*maxlen;
    }
private:
    bool canExpand(vector<vector<char>>& m, int i, int j, int len){
        if (i+len==m.size() || j+len==m[0].size()) return false;
        for (int row=i+len,col=j; col<=j+len; ++col) if (m[row][col]=='0') return false;
        for (int row=i,col=j+len; row<=i+len; ++row) if (m[row][col]=='0') return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> v {
        {'1', '1', '1'},
        {'1', '1', '1'},
        {'1', '1', '1'},
    };
    Solution s;
    cout << s.maximalSquare(v) << endl;
    
    
    return 0;
}



