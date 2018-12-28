/*
 
 Tries: Contacts
 
 https://www.hackerrank.com/challenges/ctci-contacts
 
 Check out the resources on the page's right side to learn more about tries. The video tutorial is by Gayle Laakmann McDowell, author of the best-selling interview book Cracking the Coding Interview.
 We're going to make our own Contacts application! The application must perform two types of operations:
 
 add name, where  is a string denoting a contact name. This must store  as a new contact in the application.
 find partial, where  is a string denoting a partial name to search the application for. It must count the number of contacts starting with  and print the count on a new line.
 Given  sequential add and find operations, perform each operation in order.
 
 Input Format
 
 The first line contains a single integer, , denoting the number of operations to perform.
 Each line  of the  subsequent lines contains an operation in one of the two forms defined above.
 
 Constraints
 
 It is guaranteed that  and  contain lowercase English letters only.
 The input doesn't have any duplicate  for the  operation.
 Output Format
 
 For each find partial operation, print the number of contact names starting with  on a new line.
 
 Sample Input
 
 4
 add hack
 add hackerrank
 find hac
 find hak
 Sample Output
 
 2
 0
 Explanation
 
 We perform the following sequence of operations:
 
 Add a contact named hack.
 Add a contact named hackerrank.
 Find and print the number of contact names beginning with hac. There are currently two contact names in the application and both of them start with hac, so we print  on a new line.
 Find and print the number of contact names beginning with hak. There are currently two contact names in the application but neither of them start with hak, so we print  on a new line.
 
 */


#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    TrieNode(char val) : val{val}, isEnd{false}, word_count{0} {}
    char val;
    bool isEnd;
    int word_count;
    unordered_map<char,TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode(' ');
    }
    
    void Add(string word){
        
        if (word.size() == 0){
            return;
        }
        
        TrieNode* curr = root;
        unordered_map<char,TrieNode*>::iterator itr;
        for (char ch : word){
            curr->word_count++;
            itr = curr->children.find(ch);
            if (itr == curr->children.end()){
                curr->children[ch] = new TrieNode(ch);
            }
            curr = curr->children[ch];
        }
        
        // one last special update for the very last child
        curr->word_count++;
        curr->isEnd = true;
    }
    
    int Find(string prefix){
        
        int child_count = 0;
        
        if (prefix.size() == 0){
            return 0;
        }
        
        TrieNode* curr = root;
        unordered_map<char,TrieNode*>::iterator itr;
        for (char ch : prefix){
            itr = curr->children.find(ch);
            if (itr == curr->children.end()){
                return 0;
            }
            curr = curr->children[ch];
        }
        
        
        return curr->word_count;
    }
    
private:
    TrieNode* root;
};

int main(){
    
    Trie trie;
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        
        if (op == "add"){
            trie.Add(contact);
        }
        
        if (op == "find"){
            cout << trie.Find(contact) << endl;
        }
    }
    return 0;
}
