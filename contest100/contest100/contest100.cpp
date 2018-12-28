/*

Rank        Name            Score   Finish Time     Q1 (2)    Q2 (3)    Q3 (6)    Q4 (7)
548 / 4008  claytonjwong    5       0:13:51         0:01:15   0:13:51

Q1: https://leetcode.com/problems/monotonic-array/description/
A1: https://leetcode.com/problems/monotonic-array/discuss/165899/1-liner-C++

Q2: https://leetcode.com/problems/increasing-order-search-tree/description/
A2: https://leetcode.com/problems/increasing-order-search-tree/discuss/165898/1-liner-C++

*/

#include <iostream>
#include <list>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return is_sorted( A.begin(), A.end() )  ||  is_sorted( A.rbegin(), A.rend() );
    }
};
*/


struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

/*
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* ans=nullptr) {
        vector<int> inOrder;
        if ( root != nullptr )
            go( root, inOrder );
        ans = createTree( inOrder );
        return ans;
    }
private:
    void go(TreeNode* root, vector<int>& inOrder)
    {
        if ( root == nullptr ) return;
        
        go( root->left, inOrder );
        inOrder.push_back( root->val );
        go( root->right, inOrder );
    }
    
    TreeNode* createTree( const vector<int>& inOrder )
    {
        TreeNode *sentinel = new TreeNode( -1 ), *current=sentinel;
        
        for_each( inOrder.begin(), inOrder.end(),[&](int val)
        {
            current->right = new TreeNode( val );
            current = current->right;
        });
        return sentinel->right;
    }
};
*/

/*
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        go( root );
        return sentinel->right;
    }
private:
    TreeNode *sentinel{ new TreeNode{-1} }, *current{ sentinel };
    void go(TreeNode* root)
    {
        if ( root == nullptr ) return;
        go( root->left );
        current = current->right = new TreeNode( root->val );
        go( root->right );
    }
};
*/

/*
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        go( root );
        return sentinel->right;
    }
private:
    TreeNode *sentinel{ new TreeNode{-1} }, *curr{ sentinel };
    void go(TreeNode* root)
    {
        if ( root ) go( root->left ), curr = curr->right = new TreeNode( root->val ), go( root->right );
    }
};
*/

/*
class Solution {
    TreeNode *sentinel{ new TreeNode{-1} }, *curr{ sentinel };
public:
    TreeNode* increasingBST(TreeNode* root) {
        if ( root ) increasingBST( root->left ), curr = curr->right = new TreeNode( root->val ), increasingBST( root->right );
        return sentinel->right;
    }
};
*/

using T = TreeNode;
class Solution{ T *X{ new T{-1} }, *C{ X };
public:
    T* increasingBST(T* R) {
        if(R) increasingBST(R->left), C=C->right=new T{R->val}, increasingBST(R->right); return X->right;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    TreeNode* root = new TreeNode( 5 );
    root->left = new TreeNode ( 3 );
    root->left->left = new TreeNode( 2 );
    root->left->right=new TreeNode(4);
    root->right = new TreeNode ( 6 );
    auto res = s.increasingBST( root );
    
    
    return 0;
}


// TLE

/*
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A, unordered_set<int> unique={}) {
        for ( int i=0,N=static_cast<int>( A.size() ); i<N; ++i)
        {
            int orValue = 0;
            for ( int j=i; j<N; ++j)
            {
                orValue |= A[j];
                unique.insert( orValue );
            }
        }
        return static_cast<int>( unique.size() );
    }
};


int main(int argc, const char * argv[]) {

    Solution s;
    vector<int> v1{0};
    cout << "[0] = " << s.subarrayBitwiseORs(v1) << endl;
    
    vector<int> v2{1,1,2};
    cout << "[1,1,2] = " << s.subarrayBitwiseORs(v2) << endl;

    vector<int> v3{1,2,4};
    cout << "[1,2,4] = " << s.subarrayBitwiseORs(v3) << endl;
}
*/
