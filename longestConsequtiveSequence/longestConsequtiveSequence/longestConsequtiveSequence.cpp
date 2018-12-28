/*
 
 128. Longest Consecutive Sequence
 
 https://leetcode.com/problems/longest-consecutive-sequence/description/
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
 **Solution 1:** Union Find.  Create a union of sequential valued nodes.  Find each node's parent, and return the maximum parent count.
 
 */

/*
 **Solution 2:** Find sequence beginnings and count longest sequence
 
 Insert each unique number into an unordered set to be used for O(1) lookup.  For each number in the set, see if that number is the potential beginning of a sequence.  We know that the number is a potential beginning of a sequence if there does NOT exist a number with value one less than the current number's value.  Track the longest sequence and return it.
*/

/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        unordered_map<int,Node*> m;
        for (auto num: s) m[num]=new Node(num);
        for (auto num: s){
            if (m.count(num-1))
                u(m[num],m[num-1]);
            if (m.count(num+1))
                u(m[num],m[num+1]);
        }
        unordered_map<Node*,int> pc; // parent count
        int maxi=0;
        for (auto num: s)
            maxi=max(maxi,++pc[f(m[num])]);
        return maxi;
    }
private:
    class Node {
    public:
        int val;
        Node* parent;
        Node(int val) : val{val}, parent{this} {}
    };
    Node* f(Node* x){ // find (with path compression)
        if (x!=x->parent)
            x->parent=f(x->parent);
        return x->parent;
    }
    void u(Node* a, Node* b){ // union (arbitrarily set a parent to b parent)
        auto pa=f(a),pb=f(b);
        if (pa==pb) return;
        pa->parent=pb;
    }
};
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        unordered_map<int,int> p;
        for (int n: s) p[n]=n;
        for (int n: s){
            if (p.count(n-1))
                u(p,p[n],p[n-1]);
            if (p.count(n+1))
                u(p,p[n],p[n+1]);
        }
        unordered_map<int,int> pc; // parent count
        int maxi=0;
        for (auto x: p)
            maxi=max(maxi,++pc[f(p,x.second)]);
        return maxi;
    }
private:
    int f(unordered_map<int,int>& p, int x){ // find (with path compression)
        if (x!=p[x])
            p[x]=f(p,p[x]);
        return p[x];
    }
    void u(unordered_map<int,int>& p, int a, int b){ // union (arbitrarily set a parent to b parent)
        auto pa=f(p,a),pb=f(p,b);
        if (pa==pb) return;
        p[pa]=pb;
    }
};

class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int maxi=0;
        for (int n: s){
            if (!s.count(n-1)){ // n is the beginning of a potential sequence
                int seq=0;
                while (s.count(n++)) ++seq;
                maxi=max(maxi,seq);
            }
        }
        return maxi;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    Solution2 s2;
    vector<int> nums { 100, 4, 200, 1, 3, 2 };
    cout << s.longestConsecutive(nums) << endl;
    cout << s2.longestConsecutive(nums) << endl;
    

    return 0;
}



