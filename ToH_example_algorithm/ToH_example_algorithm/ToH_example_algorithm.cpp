#include <vector>

using namespace std;
using VI=vector<int>;

void go(int N, VI& src, VI& dst, VI& aux){
    if (N==0) return;
    go(N-1,src,aux,dst);
    dst.push_back(src.back());
    src.pop_back();
    go(N-1,aux,dst,src);
}

void go2(int N, VI& S, VI& D, VI& A){
    if (N==0) return; else go2(N-1,S,A,D),D.push_back(S.back()),S.pop_back(),go2(N-1,A,D,S);
}

#include <iostream>
int main(){
    int N; cout << "N: ";
    while (cin>>N && N>0){
        VI src(N),dst,aux;
        for (int i=0,j=N; i<N; ++i,--j)
            src[i]=j;
        
        assert((int)src.size()==N && is_sorted(src.rbegin(),src.rend())); // src with N disks in descending order
        go(N,src,dst,aux);
        assert((int)dst.size()==N && is_sorted(dst.rbegin(),dst.rend())); // dst with N disks in descending order
        
        src.swap(dst); // start over again
        
        assert((int)src.size()==N && is_sorted(src.rbegin(),src.rend())); // src with N disks in descending order
        go2(N,src,dst,aux);
        assert((int)dst.size()==N && is_sorted(dst.rbegin(),dst.rend())); // dst with N disks in descending order
        
        cout << "N: ";
    }
}
