/*
 
 797. All Paths From Source to Target
 
 https://leetcode.com/contest/weekly-contest-75/problems/all-paths-from-source-to-target/
 
 Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
 
 The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
 
 Example:
 Input: [[1,2], [3], [3], []]
 Output: [[0,1,3],[0,2,3]]
 Explanation: The graph looks like this:
 0--->1
 |    |
 v    v
 2--->3
 There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 Note:
 
 The number of nodes in the graph will be in the range [2, 15].
 You can print different paths in any order, but you should keep the order of nodes inside one path.
 
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        go(res,graph,0,(int)graph.size()-1,path);
        return res;
    }
private:
    void go(vector<vector<int>>& r, vector<vector<int>>& g, int i, int t, vector<int>& p){
        p.push_back(i);
        if (i==t) {
            r.push_back(p);
        } else {
            for (auto nei: g[i])
                go(r,g,nei,t,p);
        }
        p.pop_back();
    }
};



int main(int argc, const char * argv[]) {

    
    Solution s;
    vector<vector<int>> graph {
        {1,2},
        {3},
        {3},
        {},
    };
    auto r=s.allPathsSourceTarget(graph);
    
    
    return 0;
}




