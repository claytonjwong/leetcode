/*
 
 CCI 4.8: Design an algorithm and write code t o fine the first common ancestor of two nodes in a binary tree.  Avoid storing additional nodes in a data structure.  Note: This is not necessarily a binary search tree.
 
 */

#include <iostream>
#include <queue>
#include <time.h>

using namespace std;

template<class T>
class Node{
public:
    Node(T val) : val{val}, parent{NULL}, left{NULL}, right{NULL} {}
    T val;
    Node<T>* parent;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class NodeFactory{
public:
    static Node<T>* Produce(T val) {
        return new Node<T>(val);
    }
};

template<class T>
class Solution{
public:
    static void SetSeed(int seed){
        srand(time(NULL));
    }
    
    static void Insert(Node<T>* root, Node<T>* node){
        
        if (!root){
            root = node;
            return;
        }
        
        Solution<T>::SetSeed(rand());
        Node<T>* curr = root;
        while (true){
            // randomly go left/right to insert this node
            if (rand() % 2 == 0){
                if (!curr->left){
                    curr->left = node;
                    node->parent = curr;
                    return;
                } else {
                    curr = curr->left;
                }
            } else { // go right
                if (!curr->right){
                    curr->right = node;
                    node->parent = curr;
                    return;
                } else {
                    curr = curr->right;
                }
            }
        }
    }
    
    static bool IsFound(Node<T>* root, Node<T>* node){
        
        // sanity checks
        if (!root || !node){
            return false;
        }
        
        queue<Node<T>*> q;
        Node<T>* result=NULL;
        
        // traverse tree to ensure node exist in the tree
        // by comparing memory addresses of the nodes
        q.push(root);
        while(!q.empty()){
            
            Node<T>* curr = q.front();
            q.pop();
            
            if (curr == node){
                return true;
            }
            
            if (curr->left){
                q.push(curr->left);
            }
            
            if (curr->right){
                q.push(curr->right);
            }
        }
        return false;
    }
    
    static Node<T>* FirstCommonAncestorViaParent(Node<T>* root, Node<T>* a, Node<T>* b){
        
        Node<T>* result = NULL;
        Node<T>* curr = NULL;
        
        // ensure a and b exist in the tree
        if ( ! Solution<T>::IsFound(root, a) || ! Solution<T>::IsFound(root, b)){
            return NULL;
        }
        
        // see how far away a and b are from the root
        int a_depth=0;
        int b_depth=0;
        
        curr = a;
        while(curr && curr->parent){
            a_depth++;
            curr = curr->parent;
        }
        
        curr = b;
        while(curr && curr->parent){
            b_depth++;
            curr = curr->parent;
        }
        
        // move up the deeper node's parents until the depths are equal,
        // then traverse up to the root together to find the first common ancestor
        while ( a_depth > b_depth ){
            a_depth--;
            a = a->parent;
        }
        
        while ( b_depth > a_depth ){
            b_depth--;
            b = b->parent;
        }
        
        while (a != b){
            a = a->parent;
            b = b->parent;
        }
        
        return a; // both a and b point to the same node, arbitarily return a
        
    }
    
    static Node<T>* FirstCommonAncestorViaSearch(Node<T>* root, Node<T>* a, Node<T>* b){
        
        if ( ! Solution<T>::IsFound(root, a) || ! Solution<T>::IsFound(root, b)){
            return NULL;
        }
        
        return Solution<T>::FirstCommonAncestorViaSearchHelper(root, a, b);
    }
    
    static Node<T>* FirstCommonAncestorViaSearchHelper(Node<T>* root, Node<T>* a, Node<T>* b){
        
        // root is common ancestor, since a and b are found in the tree
        // but we need to check further to find the first common ancestor
        Node<T>* result = root;
        
        // first common ancestor is found when a exists in the left sub-tree
        // and b exists in the right sub-tree ( or vice-versa )
        if ( Solution<T>::IsFound(root->left, a) && Solution<T>::IsFound(root->right, b) ){
            return root;
        }
        else
        if ( Solution<T>::IsFound(root->right, a) && Solution<T>::IsFound(root->left, b) ){
            return root;
        }
        else // both a and b are in the left sub-tree, recurse left and check again
        if ( Solution<T>::IsFound(root->left, a) && Solution<T>::IsFound(root->left, b) ){
            return Solution<T>::FirstCommonAncestorViaSearchHelper(root->left, a, b);
        }
        else // both a and b are in the right sub-tree recurse right and check again
        if ( Solution<T>::IsFound(root->right, a) && Solution<T>::IsFound(root->right, b) ){
            return Solution<T>::FirstCommonAncestorViaSearchHelper(root->right, a, b);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {


    Node<int>* root = NodeFactory<int>::Produce(10);
    
    Node<int>* a = NodeFactory<int>::Produce(69);
    Node<int>* b = NodeFactory<int>::Produce(13);

    Solution<int>::Insert(root, NodeFactory<int>::Produce(int(rand()%100)));
    Solution<int>::Insert(root, NodeFactory<int>::Produce(int(rand()%100)));
    Solution<int>::Insert(root, NodeFactory<int>::Produce(int(rand()%100)));
    Solution<int>::Insert(root, NodeFactory<int>::Produce(int(rand()%100)));
    Solution<int>::Insert(root, b);
    Solution<int>::Insert(root, NodeFactory<int>::Produce(int(rand()%100)));
    Solution<int>::Insert(root, NodeFactory<int>::Produce(int(rand()%100)));
    Solution<int>::Insert(root, NodeFactory<int>::Produce(int(rand()%100)));
    Solution<int>::Insert(root, NodeFactory<int>::Produce(int(rand()%100)));
    Solution<int>::Insert(root, a);
    
    
    
    
    
    Node<int>* ancestor_via_parent = Solution<int>::FirstCommonAncestorViaParent(root, a, b);
    Node<int>* ancestor_via_search = Solution<int>::FirstCommonAncestorViaSearch(root, a, b);
    
    cout << "FirstCommonAncestorViaParent == " << ancestor_via_parent->val << endl;
    cout << "FirstCommonAncestorViaSearch == " << ancestor_via_search->val << endl;
    
    return 0;
}





