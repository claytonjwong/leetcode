/*
 
 https://leetcode.com/contest/weekly-contest-75/
 
 Rank       Name            Score    Finish Time     Q1 (3)     Q2 (5)    Q3 (7)    Q4 (7)
 759 / 2830 claytonjwong    8        0:30:18         0:03:20    0:30:18
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

/*
 //AC
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A==B) return true;
        for (int i=0; i<A.size(); ++i){
            char c=A.back(); A.pop_back();
            A=c+A;
            if (A==B) return true;
        }
        return false;
    }
};
 */

/*
 //AC
class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size()==B.size() && (A+A).find(B) != string::npos;
    }
};
 */

/*
 //AC
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        unordered_set<int> visited;
        vector<int> path;
        go(res,graph,0,(int)graph.size()-1,visited,path);
        return res;
    }
private:
    void go(vector<vector<int>>& r, vector<vector<int>>& g, int i, int t,
            unordered_set<int>& v, vector<int>& p){
        v.insert(i);
        p.push_back(i);
        if (i==t){
            r.push_back(p);
        } else {
            for (auto nei: g[i])
                if (!v.count(nei))
                    go(r,g,nei,t,v,p);
        }
        v.erase(i);
        p.pop_back();
    }
};
*/

// AC
class Solution {
public:
    double champagneTower(int K, int M, int N) {
        vector<vector<double>> glass(M+1,vector<double>(M+1));
        glass[0][0]=K;
        for (int i=0; i<M; ++i)
            for (int j=0; j<=i && j<=N; ++j){
                if (glass[i][j]<=1) continue; // no spill
                auto half=(glass[i][j]-1)/2;
                glass[i+1][j]+=half;
                glass[i+1][j+1]+=half;
            }
                
        return min(1.0,glass[M][N]);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    /*
    string A="abcde",B="deabc";
    cout << s.rotateString(A, B) << endl;
    */
    
    /*
    vector<vector<int>> graph {
        {1,2},
        {3},
        {3},
        {},
    };
    auto res=s.allPathsSourceTarget(graph);
    */
    
    //double champagneTower(int poured, int query_row, int query_glass) {
    
    cout << s.champagneTower(8, 3, 2) << endl;
    //cout << s.champagneTower2(6, 2, 0) << endl;
    
    
    return 0;
}




