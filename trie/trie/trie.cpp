/*
 
 208. Implement Trie (Prefix Tree)
 
 https://leetcode.com/problems/implement-trie-prefix-tree/description/
 
 
 Implement a trie with insert, search, and startsWith methods.
 
 Note:
 You may assume that all inputs are consist of lowercase letters a-z.
 
 */

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode(char val) : val{val}, isEnd{false} {}
    char val;
    bool isEnd;
    unordered_map<char,TrieNode*> children;
};

class Trie {
public:
    Trie (){
        root = new TrieNode(' ');
    }
    
    void insert(string word){
        
        TrieNode* curr = root;
        unordered_map<char,TrieNode*>::iterator itr;
        for (char ch : word){
            
            /*
             iterate to the next character in current's children,
             add the character is it is missing in current's children
             */
            itr = curr->children.find(ch);
            if (itr == curr->children.end()){
                curr->children[ch] = new TrieNode(ch);
            }
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }
    
    bool search(string word){
        TrieNode* last_node_found = startsWithHelper(word);
        return last_node_found && last_node_found->isEnd;
    }
    
    bool startsWith(string prefix){
        return startsWithHelper(prefix) != NULL;
    }

private:
    
    TrieNode* startsWithHelper(string prefix){
        
        TrieNode* curr = root;
        
        unordered_map<char,TrieNode*>::iterator itr;
        for (char ch : prefix){
            itr = curr->children.find(ch);
            if (itr == curr->children.end()){
                return NULL;
            }
            curr = curr->children[ch];
        }
        
        return curr;
    }
    
    TrieNode* root;
};

int main(int argc, const char * argv[]) {

    Trie trie;
    trie.insert("le");
    trie.insert("leetcode");
    
    
    cout << "1 == " << trie.search("le") << endl;
    cout << "1 == " << trie.startsWith("leet") << endl;
    cout << "0 == " << trie.search("leet") << endl;
    cout << "1 == " << trie.search("leetcode") << endl;
    
    return 0;
}





