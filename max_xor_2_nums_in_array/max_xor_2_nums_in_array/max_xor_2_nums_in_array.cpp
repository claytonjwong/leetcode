/*
 
 421. Maximum XOR of Two Numbers in an Array
 
 https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
 
 Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
 
 Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
 
 Could you do this in O(n) runtime?
 
 Example:
 
 Input: [3, 10, 5, 25, 2, 8]
 
 Output: 28
 
 Explanation: The maximum result is 5 ^ 25 = 28.
 
 
 
 Solution: https://discuss.leetcode.com/topic/92672/c-trie-with-explanation/2
 
 */

#include <iostream>
#include <vector>

using namespace std;


#define MAX_BIT_POS 31

class Solution{
public:
    int findMaximumXOR(vector<int>& nums){
        auto trie=make_shared<TrieNode>();
        return trie->findMaximumXOR(nums);
    }
    
private:
    class TrieNode{
    public:
        TrieNode() : _1{nullptr}, _0{nullptr} {}
        
        int findMaximumXOR(const vector<int>& nums){
            int maxXOR=0;
            auto root=Generate(nums);
            for (auto& num : nums){
                int x=0;
                auto curr=root;
                for (int i=MAX_BIT_POS; i>=0; --i){
                    x <<= 1;
                    bool opposite = !(num & (1<<i));
                    if (opposite){
                        if (curr->_1){ x|=1; curr=curr->_1; }
                        else {               curr=curr->_0; }
                    } else {
                        if (curr->_0){ x|=1; curr=curr->_0; }
                        else {               curr=curr->_1; }
                    }
                }
                maxXOR=max(maxXOR,x);
            }
            return maxXOR;
        }
        
    private:
        shared_ptr<TrieNode> _1;
        shared_ptr<TrieNode> _0;
        
        shared_ptr<TrieNode> Generate(const vector<int>& nums){
            auto root=make_shared<TrieNode>();
            for (auto& num : nums){
                auto curr=root;
                for (int i=MAX_BIT_POS; i>=0; --i){
                    if (num & (1<<i)){
                        if (!curr->_1){ curr->_1=make_shared<TrieNode>(); }
                        curr=curr->_1;
                    } else {
                        if (!curr->_0){ curr->_0=make_shared<TrieNode>(); }
                        curr=curr->_0;
                    }
                }
            }
            return root;
        }
    };
};

int main(int argc, const char * argv[]) {

    vector<int> nums{ 3, 10, 5, 25, 2, 8 };
    
    Solution solution;
    cout << solution.findMaximumXOR(nums) << endl;
    
    return 0;
}


