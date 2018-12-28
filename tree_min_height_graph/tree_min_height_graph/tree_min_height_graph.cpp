/*
 
 310. Minimum Height Trees
 
 https://leetcode.com/problems/minimum-height-trees/description/
 
 For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
 
 Format
 The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
 
 You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
 
 Example 1:
 
 Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 
   0
   |
   1
  / \
 2   3
 return [1]
 
 Example 2:
 
 Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 
 0  1  2
 \ | /
 3
 |
 4
 |
 5
 return [3, 4]
 
 Note:
 
 (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
 
 (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
 
 */


#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int,int> depths;
        vector<unordered_set<int>> graph(n);
        for (auto &e: edges){
            graph[e.first].insert(e.second);
            graph[e.second].insert(e.first);
        }
        int depth=0;
        while (depths.size()<n){
            ++depth;
            unordered_set<int> leaves;
            for (int i=0; i<n; ++i){
                if (depths.count(i)) continue; // already found depth for i
                if (graph[i].size()>1) continue; // only find leaf nodes
                leaves.insert(i);
            }
            for (int leaf: leaves){
                depths[leaf]=depth;
                if (graph[leaf].empty()) continue; // disjoint
                int nei=*graph[leaf].begin();
                graph[leaf].erase(nei);
                graph[nei].erase(leaf);
            }
        }
        vector<int> res;
        for (auto x: depths) if (x.second==depth){
            res.push_back(x.first);
        }
        return res;
    }
};

//[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]

int main(int argc, const char * argv[]) {
    
    Solution s;
    int n=4;
    vector<pair<int,int>> vp {
        {0,1},
        {1,2},
        {1,3},
    };
    auto res=s.findMinHeightTrees(n, vp);
    
    return 0;
}



