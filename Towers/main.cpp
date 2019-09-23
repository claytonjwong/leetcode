#include <iostream>
#include <vector>

using namespace std;
using VI = vector<int>;

struct Tower {
    VI rod;
    string name;
    explicit Tower(const string& name_) : name{name_} {}
};

string whitespace(int i) {
    string res;
    fill_n(back_inserter(res), 2*i, ' ');
    return res;
}

void go(int N, Tower& src, Tower& dst, Tower& aux, int i=0) {
    if (N == 0)
        return;
    cout << whitespace(i) << "go(" << N << ", " << src.name << ", " << dst.name  << ", " << aux.name << ")" << endl;
    go(N-1, src, aux, dst, i+1);
    cout << whitespace(i+1) << src.name << " --(" << N << ")--> " << dst.name << endl;
    dst.rod.push_back(src.rod.back()), src.rod.pop_back();
    go(N-1, aux, dst, src, i+1);
}

int main() {
    Tower src{"src"}, dst{"dst"}, aux{"aux"};
    const auto N = 3;
    generate_n(back_inserter(src.rod), N, [i=N]() mutable { return i--; });
    go(N, src, dst, aux);
    return 0;
}