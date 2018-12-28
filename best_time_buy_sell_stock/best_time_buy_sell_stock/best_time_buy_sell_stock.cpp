/*
 
 121. Best Time to Buy and Sell Stock
 
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 
 Example 1:
 Input: [7, 1, 5, 3, 6, 4]
 Output: 5
 
 max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 Example 2:
 Input: [7, 6, 4, 3, 1]
 Output: 0
 
 In this case, no transaction is done, i.e. max profit = 0.
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        
        int max_profit = 0;
        int min_price = INT_MAX;
        for ( auto price : prices ){
            min_price = min( min_price, price );
            max_profit = max( max_profit, price - min_price );
        }
        
        return max_profit;
    }
};

//class Solution {
//public:
//    int maxProfit(vector<int>& prices){
//        
//        int mp = 0;
//        
//        int min_price = INT_MAX;
//        
//        for (int i=0; i < prices.size(); i++){
//            
//            min_price = min( min_price, prices[i] );
//            
//            mp = max ( mp, prices[i] - min_price );
//        }
//        
//        return mp;
//    }
//};

//class Solution {
//public:
//    
//    /* brute force O(n^2) TLE */
//
//    int maxProfit2(vector<int>& prices) {
//        
//        if ( prices.empty () ){
//            return 0;
//        }
//        
//        int m = 0;
//        for (int i=0; i < prices.size()-1; i++){
//            for (int j=i+1; j < prices.size(); j++){
//                
//                m = max ( m, prices[j] - prices[i] );
//            }
//        }
//        
//        return m;
//    }
//    
//    /* O(n) keep track of min, and keep trying to find new max based on that min */
//    int maxProfit(vector<int>& prices){
//        
//        int profit = 0;
//        
//        int min_price = INT_MAX;
//        
//        for ( auto price : prices ){
//            
//            min_price = min( min_price, price );
//            
//            profit = max( profit, price - min_price );
//        }
//        
//        return profit;
//    }
//    
//};


int main(int argc, const char * argv[]) {

    Solution solution;
    
    
    vector<int> test { 4, 3, 2, 3, 4, 7 };
    
    cout << "5 == " << solution.maxProfit(test) << endl;
    
    
    return 0;
}




