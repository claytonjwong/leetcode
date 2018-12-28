/*
 
 Generic conversion from n (base 10) to n (base X)
 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int convertUsingString(int n, int x){
        
        string n_base_x = "";
        
        while ( n > 0 ){
            
            n_base_x = to_string(n % x) + n_base_x;
            n /= x;
        }
        
        return stoi(n_base_x);
    }
/* Not working right... looks backwards... */
//    
//    int convertUsingInt(int n, int x){
//        
//        int n_base_x = 0;
//        
//        while ( n > 0 ){
//            
//            n_base_x *= 10;
//            n_base_x += (n % x) * n_base_x;
//            
//            n /= x;
//        }
//        
//        return n_base_x;
//    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    int n, x;
    while(true){
        
        cout << "Enter n: ";
        cin >> n;
        cout << "Enter x: ";
        cin >> x;
        
        cout << endl << n << " base " << x << " = " << solution.convertUsingString(n,x) << endl << endl;
//        cout << endl << n << " base " << x << " = " << solution.convertUsingInt(n,x) << endl << endl;
        
    }
    
    
    return 0;
}




