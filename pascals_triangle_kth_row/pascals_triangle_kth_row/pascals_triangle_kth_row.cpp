//
//  main.cpp
//  pascals_triangle_kth_row
//
//  Created by CLAYTON WONG on 8/3/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> prev;
        vector<int> curr;
        
        // create first 2 rows,
        prev.push_back(1);
        if (rowIndex==0){ return prev; }
        
        curr.push_back(1);
        curr.push_back(1);
        if (rowIndex==1){ return curr; }
        
        // iteratively create the next row based on the previous row
        for (int row=2; row<=rowIndex; row++){

            //
            // save previous current
            //
            prev = curr;
            curr.clear();

            //
            // create new current based on previous
            //
            curr.push_back(1); // beginning 1

            /*
             
             n/k = n-1/k-1  + n-1/k
             
             n is curr row
             n-1 is prev row
             k is col
             
             */
            for (int col=1; col < prev.size(); col++){
                curr.push_back(prev[col-1]+prev[col]);
            }
            
            curr.push_back(1); // ending 1
        }
        
        return curr;
    }
    

    
};






int main(int argc, const char * argv[]) {
    
    
    Solution solution;
    
    vector<int> result = solution.getRow(5);
    
    
    
    
    return 0;
}







