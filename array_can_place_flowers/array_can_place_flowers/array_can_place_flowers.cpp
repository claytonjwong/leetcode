/*
 
 605. Can Place Flowers
 
 https://leetcode.com/problems/can-place-flowers/discuss/
 
 Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.
 
 Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.
 
 Example 1:
 Input: flowerbed = [1,0,0,0,1], n = 1
 Output: True
 Example 2:
 Input: flowerbed = [1,0,0,0,1], n = 2
 Output: False
 Note:
 The input array won't violate no-adjacent-flowers rule.
 The input array size is in the range of [1, 20000].
 n is a non-negative integer which won't exceed the input array size.
 
 */



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    
    /*
     
     Iterate through the flowerbed from left-to-right and plant flowers when there is an available position. I think of this solution like sliding window of size 3 ( prev, curr, next). If all 3 are available, then plant the flowers in curr, and continue sliding left-to-right. Each time a flower is planted decrement n. If n reaches 0, then all flowers were planted, otherwise there are some left over flowers which were NOT planted.
     
     */
    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if (n==0) { return true; }
        
        return canPlaceFlowersHelper( flowerbed.begin(), flowerbed.end(), n );
        
    }
    
    typedef typename vector<int>::iterator itr;
    bool canPlaceFlowersHelper( itr begin, itr end, int n ){
        
        itr curr = begin;
        
        /*
         go through the flower bed
         and insert at first available position
         and decrement n, return true if n reaches 0
         */
        while (curr != end){

            /*
             
             current position can hold flowers if:
             
                * the previous position is available
                * the current position is available
                * the next position is available
             
             */
            bool prev_avail = false;
            if ( curr==begin || *(curr-1)==0 ){ prev_avail = true; }
            
            bool curr_avail = false;
            if ( *curr == 0 ) { curr_avail = true; }
            
            bool next_avail = false;
            if ( (curr+1)==end || *(curr+1)==0 ){ next_avail = true; }
            
            if ( prev_avail && curr_avail && next_avail ){
                
                *curr = 1; // plant flowers here
                n--;
                
                if (n==0){
                    return true; // no more flowers left to plant
                }
            }
            
            curr++; // move to the next flower bed position
        }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {

    vector<int> flowerbed1 { 1,0,0,0,1 };
    vector<int> flowerbed2 { 1,0,0,0,1 };
    
    Solution solution;
//    cout << "1 == " << solution.canPlaceFlowers(flowerbed, 1) << endl;
    cout << "0 == " << solution.canPlaceFlowers(flowerbed, 2) << endl;
    
    return 0;
}
