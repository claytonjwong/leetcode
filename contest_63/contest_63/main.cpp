//
//  main.cpp
//  contest_63
//
//  Created by CLAYTON WONG on 12/16/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=(int)cost.size();
        vector<int> dp(n);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for (int i=2; i<n; ++i)
            dp[i]=cost[i]+min(dp[i-2],dp[i-1]);
        return min(dp[n-2],dp[n-1]);
    }
};



/*
 
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int min_idx=-1;
        vector<map<char,int>> alpha_counts{};
        auto target=createMap(licensePlate);
        for (auto &&word: words){
            auto m=createMap(word);
            alpha_counts.push_back(m);
        }
        for (int i=0; i<words.size(); ++i){
            if (isSubset(target, alpha_counts[i])){
                if (min_idx==-1 || words[i].size()<words[min_idx].size())
                    min_idx=i;
            }
        }
        return words[min_idx];
    }
private:
    map<char,int> createMap(string& s){
        transform(s.begin(),s.end(),s.begin(),::tolower);
        map<char,int> m{};
        for (auto &&c: s)
            if (isalpha(c))
                m[c]=m.find(c)==m.end() ? 1 : m[c]+1;
        return m;
    }
    bool isSubset(map<char,int>& a, map<char,int>& b){
        for (auto &&x: a){
            char c=x.first;
            int n=x.second;
            if (b.find(c)==b.end() || (b.find(c)!=b.end() && n>b[c]))
                return false;
        }
        return true;
    }
};
 
 */

/*
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int cnt=0,m=(int)grid.size(),n=(int)grid[0].size();
        for (int i=0; i<m-1; ++i)
            for (int j=0; j<n-1; ++j)
                if (grid[i][j])
                    for (int k=i+1; k<m; ++k)
                        for (int l=j+1; l<n; ++l)
                            if (grid[i][l] && grid[k][l] && grid[k][j])
                                ++cnt;
        return cnt;
    }
};
*/

 /*
 
class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        return 0;
    }
private:
    set<pair<pair<int,int>,pair<int,int>>> getIsland(vector<vector<int>>& grid, int i, ){
        set<pair<pair<int,int>,pair<int,int>>> s{};
        
        return s;
    }
};

  */

int main(int argc, const char * argv[]) {

    vector<int> nums { 1,100,1,1,1,100,1,1,100,1 };
    Solution s;
    cout << s.minCostClimbingStairs(nums) << endl;

    
    /*
     
    string licensePlate = "1s3 PSt";
    vector<string>words = {"step", "steps", "stripe", "stepple"};
    
    
    
    Solution s;
    cout << s.shortestCompletingWord(licensePlate, words) << endl;
    
    */
     
/*
    Solution s;
    
    vector<vector<int>> grid {

        {1,1,1},
        {1,1,1},
        {1,1,1},
        
    };
    cout << s.countCornerRectangles(grid) << endl;
    */
    
    
    
    return 0;
}
