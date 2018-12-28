/*
 
 684. Redundant Connection
 
 https://leetcode.com/contest/leetcode-weekly-contest-51/problems/redundant-connection/
 
 We are given a "tree" in the form of a 2D-array, with distinct values for each node.
 
 In the given 2D-array, each element pair [u, v] represents that v is a child of u in the tree.
 
 We can remove exactly one redundant pair in this "tree" to make the result a tree.
 
 You need to find and output such a pair. If there are multiple answers for this question, output the one appearing last in the 2D-array. There is always at least one answer.
 
 Example 1:
 Input: [[1,2], [1,3], [2,3]]
 Output: [2,3]
 Explanation: Original tree will be like this:
   1
  / \
 2 - 3
 Example 2:
 Input: [[1,2], [1,3], [3,1]]
 Output: [3,1]
 Explanation: Original tree will be like this:
   1
  / \\
 2   3
 Note:
 The size of the input 2D-array will be between 1 and 1000.
 Every integer represented in the 2D-array will be between 1 and 2000.
 
 
 Solution: https://discuss.leetcode.com/topic/104888/simple-c-unionfind-with-explanation/1
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution1{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        const int size=2001;
        vector<int> res{}, tree(size);
        for (int i=0; i<size; ++i){ tree[i]=i; }
        for (auto& edge : edges){
            int p=edge[0], q=edge[1];
            int parent=tree[p], child=tree[q];
            if (parent==child) { return vector<int>{p,q}; }
            for (int i=0; i<size; ++i){ if (tree[i]==parent) { tree[i]=child; } } // optimized #2
        }
        return res;
    }
};


class Solution2{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        const int size=2001;
        vector<int> res{}, tree(size);
        for (int i=0; i<size; ++i){ tree[i]=i; }
        for (auto& edge : edges){
            int p=_find(tree,edge[0]),q=_find(tree,edge[1]);
            if (p==q) { return edge; }
            tree[p]=q;
        }
        return res;
    }
    
private:
    int _find(vector<int>& tree, int i){
        if (tree[i]!=i){
            tree[i]=_find(tree,tree[i]); // optimized #3
        }
        return tree[i];
    }
};

class Solution3{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        const int size=2001;
        vector<int> res{}, tree(size);
        for (int i=0; i<size; ++i){ tree[i]=i; }
        for (auto& edge : edges){
            int p=_find(tree,edge[0]),q=_find(tree,edge[1]);
            if (p==q) { return edge; }
            tree[p]=q;
        }
        return res;
    }
    
private:
    int _find(vector<int>& tree, int i){
        while (tree[i]!=i){ tree[i]=tree[tree[i]]; }
        return tree[i];
    }
};


/*
 Input:
 [[3,4],[2,3],[1,2]]
 Output:
 [3,2]
 Expected:
 [2,3]
 */

int main(int argc, const char * argv[]) {
    
    
    vector<vector<int>> edges {
        { 3,4 },
        { 2,3 },
        { 1,2 },
        { 3,2 }
    };
    
    Solution2 solution2;
    vector<int> res2=solution2.findRedundantConnection(edges);

    Solution3 solution3;
    vector<int> res3=solution2.findRedundantConnection(edges);
    
    return 0;
}




