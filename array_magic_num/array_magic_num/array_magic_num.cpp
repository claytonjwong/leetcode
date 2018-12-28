/*
 
 CCI CH 8.3 Magic Index: A magic index in an array A[0..n-1] is defined to be an index such that
 A[i] = i/  Given a sorted array of distinct integers, write a method to find a magic index,
 if one exists, in array A
 
 */

#include <iostream>
#include <vector>

using namespace std;

class NoMagicException : public exception {
public:
    const char* what(){
        return "NoMagicException";
    }
} no_magic_ex ;

class Solution{
public:
    
    int magicIndex(vector<int>& A){
        return magicIndex(A, 0, A.size());
    }
    
    int magicIndex(vector<int>& A, int beg, int end){
        
        if (beg == end){
            throw no_magic_ex;
        }
        
        int idx = (beg+end)/2;
        int num = A[idx];
        
        if      ( idx == num ) { return idx; } // match
        else if ( idx < num  ) { return magicIndex(A, beg, idx);   } // left half
        else   /* idx > num */ { return magicIndex(A, idx+1, end); } // right half
    }
    
};


int main(int argc, const char * argv[]) {
    
    
    Solution solution;
    
    vector<int> test1
    {   0, // 0
        2, // 1
        3, // 2
        4, // 3
    };
    
    try{
        
        cout << solution.magicIndex(test1) << endl;
        
    } catch ( NoMagicException& e ){
        
        cout << e.what() << endl;
    }
    
    return 0;
}



