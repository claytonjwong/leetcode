/*
 
 https://www.codechef.com/JUNE18B/problems/NAICHEF
 
 */

#include <iostream>
#include <iomanip>
#include <unordered_map>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int T;
    cin >> T;
    while (T--){
        int N,A,B;
        cin >> N >> A >> B;
        unordered_map<int,int> m{{A,0},{B,0}};
        for (int i=0; i<N; ++i){
            int x;
            cin >> x;
            ++m[x];
        }
        double pa=m[A]/double(N),pb=m[B]/double(N),ans=pa*pb;
        cout << fixed << setprecision(10) << ans << endl;
    }
    
    return 0;
}
/*
2
5 1 1
1 1 1 1 1
2 1 1
1 2
*/

/*
1.0000000000
0.2500000000

1.0000000000
0.2500000000

 */
