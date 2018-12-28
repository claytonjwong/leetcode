/*
 
 261. Graph Valid Tree
 
 https://leetcode.com/problems/graph-valid-tree/description/
 
 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
 write a function to check whether these edges make up a valid tree.
 
 For example:
 
 Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
 
 Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
 
 Note: you can assume that no duplicate edges will appear in edges. Since all edges
 are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 
 */

#include <iostream>
#include <vector>

using namespace std;

/*
// AC
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& e) {
        if (n==0) return true;
        vector<int> p(n);
        for (int i=0; i<n; ++i) p[i]=i; // parents of disjoint sets
        if (!go(p,0,e.size(),e)) return false; // loop detected
        int rep=f(p,p[0]); // representative of the unioned set is same if graph is connected
        for (int i=1; i<n; ++i) if (f(p,p[i])!=rep) return false; // NOT connected graph
        return true;
    }
private:
    int f(vector<int>& p, int x){ // find (with path compression)
        if (p[x]!=x)
            p[x]=f(p,p[x]);
        return p[x];
    }
    bool u(vector<int>& p, int a, int b){ // union (arbitrarily set parent of a to parent of b)
        int pa=f(p,a),pb=f(p,b);
        if (pa==pb) return false; // loop detected
        p[pa]=pb;
        return true;
    }
    bool go(vector<int>& p, int i, const int& n, const vector<pair<int,int>>& e){
        if (i==n) return true;
        return u(p,e[i].first,e[i].second) ? go(p,i+1,n,e) : false; // return false if loop detected
    }
};
*/

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& e) {
        if (n==0) return true;
        vector<int> p(n);
        for (int i=0; i<n; ++i) p[i]=i; // init parents to themselves (disjoint sets)
        for (int i=0; i<e.size(); ++i) if (!u(p,e[i].first,e[i].second)) return false; // loop detected
        int rep=f(p,p[0]); // representative of the unioned set is same if graph is connected
        for (int i=1; i<n; ++i) if (f(p,p[i])!=rep) return false; // NOT connected graph
        return true;
    }
private:
    int f(vector<int>& p, int x){ // find (with path compression)
        if (p[x]!=x) p[x]=f(p,p[x]);
        return p[x];
    }
    bool u(vector<int>& p, int a, int b){ // union (arbitrarily set parent of a to parent of b)
        int pa=f(p,a),pb=f(p,b);
        if (pa==pb) return false; // loop detected
        p[pa]=pb;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    int n=4;
    vector<pair<int,int>> v{
        {0,1},
        {2,3},
    };
    cout << s.validTree(n, v) << endl;
    
    return 0;
}



