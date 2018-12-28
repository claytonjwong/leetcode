/*

 Rank           Name            Score   Finish Time     Q1 (4)      Q2 (4)      Q3 (5)    Q4 (9)
 825 / 2937     claytonjwong    13      0:45:54         0:21:18     0:30:31     0:45:54
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

/*
 // AC
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines=1,currPos=0;
        for (auto c: S){
            currPos+=widths[c-'a'];
            if (currPos>100){
                ++lines;
                currPos=widths[c-'a'];
            }
        }
        return {lines,currPos};
    }
};
*/

/*
 //AC
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        for (auto& word: words)
            s.insert(encode(word));
        return (int)s.size();
    }
private:
    string encode(const string& s){
        static vector<string> m{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string e;
        for (auto c: s)
            e.append(m[c-'a']);
        return e;
    }
};
*/


class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int cnt=0,M=(int)grid.size(),N=(int)grid[0].size();
        vector<int> maxRow(M),maxCol(N);
        for (int i=0; i<M; ++i)
            for (int j=0; j<N; ++j){
                maxRow[i]=max(maxRow[i],grid[i][j]);
                maxCol[j]=max(maxCol[j],grid[i][j]);
            }
        for (int i=0; i<M; ++i)
            for (int j=0; j<N; ++j)
                cnt+=min(maxRow[i],maxCol[j])-grid[i][j];
        return cnt;
    }
};


int main(int argc, const char * argv[]) {
    
    /*
    Solution s;
    vector<int> widths{4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string S = "bbbcccdddaaa";
    auto r=s.numberOfLines(widths, S);
    */
    
    /*
    vector<string> words{"gin", "zen", "gig", "msg"};
    Solution s;
    auto r=s.uniqueMorseRepresentations(words);
    */
    
    
    Solution s;
    vector<vector<int>> grid
    {{3, 0, 8, 4},
     {2, 4, 5, 7},
     {9, 2, 6, 3},
     {0, 3, 1, 0}};
    
    auto r=s.maxIncreaseKeepingSkyline(grid);
    
    
    return 0;
}


