/*
 
 CCI 4.3 List of Depths:  Given a binary tree, design an algorithm which creates a linked list of all nodes at each depth (e.g. if you have a tree with depth D, you'll have D linked lists
 
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template<class T>
class Node {
public:
    Node(T val) : val{val}, left{NULL}, right{NULL} {}
    T val;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class BinaryTree{
public:
    BinaryTree() : root{NULL} {}
    
    void Insert(T val){
        if (!root){
            root = new Node<T>(val);
            return;
        }
        
        Node<T>* curr = root;
        while(curr){
            if (val <= curr->val){
                if (!curr->left){
                    curr->left = new Node<T>(val);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (!curr->right){
                    curr->right = new Node<T>(val);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
    }
    
    void UpdateDepthList(Node<T>* node, int depth){
        
        if (!node){
            return;
        }
        
        if (depth_list.find(depth) == depth_list.end()){
            depth_list.insert({depth, new vector<Node<T>*>});
        }
        depth_list[depth]->push_back(node);
        
        UpdateDepthList(node->left, depth+1);
        UpdateDepthList(node->right, depth+1);
    }
    
    unordered_map<int,vector<Node<T>*>*> ListDepths(){
        
        depth_list.clear();
        UpdateDepthList(root, 0);
        return depth_list;
    }
    
    
private:
    Node<T>* root;
    unordered_map<int,vector<Node<T>*>*> depth_list;
};

int main(int argc, const char * argv[]) {

    BinaryTree<int> bt;
    bt.Insert(5);
    bt.Insert(3);
    bt.Insert(7);
    bt.Insert(2);
    bt.Insert(1);
    bt.Insert(4);
    bt.Insert(6);
    bt.Insert(8);
    bt.Insert(10);
    
    
    unordered_map<int,vector<Node<int>*>*> umap = bt.ListDepths();
    
    
    
    for ( auto item : umap ){
        cout << "Key: " << item.first << " == ";
        for ( auto node : *item.second ){
            cout << node->val << ", ";
        }
        cout << endl;
    }
    
    return 0;
}
