/*
 
 Q: https://leetcode.com/problems/valid-sudoku/description/
 A: https://leetcode.com/problems/valid-sudoku/discuss/131126/Straightforward-C++
 
 Q: https://leetcode.com/problems/sudoku-solver/description/
 A: https://leetcode.com/problems/sudoku-solver/discuss/126744/Concise-C++-Backtracking-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& G) {
        return valid(G);
    }
private:
    bool valid(vector<vector<char>>& G) const {
        vector<vector<unordered_set<char>>> grp(3,vector<unordered_set<char>>(3));
        for (int i=0,M=(int)G.size(); i<M; ++i){
            unordered_set<char> row,col;
            for (int j=0,N=(int)G[0].size(); j<N; ++j){
                char r=G[i][j],c=G[j][i];
                if (isdigit(r)){
                    if (row.find(r)!=row.end())
                        return false;
                    row.insert(r);
                    int k=i>5 ? 2 : i>2 ? 1 : 0;
                    int l=j>5 ? 2 : j>2 ? 1 : 0;
                    if (grp[k][l].find(r)!=grp[k][l].end())
                        return false;
                    grp[k][l].insert(r);
                }
                if (isdigit(c)){
                    if (col.find(c)!=col.end())
                        return false;
                    col.insert(c);
                }
            }
            ;
        }
        return true;
    }
};
*/

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& G) {
        unordered_set<string> row,col,grp;
        for (int i=0,M=(int)G.size(); i<M; ++i){
            for (int j=0,N=(int)G[0].size(); j<N; ++j){
                char c=G[i][j];
                if (c=='.') continue;
                string str_row=string(1,c)+string(" in row ")+to_string(i);
                string str_col=string(1,c)+string(" in col ")+to_string(j);
                string str_grp=string(1,c)+string(" in grp [")+to_string(i/3)+"]["+to_string(j/3)+"]";
                if (row.find(str_row)!=row.end()) return false;
                if (col.find(str_col)!=col.end()) return false;
                if (grp.find(str_grp)!=grp.end()) return false;
                row.insert(str_row);
                col.insert(str_col);
                grp.insert(str_grp);
            }
        }
        return true;
    }
};
*/

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& G) {
        unordered_set<string> row,col,grp;
        for (int i=0,M=(int)G.size(); i<M; ++i){
            for (int j=0,N=(int)G[0].size(); j<N; ++j){
                char c=G[i][j];
                if (c=='.') continue;
                if (!row.insert(string(1,c)+string(" in row ")+to_string(i)).second
                 || !col.insert(string(1,c)+string(" in col ")+to_string(j)).second
                 || !grp.insert(string(1,c)+string(" in grp [")+to_string(i/3)+"]["+to_string(j/3)+"]").second)
                    return false;
            }
        }
        return true;
    }
};
 */


class Solution {
public:
    void solveSudoku(vector<vector<char>>& G) {
        go(G);
    }
private:
    bool go(vector<vector<char>>& G){
        for (int i=0; i<9; ++i){
            for (int j=0; j<9; ++j){
                if (G[i][j]!='.') continue;
                for (char k='1'; k<='9'; ++k){
                    G[i][j]=k;
                    if (valid(G,i,j) && go(G)) return true;
                    G[i][j]='.';
                }
                return false;
            }
        }
        return true;
    }
    bool valid(vector<vector<char>>& G, int k, int l) const {
        unordered_set<char> row,col,grp;
        char c=G[k][l];
        for (int i=0; i<9; ++i){
            if (G[k][i]!='.' && !row.insert(G[k][i]).second) return false;
            if (G[i][l]!='.' && !col.insert(G[i][l]).second) return false;
        }
        int gi=k>5 ? 6 : k>2 ? 3 : 0, gj=l>5 ? 6 : l>2 ? 3 : 0;
        for (int i=gi; i<gi+3; ++i)
            for (int j=gj; j<gj+3; ++j)
                if (G[i][j]!='.' && !grp.insert(G[i][j]).second) return false;
        return true;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<vector<char>> v{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    s.solveSudoku(v);
    //cout << s.isValidSudoku(v) << endl;

    
    return 0;
}


