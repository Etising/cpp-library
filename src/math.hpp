#include <bits/stdc++.h>
using namespace std;

long long pow_mod(long long x, long long n, long long mod = 1e18) {
    long long ret = 1;
    while(n > 0) {
        if(n & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return ret;
}

//a ÷ bをmodで割った余り(modは素数) - O(log(mod))
long long div_mod(long long a, long long b, long long mod = 1e18) {return (a * pow_mod(b, mod - 2, mod)) % mod;}

//階乗 - O(n)
long long factorial(long long n, long long mod = 1e18) {
    long long ans = 1;
    for(long long i = n; i >= 2; i--) ans = (ans * i) % mod;
    return ans;
}

//順列 - O(r)
long long permutation(long long n, long long r, long long mod = 1e18) {
    long long ans = 1;
    for(long long i = 0; i < r; i++) ans = (ans * (n - i)) % mod;
    return ans;
}

//組み合わせ(modは素数) - O(min(r, n - r) + log(mod))
long long combination(long long n, long long r, long long mod = 1e18) {
    r = min(r, n - r);
    if(r == 0) return 1;
    long long up = n;
    long long down = 1;
    for(int i = 1; i < r; i++) {
        up = (up * (n - i)) % mod;
        down = (down * (i + 1)) % mod;
    }
    return div_mod(up, down, mod);
}

//nC0~nCrまでの列挙(modは素数) - O(rlog(mod))
vector<long long> getCombination_vec(long long n, long long r, long long mod = 1e18) {
    vector<long long> ret(r + 1);
    ret[0] = 1;
    long long up = n;
    long long down = 1;
    ret[1] = div_mod(up, down, mod);
    for(int i = 1; i < r; i++) {
        up = (up * (n - i)) % mod;
        down = (down * (i + 1)) % mod;
        ret[i + 1] = div_mod(up, down, mod);
    }
    return ret;
}

//素数判定 - O(√N)
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

//約数列挙 - O(√N)
vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            res.emplace_back(i);
            if (N / i != i) res.emplace_back(N / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

//素因数分解 - O(√N)
vector<pair<long long, long long>> prime_factorize(long long N) {
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; a++) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ex++;
            N /= a;
        }
        res.emplace_back(make_pair(a, ex));
    }
    if (N != 1) res.emplace_back(make_pair(N, 1));
    return res;
}

//エラトステネスの篩 - O(NloglogN)
vector<bool> Eratosthenes(long long N) {
    vector<bool> isprime(N + 1, true);
    isprime[0] = isprime[1] = false;
    for (long long p = 2; p <= N; p++) {
        if (!isprime[p]) continue;
        for (long long q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }
    return isprime;
}

//N以下の素数を列挙 - O(NloglogN)
vector<long long> getPrimes(long long N) {
    vector<bool> era = Eratosthenes(N);
    vector<long long> primes;
    for(long long i = 2; i <= N; i++) {
        if(era[i]) primes.emplace_back(i);
    }
    return primes;
}

//ユークリッド距離
long double calc_dist(long long x1, long long y1, long long x2, long long y2) {return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));}
long double calc_dist(pair<long long, long long> p1, pair<long long, long long> p2) {return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));}

//ユークリッド距離の2乗
long long calc_dist2(long long x1, long long y1, long long x2, long long y2) {return pow(x2 - x1, 2) + pow(y2 - y1, 2);}
long long calc_dist2(pair<long long, long long> p1, pair<long long, long long> p2) {return pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2);}