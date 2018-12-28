/*
 
 677. Map Sum Pairs
 
 https://leetcode.com/contest/leetcode-weekly-contest-50/problems/map-sum-pairs/
 
 Implement a MapSum class with insert, and sum methods.
 
 For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.
 
 For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.
 
 Example 1:
 Input: insert("apple", 3), Output: Null
 Input: sum("ap"), Output: 3
 
 Input: insert("app", 2), Output: Null
 Input: sum("ap"), Output: 5
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode{
public:
    unordered_map<string,int> dic;
    vector<shared_ptr<TrieNode>> next;
    TrieNode(string key, int val) : next{26,nullptr} {
        dic[key]=val;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() : _root{make_shared<TrieNode>("",0)} {}
    
    void insert(string key, int val) {
        int idx=0;
        auto curr=_root;
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        for (auto& ch : key){
            idx=ch-'a';
            if (!curr->next[idx]){
                curr->next[idx]=make_shared<TrieNode>(key,val);
            } else {
                curr->next[idx]->dic[key]=val;
            }
            curr=curr->next[idx];
        }
    }
    
    int sum(string prefix) {
        int res=0;
        auto curr=_root;
        for (auto& ch : prefix){
            int idx=ch-'a';
            if (curr->next[idx]){
                curr=curr->next[idx];
            } else {
                return 0;
            }
        }
        for (auto& item : curr->dic){
            res+=item.second;
        }
        return res;
    }
    
private:
    shared_ptr<TrieNode> _root;
};

int main(int argc, const char * argv[]) {
    
    MapSum solution;
    solution.insert("a", 3);
    
    
    while (true){
        string prefix;
        cout << "Prefix: ";
        cin >> prefix;
        cout << solution.sum(prefix) << endl;
    }
    
    
    return 0;
}



