/*
 
 Rank           Name             Score  Finish Time     Q1 (4)      Q2 (5)    Q3 (6)    Q4 (7)
 590 / 2485     claytonjwong     9      0:42:03         0:27:12     0:42:03
 
 Q1: https://leetcode.com/problems/largest-triangle-area/discuss/123082/Calculate-area-using-matrix-for-shoe-+-lace
 Q2: https://leetcode.com/problems/binary-tree-pruning/discuss/122706/Simple-C++-using-recursion
 Q3: https://leetcode.com/problems/largest-sum-of-averages/discuss/123536/C++-verbose-+-concise-solutions-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

/*
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p){
        double ans=-1,N=p.size();
        for (int i=0; i<N-2; ++i)
            for (int j=i+1; j<N-1; ++j)
                for (int k=j+1; k<N; ++k)
                    ans=max(ans,area(p[i][0],p[i][1],p[j][0],p[j][1],p[k][0],p[k][1]));
        return ans;
    }
private:
    double area(int x1, int y1, int x2, int y2, int x3, int y3){
        return abs( (x1*y2)+(x2*y3)+(x3*y1)-(x2*y1)-(x3*y2)-(x1*y3) )/2.0;
    }
};
 */

/*
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p){
        double ans=-1,N=p.size();
        for (int i=0; i<N-2; ++i)
            for (int j=i+1; j<N-1; ++j)
                for (int k=j+1; k<N; ++k)
                    ans=max(ans,area(p[i][0],p[i][1],p[j][0],p[j][1],p[k][0],p[k][1]));
        return ans;
    }
private:
    double area(int x1, int y1, int x2, int y2, int x3, int y3){
        vector<vector<int>> shoe {
            {x1,y1},
            {x2,y2},
            {x3,y3},
            {x1,y1},
        };
        vector<int> lace(2);
        for (int i=0; i<3; ++i){
            lace[0]+=shoe[i][0]*shoe[i+1][1];
            lace[1]+=shoe[i][1]*shoe[i+1][0];
        }
        return abs(lace[0]-lace[1])/2.0;
    }
};
*/

/*
  // AC
struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int val) : val{val},left{nullptr},right{nullptr} {}
};
 
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root){
        return go(root) ? root : nullptr;
    }
private:
    int go(TreeNode* node){
        if (node==nullptr) return 0;
        int l=go(node->left),r=go(node->right);
        if (l==0) node->left=nullptr;
        if (r==0) node->right=nullptr;
        return l+r+node->val;
    }
};
*/
 
/*
 // AC
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root){
        if (root)
            go(root);
        return root;
    }
private:
    int go(TreeNode* node){
        int l=(node->left) ? go(node->left) : 0,r=(node->right) ? go(node->right) : 0;
        if (l==0) node->left=nullptr;
        if (r==0) node->right=nullptr;
        return l+r+node->val;
    }
};
*/

/*
 // AC verbose
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K){
        int N=(int)A.size();
        vector<int> S(N+1);
        for (int i=1; i<=N; ++i)
            S[i]=S[i-1]+A[i-1];
        vector<vector<double>> memo(N,vector<double>(K+1));
        return go(S,0,K,memo);
    }
private:
    double go(const vector<int>& S, int beg, int K, vector<vector<double>>& memo){
        if (memo[beg][K]>0)
            return memo[beg][K];
        const int N=(int)S.size()-1,end=N-K+1;
        if (K==1)
            return memo[beg][K]=avg(S,beg,end);
        double max_avg=0.0;
        for (int i=beg,j=i+1; j<=end; ++j){
            double group_k_avg=avg(S,i,j);
            double remaining_group_k_minus_1_avg=go(S,j,K-1,memo);
            if (max_avg < group_k_avg + remaining_group_k_minus_1_avg)
                max_avg=group_k_avg + remaining_group_k_minus_1_avg;
        }
        return memo[beg][K]=max_avg;
    }
    inline double avg(const vector<int>& S, int i, int j) const {
        return ( S[j]-S[i] ) / double( j-i );
    }
};
 */


 // AC more concise
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K){
        int N=(int)A.size();
        vector<int> S(N+1);
        for (int i=1; i<=N; ++i)
            S[i]=S[i-1]+A[i-1];
        memset(memo,0,sizeof(memo));
        for (int i=0; i<N; ++i)
            memo[i][1]=avg(S,i,N);
        return go(S,0,K);
    }
private:
    double go(const vector<int>& S, int beg, int K){
        if (memo[beg][K]>0)
            return memo[beg][K];
        for (int i=beg,j=i+1; j<=S.size()-K; ++j)
            memo[beg][K]=max(memo[beg][K],avg(S,i,j)+go(S,j,K-1));
        return memo[beg][K];
    }
    inline double avg(const vector<int>& S, int i, int j) const {
        return ( S[j]-S[i] ) / double( j-i );
    }
    double memo[101][101];
};




int main(int argc, const char * argv[]) {
    
    /*
     
     Input:
     [[2,5],[7,7],[10,8],[10,10],[1,1]]
     Output:
     18.5
     Expected:
     14.5
     
     */
    
    /*
    vector<vector<int>> points {
        {2,5},
        {7,7},
        {10,8},
        {10,10},
        {1,1},
    };
    Solution s;
    auto r=s.largestTriangleArea(points);
    
    */

    
    
    /*
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(0);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(0);
    root->right=new TreeNode(1);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(1);
    
    Solution s;
    auto res=s.pruneTree(root);
    */
    
    Solution s;
    vector<int> A={1,2,3,4,5,6,7}; int K=4;
    auto r=s.largestSumOfAverages(A, K);
    
    return 0;
}


