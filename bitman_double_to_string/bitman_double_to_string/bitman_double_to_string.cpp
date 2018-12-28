/*
 
 CCI 5.2 BitMan: given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, print the binary representation.  If the number cannot be represented acurately in binary with at most 32 characters, print "ERROR"
 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    void printBinary(double n){
        
        double original_n = n;
        string s = "0.";
        
        if (n == 0.0){
            
            s += "0";
            
            cout << "n (base 10)=" << to_string(n) << endl;
            cout << "n (base  2)=" << s << endl << endl << endl << endl;
            return;
        }
        
        int i=1;
        while (n > 0.0 && i <= 32){
            
            n *= 2;
            
            if (n >= 1.0){
                s += "1";
                n -= 1.0;
            } else {
                s += "0";
            }
            
            i++;
        }
        
        if (n != 0.0){
            cout << "ERROR..." << endl;
        }
        cout << "n (base 10)" << original_n << endl;;
        cout << "n (base  2)=" << s << endl;
        
        cout << endl << endl << endl;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    solution.printBinary(0.0);
    solution.printBinary(0.5);
    solution.printBinary(0.25);
    solution.printBinary(0.125);
    solution.printBinary(0.0625);
    solution.printBinary(0.3);
    
    
    return 0;
}


/* OUTPUT
 
 n (base 10)=0.000000
 n (base  2)=0.0
 
 
 
 n (base 10)0.5
 n (base  2)=0.1
 
 
 
 n (base 10)0.25
 n (base  2)=0.01
 
 
 
 n (base 10)0.125
 n (base  2)=0.001
 
 
 
 n (base 10)0.0625
 n (base  2)=0.0001
 
 
 
 ERROR...
 n (base 10)0.3
 n (base  2)=0.01001100110011001100110011001100
 
 
 
 Program ended with exit code: 0
 
 */

