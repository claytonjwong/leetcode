/*
 
 Q: https://leetcode.com/problems/word-search/description/
 A: https://leetcode.com/problems/word-search/discuss/133457/C++-DFS-+-Backtracking
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string target) {
        if (board.empty()) return false;
        for (int i=0,M=(int)board.size(); i<M; ++i)
            for (int j=0,N=(int)board[0].size(); j<N; ++j)
                if (go(board,target,i,j)) return true;
        return false;
    }
private:
    vector<pair<int,int>> dirs={{-1,0},{0,1},{1,0},{0,-1}};
    int key(int i, int j, int N) const { return i*N+j; } // visited hash
    bool go(vector<vector<char>>& B, const string& T,
            int i=0, int j=0, string word="", unordered_set<int> visited={}) const {
        int M=(int)B.size(),N=(int)B[0].size();
        if (i<0||j<0||i>=M||j>=N) return false;
        if (!visited.insert(key(i,j,N)).second) return false;
        word.push_back(B[i][j]);
        if (T.substr(0,word.size())==word){
            if (word.size()<T.size()){
                for (auto& dir: dirs)
                    if (go(B,T,i+dir.first,j+dir.second,word,visited)) return true;
            }
            else if (word.size()==T.size()) return true;
        }
        visited.erase(key(i,j,N));
        word.pop_back();
        return false;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<vector<char>> b{
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << s.exist(b, "ABCB") << endl;
    
    return 0;
}


