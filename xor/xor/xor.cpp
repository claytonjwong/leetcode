/*
 
 XOR
 
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void PrintBinary(int n){
    
    string nstr="";
    for (int i=7; i>=0; i--){
        if (n & (1<<i)){
            nstr += "1";
        } else {
            nstr += "0";
        }
    }
    cout << nstr << endl;
}

void PrintIndex(){

    string istr="";
    for (int i=7; i>=0; i--){
        istr += to_string(i%10);
    }
    cout << istr << endl;
}

void SwapRightMostNBits(int& a, int& b, unsigned int n){
    
    if (&a==&b) { return; }
    if (n>31) { n=31; }
    
    int mask=(1<<n)-1;
    a ^= (b & mask);
    b ^= (a & mask);
    a ^= (b & mask);
}



int main(int argc, const char * argv[]) {

    /*
     
     x = x ^ y
     y = x ^ y
     x = x ^ y
     
     x1 = x ^ y
     y1 = x1 ^ y
     x2 = x1 ^ y1
     
     
     y1 = x1 ^ y 
     y1 = (x ^ y ) ^ y
     y1 = x ^ ( y ^ y )
     y1 = x ^ (0)
     y1 = x
     
     x2 = x1 ^ y1
     x2 = (x ^ y) ^ x
     x2 = y ^ (x^x)
     x2 = y ^ (0)
     x2 = y
     
     */
    
    int a = 1;
    int b = 2;

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    
    SwapRightMostNBits(a,b,32);
    
    cout << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    return 0;
}



