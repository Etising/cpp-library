#include <bits/stdc++.h>
using namespace std;

//ex: 6(10)->011(2)
vector<int> d_to(long long x, int hex) {
    vector<int> ret;
    long long cur = x;
    while(cur != 0) {
        ret.emplace_back(cur % hex);
        cur /= hex;
    }
    return ret;
}

//小さい順に配列を用意すること
long long to_d(const vector<int> &x, int hex) {
    long long ret = 0;
    long long cur = 1;
    for(int i = 0; i < x.size(); i++) {
        ret += cur * x[i];
        cur *= hex;
    }
    return ret;
}