/*
 
 CCI CH 5.5: Explain what the follow code does: ((n & (n-1)) == 0)
 
 */

#include <iostream>

using namespace std;

void print_bitpos(int n){
    if (n < 0) {
        return;
    }
    
    cout << n % 10;
    print_bitpos(n-1);
}

void print_binary(int n){
    for (int i=31; i >=0; i--){
        if (n & 1<<i){
            cout << "1";
        } else {
            cout << "0";
        }
    }
}

int main(int argc, const char * argv[]) {

    
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << endl << endl;
    
    // n & n-1 == 0 is a check for power of 2
    
    cout << "      ";
    print_bitpos(31);
    cout << endl;
    cout << "n   : ";
    print_binary(n);
    cout << " == " << n << endl;
    
    cout << "n-1 : ";
    print_binary(n-1);
    cout << " == " << n << endl;
    
    
    if (( n & (n-1)) == 0){
        cout << endl << "Summary: (n & (n-1)) == 0, so n is a power of 2" << endl << endl;
    } else {
        cout << endl << "Summary: (n & (n-1)) != 0, so n is NOT a power of 2" << endl << endl;
    }

    
    return 0;
}
