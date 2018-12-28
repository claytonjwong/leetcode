/*
 
 739. Daily Temperatures
 
 https://leetcode.com/problems/daily-temperatures/description/
 
 Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
 
 For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 
 Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int N=(int)t.size();
        vector<int> res(N);
        stack<pair<int,int>> st;
        for (int i=0; i<N; ++i){
            while (!st.empty() && st.top().first<t[i]){
                int j=st.top().second; st.pop();
                res[j]=i-j;
            }
            st.push({t[i],i});
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<int> temps { 73, 74, 75, 71, 69, 72, 76, 73 };
    //vector<int> temps {77,77,77,77,77,41,77,41,41,77};
    auto r=s.dailyTemperatures(temps);
    
    
    return 0;
}


