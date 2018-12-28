/*
 
 37. Sudoku Solver
 
 Q: https://leetcode.com/problems/sudoku-solver/description/
 
 A: https://leetcode.com/problems/sudoku-solver/discuss/126744/Concise-C++-Backtracking-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& B) { go(B); }
private:
    bool go(vector<vector<char>>& B){
        for (int i=0,N=(int)B.size(); i<N; ++i) for (int j=0; j<N; ++j){
            if (isdigit(B[i][j])) continue;
            for (int k='1'; k<='9'; ++k){
                if (!valid(B,i,j,k)) continue;
                B[i][j]=k;
                if (go(B)) return true;
                B[i][j]='.';
            }
            return false;
        }
        return true;
    }
    bool valid(vector<vector<char>>& B, int i, int j, char k){
        for (int x=0; x<B.size(); ++x)
            if (B[i][x]==k || B[x][j]==k) return false;
        for (int begX=(i>5)?6 : (i>2)?3 : 0,x=begX; x<begX+3; ++x)
            for (int begY=(j>5)?6 : (j>2)?3 : 0,y=begY; y<begY+3; ++y)
                if (B[x][y]==k) return false;
        return true;
    }
};

void print(vector<vector<char>>& B){
    int N=(int)B.size();
    for (int i=0; i<N; ++i){
        cout << "{";
        for (int j=0; j<N; ++j){
            cout << "'" << B[i][j] << "',";
        }
        cout << "}," << endl;
    }
    cout << endl << endl;
}

int main(int argc, const char * argv[]) {

    Solution s;
    int N=9;
    
    /*
    vector<vector<char>> B={
    {'.','2','3','4','5','6','7','8','9',},
    {'4','5','6','7','8','9','1','2','3',},
    {'7','8','9','1','2','3','4','5','6',},
    {'2','1','4','3','6','5','8','9','7',},
    {'3','6','5','8','9','7','2','1','4',},
    {'8','9','7','2','1','4','3','6','5',},
    {'5','3','1','6','4','2','9','7','8',},
    {'6','4','2','9','7','8','5','3','1',},
    {'9','7','8','5','3','1','6','4','2',},
    };
     */
    
    vector<vector<char>> B=
    {{'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    
    s.solveSudoku(B);
    print(B);

    
    return 0;
}



