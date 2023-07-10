/*Math Library<ACL>*/
//a ÷ bをmodで割った余り(modは素数) - O(log(mod))
ll div_mod(ll a, ll b, ll mod) {return (a * pow_mod(b, mod - 2, mod)) % mod;}

//階乗 - O(n)
ll factorial(ll n, ll mod) {
    ll ans = 1;
    for(ll i = n; i >= 2; i--) ans = (ans * i) % mod;
    return ans;
}ll factorial(ll n) {return factorial(n, MOD);}

//順列 - O(r)
ll permutation(ll n, ll r, ll mod) {
    ll ans = 1;
    for(ll i = 0; i < r; i++) ans = (ans * (n - i)) % mod;
    return ans;
}ll permutation(ll n, ll r) {return permutation(n, r, MOD);}

//組み合わせ(modは素数) - O(min(r, n - r) + log(mod))
ll combination(ll n, ll r, ll mod) {
    r = min(r, n - r);
    if(r == 0) return 1;
    ll up = n;
    ll down = 1;
    for(int i = 1; i < r; i++) {
        up = (up * (n - i)) % mod;
        down = (down * (i + 1)) % mod;
    }
    return div_mod(up, down, mod);
}ll combination(ll n, ll r) {return combination(n, r, MOD);}

//nC0~nCrまでの列挙(modは素数) - O(rlog(mod))
vector<ll> getCombination_vec(ll n, ll r, ll mod) {
    vector<ll> ret(r + 1);
    ret[0] = 1;
    ll up = n;
    ll down = 1;
    ret[1] = div_mod(up, down, mod);
    for(int i = 1; i < r; i++) {
        up = (up * (n - i)) % mod;
        down = (down * (i + 1)) % mod;
        ret[i + 1] = div_mod(up, down, mod);
    }
    return ret;
}vector<ll> getCombination_vec(ll n, ll r) {return getCombination_vec(n, r, MOD);}

//素数判定 - O(√N)
bool is_prime(ll N) {
    if (N == 1) return false;
    for (ll i = 2; i * i <= N; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

//約数列挙 - O(√N)
vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            res.eb(i);
            if (N / i != i) res.eb(N / i);
        }
    }
    sort(all(res));
    return res;
}

//素因数分解 - O(√N)
vector<pair<ll, ll>> prime_factorize(ll N) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= N; a++) {
        if (N % a != 0) continue;
        ll ex = 0;
        while (N % a == 0) {
            ex++;
            N /= a;
        }
        res.eb(mp(a, ex));
    }
    if (N != 1) res.eb(mp(N, 1));
    return res;
}

//エラトステネスの篩 - O(NloglogN)
vector<bool> Eratosthenes(ll N) {
    vector<bool> isprime(N + 1, true);
    isprime[0] = isprime[1] = false;
    for (ll p = 2; p <= N; p++) {
        if (!isprime[p]) continue;
        for (ll q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }
    return isprime;
}

//N以下の素数を列挙 - O(NloglogN)
vector<ll> getPrimes(ll N) {
    vector<bool> era = Eratosthenes(N);
    vector<ll> primes;
    for(ll i = 2; i <= N; i++) {
        if(era[i]) primes.eb(i);
    }
    return primes;
}

//ユークリッド距離
ld calc_dist(ll x1, ll y1, ll x2, ll y2) {return sqrt(Epow(x2 - x1, 2) + Epow(y2 - y1, 2));}
ld calc_dist(pair<ll, ll> p1, pair<ll, ll> p2) {return sqrt(Epow(p2.fi - p1.fi, 2) + Epow(p2.se - p1.se, 2));}

//ユークリッド距離の2乗
ll calc_dist2(ll x1, ll y1, ll x2, ll y2) {return Epow(x2 - x1, 2) + Epow(y2 - y1, 2);}
ll calc_dist2(pair<ll, ll> p1, pair<ll, ll> p2) {return Epow(p2.fi - p1.fi, 2) + Epow(p2.se - p1.se, 2);}