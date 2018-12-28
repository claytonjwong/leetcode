/*
 
 CCI 4.6: Write an alogirthm to find the "next" node (i.e. in-order successor) of a given node in a binary search tree.  You may assume that each node has a link to its parent.
 
 
 
 Hint #79: Think about how an in-order traversal works and try to "reverse engineer" it.
 
 Hint #91: Here's one step of the logic: The successor of a specific node is the leftmost node of the right subtree.  What if there is no right subtree, though?
 
 */

#include <iostream>
#include <vector>

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
class BinTree {
public:
    BinTree() : root{NULL} {}
    void Insert(T val){
        if ( ! root ){
            root = new Node<T>(val);
        } else {
            
            Node<T>* curr = root;
            while (true){
                
                if ( val <= curr->val ){
                    if ( curr->left ){
                        curr = curr->left;
                    } else {
                        curr->left = new Node<T>(val);
                        curr->left->parent = curr;
                        break;
                    }
                } else { // val > curr->val
                    if ( curr->right ){
                        curr = curr->right;
                    } else {
                        curr->right = new Node<T>(val);
                        curr->right->parent = curr;
                        break;
                    }
                }
            }
        }
    }
    
    T Successor(T val){
        
        if (!root){
            return NULL;
        }
        
        // find the node with val
        Node<T>* target = NULL;
        Node<T>* curr;
        vector<Node<T>*> vec;
        vec.push_back(root);
        while (!vec.empty()){
            curr = vec.back();
            vec.pop_back();
            
            if ( curr->val == val ){
                target = curr;
                break;
            }
            
            if ( curr->left ){
                vec.push_back(curr->left);
            }
            
            if ( curr->right ){
                vec.push_back(curr->right);
            }
            
        }
        
        // check if node with val was found or not
        if ( ! target ){
            return NULL;
        }
        
        // see if there is a right-sub tree or not
        curr = target;
        if ( ! curr->right ){
            
            // no right sub-tree, if parent exists return the first parent
            // who's val is greater than the target node's value
            while ( curr->parent && curr->parent->val <= target->val){
                curr = curr->parent;
            }
            
            if ( ! curr->parent ){ // no parent with a value > target->val
                return NULL;
            } else {
                return curr->parent->val; // parent found with value > target->val
            }
        } else { // right sub-tree exists, return left-most node
            
            curr = curr->right;
            
            while (curr->left){
                curr = curr->left;
            }
            
            return curr->val;
        }
    }
private:
    Node<T>* root;
};




int main(int argc, const char * argv[]) {

    BinTree<int> bt;
    
    bt.Insert(8);
    bt.Insert(4);
    bt.Insert(2);
    bt.Insert(6);
    bt.Insert(5);
    bt.Insert(7);
    bt.Insert(10);
    bt.Insert(20);
    
    
    cout << "Enter values to find successors [-1 to END]." << endl;
    int val;
    int res;
    
    while (true){
        cout << "Input value: ";
        cin >> val;
        
        if (val == -1){
            break;
        }
        
        res = bt.Successor(val);
        cout << "The successor of " << val << " is " << res << endl;
    }

    

    
    return 0;
}
