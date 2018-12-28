//
//  main.cpp
//  pow
//
//  Created by CLAYTON WONG on 7/26/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    double myPow(double x, int n){
        
        if (n==1){
            return x;
        } else {
            return x * this->myPow(x, abs(n)-1);
        }
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution solution;
    
    cout << "1024 == " << solution.myPow(2, 10) << endl << endl;
    
    return 0;
}
