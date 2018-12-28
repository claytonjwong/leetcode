/*
 
 31. Next Permutation
 
 https://leetcode.com/problems/next-permutation/description/
 
 47. Permutations II
 
 https://leetcode.com/problems/permutations-ii/description/
 
 
 
 https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 
 The following algorithm generates the next permutation lexicographically after a given permutation.
 It changes the given permutation in-place.
 
 1) Find the largest index k such that a[i] < a[i + 1].
    ( If no such index exists, the permutation is the last permutation. )
 2) Find the largest index j greater than i such that a[i] < a[j].
 3) Swap the value of a[i] with that of a[j].
 4) Reverse the sequence from a[i + 1] up to and including the final element a[n].
 
 */

#include <iostream>
#include <vector>
#include <set>
#include "TestHarness.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size()==1) return;
        int N=(int)nums.size(),i=N-2,j=N-1;
        while (i>=0 && nums[i]>=nums[i+1]) --i;
        if (i==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        while (nums[i]>=nums[j]) --j;
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<int> curr=nums;
        while (!s.count(curr)){
            s.insert(curr);
            nextPermutation(curr);
        }
        return {s.begin(),s.end()};
    }
};



TEST(empty,NP){
    Solution s;
    vector<int> nums;
    s.nextPermutation(nums);
    CHECK_EQUAL(nums.size(), 0);
}

TEST(single,NP){
    Solution s;
    vector<int> nums{1};
    s.nextPermutation(nums);
    CHECK_EQUAL(nums.size(), 1);
}

TEST(dub,NP){
    Solution s;
    vector<int> a{1,2},b{2,1};
    s.nextPermutation(a);
    CHECK_EQUAL(a[0],b[0]);
    CHECK_EQUAL(a[1],b[1]);
}

TEST(triple,NP){
    Solution s;
    vector<int> a={1,2,3},b={1,3,2};
    s.nextPermutation(a);
    CHECK_EQUAL(a[0],b[0]);
    CHECK_EQUAL(a[1],b[1]);
    CHECK_EQUAL(a[2],b[2]);
    
    b={2,1,3};
    s.nextPermutation(a);
    CHECK_EQUAL(a[0],b[0]);
    CHECK_EQUAL(a[1],b[1]);
    CHECK_EQUAL(a[2],b[2]);

    b={2,3,1};
    s.nextPermutation(a);
    CHECK_EQUAL(a[0],b[0]);
    CHECK_EQUAL(a[1],b[1]);
    CHECK_EQUAL(a[2],b[2]);

    b={3,1,2};
    s.nextPermutation(a);
    CHECK_EQUAL(a[0],b[0]);
    CHECK_EQUAL(a[1],b[1]);
    CHECK_EQUAL(a[2],b[2]);

    b={3,2,1};
    s.nextPermutation(a);
    CHECK_EQUAL(a[0],b[0]);
    CHECK_EQUAL(a[1],b[1]);
    CHECK_EQUAL(a[2],b[2]);
    
    s.nextPermutation(a);
    CHECK(is_sorted(a.begin(), a.end()));
}

TEST(end,NP){
    Solution s;
    vector<int> nums={3,2,1};
    s.nextPermutation(nums);
    CHECK(is_sorted(nums.begin(),nums.end()));
}

TEST(dups,NP){
    Solution s;
    vector<int> dups={1,1,2};
    vector<int> expected={1,2,1};
    s.nextPermutation(dups);
    CHECK_EQUAL(dups[0],expected[0]);
    CHECK_EQUAL(dups[1],expected[1]);
    CHECK_EQUAL(dups[2],expected[2]);
    
    expected={2,1,1};
    s.nextPermutation(dups);
    CHECK_EQUAL(dups[0],expected[0]);
    CHECK_EQUAL(dups[1],expected[1]);
    CHECK_EQUAL(dups[2],expected[2]);

    s.nextPermutation(dups);
    CHECK(is_sorted(dups.begin(), dups.end()));
}

TEST(unique,NP){
    Solution s;
    vector<int> nums={1,2,3};
    auto r=s.permuteUnique(nums);
    CHECK_EQUAL(r.size(),6);
}






