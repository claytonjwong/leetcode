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
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
class MapSum {
public:
    void insert(string key, int val) {
        bool found=K.find(key)!=K.end();
        K.insert(key);
        for (int i=1; i<=(int)key.size(); ++i){
            if (found)
                M[key.substr(0,i)]=val;
            else
                M[key.substr(0,i)]+=val;
        }
    }
    int sum(string prefix) {
        return M[prefix];
    }
private:
    unordered_map<string,int> M;
    unordered_set<string> K;
};
 */


class MapSum {
public:
    void insert(string key, int val) {
        for (int i=1,N=(int)key.size(),found=!(K.insert(key).second); i<=N; ++i)
            M[key.substr(0,i)]=found ? val : val+M[key.substr(0,i)];
    }
    int sum(string prefix) { return M[prefix]; }
private:
    unordered_map<string,int> M;
    unordered_set<string> K;
};


/*
class MapSum {
public:
    void insert(string key, int val) {
        m[key]=val;
    }
    int sum(string prefix) {
        int ans=0, N=(int)prefix.size();
        for (auto itr=m.lower_bound(prefix); itr!=m.end(); itr++)
            if (itr->first.substr(0,N)==prefix){ ans+=itr->second; } else { break; }
        return ans;
    }
private:
    map<string,int> m;
};
*/

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main(int argc, const char * argv[]) {

    MapSum solution;
    solution.insert("apple", 3);
    solution.insert("app", 2);
    solution.insert("othera", 69);
    solution.insert("otherb", 69);
    solution.insert("otherc", 69);
    cout << solution.sum("ap") << endl;
    
    
    
    return 0;
}




