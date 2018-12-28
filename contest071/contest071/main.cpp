/*
 
 https://leetcode.com/contest/weekly-contest-71/ranking
 
 Rank           Name            Score       Finish Time     Q1 (3)          Q2 (5)    Q3 (7)    Q4 (10)
 925 / 2474     claytonjwong    8           1:33:02         0:19:58  1      1:18:02  2
 
 */

#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left,* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        int m=INT_MAX;
        for (int i=1; i<v.size(); ++i)
            m=min(m,abs(v[i-1]-v[i]));
        return m;
    }
private:
    void helper(TreeNode* root,vector<int>& v){
        if (!root) return;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
};


/*
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        for (auto ans: answers) ++m[ans];
        int r=0;
        for (auto x: m) r+=ceil((double)x.second/(x.first+1))*(x.first+1);
        return r;
    }
};
 */

/*
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        for (auto answer: answers){
            ++m[answer];
        }
        int rabbits=0;
        for (auto x: m){
            int unique_answer_count=x.second;
            int max_group_size=x.first+1;
            int min_group_amount=ceil((double)unique_answer_count/max_group_size);
            int min_new_rabbits=min_group_amount*max_group_size;
            rabbits+=min_new_rabbits;
        }
        return rabbits;
    }
};
*/

/*
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        const int N=1000;
        vector<int> v(N+1,0);
        for (auto ans: answers) ++v[ans];
        for (int i=0; i<N; ++i)
            v[N]+=ceil((double)v[i]/(i+1))*(i+1);
        return v[N];
    }
};
 */

/*
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        const int N=1000;
        vector<int> v(N+1,0);
        for (auto answer: answers){
            ++v[answer];
        }
        int rabbits=0;
        for (int i=0; i<N; ++i){
            int answer_count=v[i];
            int max_group_size=i+1;
            int min_group_amount=ceil((double)answer_count/max_group_size);
            int min_new_rabbits=min_group_amount*max_group_size;
            rabbits+=min_new_rabbits;
        }
        return rabbits;
    }
};
 */



#include <exception>

int main() {
    
    /*
     TreeNode* root=new TreeNode(4);
     root->right=new TreeNode(6);
     root->left=new TreeNode(2);
     root->left->left=new TreeNode(1);
     root->left->right=new TreeNode(3);
     */
    
    TreeNode* root=new TreeNode(90);
    root->left=new TreeNode(64);
    root->left->left=new TreeNode(49);
    root->left->right=new TreeNode(89);
    root->left->left->right=new TreeNode(52);
    Solution s;
    cout << s.minDiffInBST(root) << endl;
    
    
    /*
     Solution s;
     vector<int> v { 1,1,2 };
     cout << s.numRabbits(v) << endl;
     */
    

    return 0;
    
}

