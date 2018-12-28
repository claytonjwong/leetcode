/*
 
 122. Best Time to Buy and Sell Stock II
 
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices){
        
        if (prices.empty()){ return 0; }
        
        int max_profit = 0;
        
        for (int i=0; i < prices.size() - 1; i++){
            int profit = prices[i+1] - prices[i];
            
            if (profit > 0){
                max_profit += profit;
            }
        }
        
        return max_profit;
    }
};

//
//class Solution{
//public:
//    int maxProfit(vector<int>& prices){
//        
//        int mp = 0;
//        
//        if (prices.empty()) { return 0; }
//        
//        for (int i=0; i < prices.size() - 1; i++){
//                
//            int profit = prices[i+1] - prices[i];
//                
//            if (profit > 0){
//                mp += profit;
//            }
//        }
//                    
//        return mp;
//    }
//};
//
//
// initial dummy values
//
//#define MIN_PRICE INT_MAX
//#define MAX_PRICE INT_MIN


//class Solution{
//public:
//    int maxProfit(vector<int>& prices){
//        
//        if ( prices.empty() ) { return 0; }
//        
//        int profit=0;
//        
//        int min_price=MIN_PRICE;
//        int max_price=MAX_PRICE;
//        
//        int curr_price=0;
//        int next_price=0;
//        for ( int i=0; i < prices.size() - 1; i++ ){
//            
//            int j = i+1;
//            
//            curr_price = prices[i];
//            next_price = prices[j];
//            
//            if ( next_price > curr_price ){ // going up
//                
//                if ( min_price == MIN_PRICE ){ // set min price once, right before the upswing
//                
//                    min_price = curr_price;
//                }
//            }
//            
//            if ( next_price < curr_price ){ // going down
//                
//                //
//                // only track MAX after a min has been found and set
//                //
//                if ( min_price != MIN_PRICE ){
//                    
//                    max_price = curr_price;
//                }
//            }
//            
//            //
//            // we have found both a dip and a peak
//            //
//            if ( min_price != MIN_PRICE && max_price != MAX_PRICE ){
//                
//                profit += max_price - min_price;
//                
//                min_price = MIN_PRICE;
//                max_price = MAX_PRICE;
//            }
//        }
//        
//        //
//        // if we end on an upswing, then calculate the last profit
//        //
//        if ( min_price != MIN_PRICE ){
//            
//            profit += next_price - min_price;
//            
//        }
//        
//        return profit;
//    }
//};


int main(int argc, const char * argv[]) {

    Solution solution;
    vector<int> prices { 7, 1, 5, 3, 6, 4 };
    
    cout << "7 == " << solution.maxProfit(prices) << endl;
    
    return 0;
}




