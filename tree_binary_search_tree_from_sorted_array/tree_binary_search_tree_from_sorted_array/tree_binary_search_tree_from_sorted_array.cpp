/*
 
 Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
 
 */

#include <iostream>
#include <vector>

using namespace std;

// []

// [1]

// [1,2] n=2   left half: [0:n/2-1]=[0:0]=1  root=[n/2]=[1]=2  right half: [n/2+1:n)=[2,2)=N/A

// [1,2,3] n=3  left half: [0:n/2-1]=[0:0]=1   root=[n/2]=[1]=2   right half: [n/2+1:n)=[2:3)=[2]=3

// [1,2,3,4] n=4 left half: [0:n/2-1]=[0:1]=1,2  root=[n/2]=[2]=3  right half: [n/2+1:n)=[3:4)=4

class TreeNode{
public:
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
    int val=0;
    TreeNode* left=NULL;
    TreeNode* right=NULL;
};

class MinTreeMaker {
public:
    static TreeNode* ToMinTree(vector<int>& sorted){
        
        TreeNode* root=NULL;
        
        if (sorted.size() == 0){
            return NULL;
        }
        
        if (sorted.size() == 1){
            return new TreeNode(sorted[0]);
        }
        
        // get left, middle, and right
        // left half: [0:n/2-1]  root=[n/2]  right half: [n/2+1:n)
        vector<int>::iterator left = sorted.begin();
        vector<int>::iterator mid = sorted.begin() + sorted.size() / 2;
        vector<int>::iterator right = sorted.end();
        
        vector<int> left_half(left,mid);        // [left:mid)
        vector<int> middle(mid,mid+1);          // [mid]
        vector<int> right_half(mid+1,right);    // [mid+1,right)
        
        // recursively create nand return tree root
        root = new TreeNode(middle[0]);
        root->left = MinTreeMaker::ToMinTree(left_half);
        root->right = MinTreeMaker::ToMinTree(right_half);
        
        return root;
    }
};


int main(int argc, const char * argv[]) {

    vector<int> test{1,2,3,4,5,6,7,8,9,10};
    TreeNode* tree = MinTreeMaker::ToMinTree(test);
    
    return 0;
}








