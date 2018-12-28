/*
 
 https://www.codechef.com/JUNE18B/problems/SHKSTR
 
 */

#include <iostream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N;
    cin >> N;
    
    vector<string> A(N);
    for (int i=0; i<N; ++i){
        string word;
        cin >> word;
        A[i]=word;
    }
    int Q;
    cin >> Q;
    
    while (Q--){
        
        int R;
        string P;
        cin >> R >> P;
        
        auto beg=A.begin(),end=A.begin();
        for (int r=0; end!=A.end() && r<R; ++r,++end);
        set<string> ss(beg,end);
        
        while (!P.empty()){
            auto itr=ss.lower_bound(P);
            if (itr!=ss.end()){
                string str=*itr;
                if (str.find(P)!=string::npos){
                    cout << str << endl;
                    break;
                }
            }
            P.pop_back();
        }
    }
    
    
    return 0;
}

/*
 
4
abcd
abce
abcdex
abcde
1
3 abcde

 */

