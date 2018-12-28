/*

 339. Nested List Weight Sum
 
 Q: https://leetcode.com/problems/nested-list-weight-sum/description/
 
 A: https://leetcode.com/problems/nested-list-weight-sum/discuss/124490/Concise-C++-recursive-solution-(-EASY-to-understand-)
 
 */


#include <iostream>
#include <vector>

using namespace std;


// This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
     
   public:
     
     // Constructor initializes an empty nested list.
     NestedInteger(){}

     // Constructor initializes a single integer.
     NestedInteger(int value) : val{value} {}

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const { return true; }

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const { return val; }

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value) { val=value; }

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 private:
     int val;
 };


class Solution {
public:
    int depthSum(vector<NestedInteger>& v) {
        return go(v);
    }
private:
    int go(const vector<NestedInteger>& v, int d=0){
        int sum=0;
        for (auto& x: v)
            sum+=x.isInteger() ? d*x.getInteger() : go(x.getList(), d+1);
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    
    
    
    
    return 0;
}



