/*
 
 51. N-Queens
 
 https://leetcode.com/problems/n-queens/description/
 
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 such that no two queens attack each other.
 
 Given an integer n, return all distinct solutions to the n-queens puzzle.
 
 Each solution contains a distinct board configuration of the n-queens'
 placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 
 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 
 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],
 
 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]
 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sresults{};
        vector<vector<int>> res=GetNQueens(n);
        for (auto& r : res){
            sresults.push_back(to_string(r));
        }
        return sresults;
    }
    
private:
    const int _INIT=-1;
    vector<vector<int>> _results{};
    
    vector<vector<int>> GetNQueens(int n){
        _results.clear();
        vector<int> q(n,_INIT);
        GetValidBoards(q,0);
        return _results;
    }
    
    void GetValidBoards(vector<int>& q, int row){
        if (row==q.size()) {
            _results.push_back(q);
            return;
        }
        for (int col=0; col<q.size(); ++col){
            if (IsValidPos(q,row,col)){
                q[row]=col;
                GetValidBoards(q,row+1);
                q[row]=_INIT;
            }
        }
    }
    
    bool IsValidPos(vector<int>& q, const int& r, const int& c){
        bool isRowValid=q[r]==_INIT;
        bool isColValid=find(q.begin(),q.end(),c)==q.end();
        bool isDiagValid=true;
        for (int i=0; i<q.size(); ++i){ // i is the row index
            if (q[i]!=_INIT && abs(i-r)==abs(q[i]-c)){
                isDiagValid=false;
                break;
            }
        }
        return isRowValid && isColValid && isDiagValid;
    }
    
    vector<string> to_string(vector<int>& res){
        vector<string> v{};
        for (int col : res){
            string row(res.size(),'.');
            row[col]='Q';
            v.push_back(row);
        }
        return v;
    }
};

int main(int argc, const char * argv[]) {
    
    int n;
    Solution solution;
    while(true){
        cout << "n: ";
        cin >> n;
        vector<vector<string>> res=solution.solveNQueens(n);
    }
    
    return 0;
}



