/*
 
 Find the greatest common divisor between two integer arrays and return the integer pair with greatest sum
 
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Key{
    int a;
    int b;
    

    bool operator==(const Key &other) const {
        return  ( a == other.a && b == other.b ) || ( b == other.a && a == other.b );
    }
};

namespace std {
    template <>
    struct hash<Key> {

        size_t operator()(const Key& k) const {
            return k.a + k.b;
        }
    };
}

class Solution{
public:
    
    int gcd(int a, int b){
        
        // gcd(a,0) = a
        // gcd(a,b) = gcd( b, a % b )
        while (b > 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        
        return a;
    }
    
    int sum_of_gcd(vector<int> A, vector<int> B){
        
        int max_gcd = 0;
        int max_sum = 0;
        unordered_map<Key,int> umap;
        
        for (int i=0; i < A.size(); i++){
            for (int j=0; j < B.size(); j++){
                
                Key k;
                k.a = A[i];
                k.b = B[j];
                
                int curr_gcd;
                if ( umap[k] ){
                    curr_gcd = umap[k]; // look up gcd
                } else {
                    curr_gcd = gcd(A[i],B[j]); // calculate and store gcd
                    umap[k]=curr_gcd;
                }
                
                
                if (curr_gcd > max_gcd){
                    max_gcd = curr_gcd;
                    max_sum = A[i] + B[i];
                }
                
                if ( curr_gcd == max_gcd && (A[i] + B[j]) > max_sum ){
                    max_sum = A[i] + B[j];
                }
            }
        }
        
        return max_sum;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> test1 = { 3,1,4,2,8, 24,3,1,4,2,8, 24};
    vector<int> test2 = { 5,2,8,3,5,2,8,3 };
    
    Solution solution;
    int result = solution.sum_of_gcd(test1, test2);
    cout << endl << endl << "Result: " << result << endl << endl;
    
    return 0;
}
