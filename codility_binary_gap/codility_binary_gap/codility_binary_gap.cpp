//
//  main.cpp
//  codility_binary_gap
//
//  Created by CLAYTON WONG on 8/1/17.
//  Copyright © 2017 Clayton Wong. All rights reserved.
//

#include <iostream>

using namespace std;

int solution(int N) {
    
    int count=0;
    int max_count = 0;
    int i=31;
    while ( i >=0 && ! ((1<<i) & N ) ){
        i--;
    }
    
    while (--i >=0 ){
        if (N & (1<<i)){
            count=0;
        } else {
            count++;
        }
        max_count = max (max_count, count);
    }
    return max_count;
}

int main(){
    
    int num;
    cin >> num;
    
    cout << endl << solution(num) << endl;
    
    return 0;
}
