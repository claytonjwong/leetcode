/*

 684. Redundant Connection
 
 https://leetcode.com/contest/leetcode-weekly-contest-51/problems/redundant-connection/
 
 In this problem, a tree is an undirected graph that is connected and has no cycles.
 
 The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.
 
 The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.
 
 Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.
 
 Example 1:
 Input: [[1,2], [1,3], [2,3]]
 Output: [2,3]
 Explanation: The given undirected graph will be like this:
 1
 / \
 2 - 3
 Example 2:
 Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
 Output: [1,4]
 Explanation: The given undirected graph will be like this:
 5 - 1 - 2
 |   |
 4 - 3
 Note:
 The size of the input 2D-array will be between 3 and 1000.
 Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> parent{};
    void Union(int a, int b){
        int target=parent[a];
        for (int i=0; i<parent.size(); ++i)
            if (parent[i]==target)
                parent[i]=b;
    }
    
    int Find(int x){
        if (parent[x]==x)
            return x;
        parent[x]=Find(parent[x]);
        return parent[x];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        vector<int> res{};
        parent.resize(edges.size()+1);
        for (int i=0; i<parent.size(); ++i)
            parent[i]=i;
        for (auto &&edge: edges){
            int m=edge[0], n=edge[1];
            m=Find(m);
            n=Find(n);
            if (m==n)
                res=edge;
            else
                Union(m,n);
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    vector<vector<int>> edges {
        {1,2},
        {2,3},
        {3,4},
        {1,4},
        {1,5},
    };
    
    auto res=s.findRedundantConnection(edges);
    
    return 0;
}





