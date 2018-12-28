/*
 
 Towers of Hanoi: implement towers of hanoi
 
 
 */

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Solution{
public:
    void move(vector<T>& src, vector<T>& dst, vector<T>& aux){
        move ( src.size(), src, dst, aux );
    }

private:
    void move(int n, vector<T>& src, vector<T>& dst, vector<T>& aux){
        
        if (n == 0){ // base case
            return;
        }
        
        //
        // recusrive case n > 0
        //
        
        //
        // move n-1 disks from src to aux using dst as aux
        //
        move(n-1, src, aux, dst);
        
        //
        // move the nth disk from src to dst
        //
        dst.push_back(src.back());
        src.pop_back();
        
        //
        // move the remaining n-1 disks from aux to dst using src as aux
        //
        move(n-1, aux, dst, src);
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution<int> solution;
    vector<int> a{1,2,3},b,c;
    
    solution.move(a,b,c);
    
    
    return 0;
}



