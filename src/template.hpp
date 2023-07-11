#pragma GCC target("avx")
//#pragma GCC target("avx2")
#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

//local debug
#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

//AtCoder Library
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using mint = atcoder::modint998244353;
using Mint = atcoder::modint1000000007;
#endif

//alias
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

//constants
constexpr const long long MOD = 998244353;
constexpr const long long MODM = 1000000007;
constexpr const int INF = 1e9;
constexpr const ll LINF = 1e18;
constexpr const ld PI = 3.1415926535;

//rep(for-loop) macro
#define overload4(a, b, c, d, e, ...) e
#define rep2(i, n) for(ll i = 0; i < n; i++)
#define rep3(i, k, n) for(ll i = k; i < n; i++)
#define rep4(i, k, n, a) for(ll i = k; i < n; i += a)
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep1_2(i, n) for(ll i = 1; i <= n; i++)
#define rep1_3(i, k, n) for(ll i = k; i <= n; i++)
#define rep1_4(i, k, n, a) for(ll i = k; i <= n; i += a)
#define rep1(...) overload4(__VA_ARGS__, rep1_4, rep1_3, rep1_2)(__VA_ARGS__)
#define Rep2(i, n) for(ll i = n - 1; i >= 0; i--)
#define Rep3(i, k, n) for(ll i = n - 1; i >= k; i--)
#define Rep4(i, k, n, a) for(ll i = n - 1; i >= k; i -= a) 
#define Rep(...) overload4(__VA_ARGS__, Rep4, Rep3, Rep2)(__VA_ARGS__)
#define Rep1_2(i, n) for(ll i = n; i >= 1; i--)
#define Rep1_3(i, k, n) for(ll i = n; i >= k; i--)
#define Rep1_4(i, k, n, a) for(ll i = n; i >= k; i -= a) 
#define Rep1(...) overload4(__VA_ARGS__, Rep1_4, Rep1_3, Rep1_2)(__VA_ARGS__)
#define vfor(v, x) for(auto x : v)
#define mfor(map) for(auto &[key, value] : map)

//vector macro
#define vvecc(T, name, n, m) vector<vector<T>> name(n, vector<T>(m))
#define vvec(T, name, n) vector<vector<T>> name(n)
#define vvecs(T, name, n, m, s) vector<vector<T>> name(n, vector<T>(m, s))
#define vvvecc(T, name, n, m, h) vector<vector<vector<T>>> name(n, vector<vector<T>>(m, vector<T>(h)))
#define vvvecs(T, name, n, m, h, s) vector<vector<vector<T>>> name(n, vector<vector<T>>(m, vector<T>(h, s)))
#define LB(v, x) distance((v).begin(), lower_bound(all(v), (x)))
#define UB(v, x) distance((v).begin(), upper_bound(all(v), (x)))
#define MIN(v) *min_element(all(v))
#define MINI(v) distance(v.begin(), min_element(all(v)))
#define MAX(v) *max_element(all(v))
#define MAXI(v) distance(v.begin(), max_element(all(v)))
#define Sort(v) sort(all(v))
#define Rev(v) reverse(all(v))
template<class T> inline bool vsame(const vector<T> &a, const vector<T> &b) {return (a.size() == b.size() && equal(all(a), b.begin()));}
template<class T> inline ll vsum(const vector<T> &v) {ll sum = 0; for(T x : v) sum += x; return sum;}

//iterator macro
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define rng(v, l, r) begin(v) + (l), begin(a) + (r)

//data structure macro
#define ef emplace_front
#define eb emplace_back
#define pf pop_front
#define pb pop_back
#define mp make_pair
#define fi first
#define se second
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
template<class T> using pq = priority_queue<T>;
template<class T> using pqmin = priority_queue<T, vector<T>, greater<T>>;
template<class T, class U> using pqp = priority_queue<pair<T, U>>;
template<class T, class U> using pqpmin = priority_queue<pair<T, U>, vector<pair<T, U>>, greater<pair<T,U>>>;

//output
#define pl() cout << '\n'
template<class T> inline void print(const T& a) {cout << a;}
inline void printl() {}
template<class T> inline void printl(const T& t) {print(t); pl();}
template<class T> inline void printf(const T& t) {print(t); pl(); cout << flush;}
template<class Head, class... Tail> inline void printl(const Head& head, const Tail&... tail) {print(head); cout << " "; printl(tail...);}
template<class Head, class... Tail> inline void printf(const Head& head, const Tail&... tail) {print(head); cout << " "; printl(tail...); cout << flush;}
template<class T> inline void printl(const vector<T>& v) {if(v.size() == 0) return; print(v[0]); for(auto i = v.begin(); ++i != v.end();) {cout << " "; print(*i);}}
template<class T> inline void printl1(const vector<T>& v) {if(v.size() <= 1) return; print(v[1]); for(auto i = v.begin() + 1; ++i != v.end();) {cout << " "; print(*i);}}
template<class T> inline void prints(const T& a) {cout << a << " ";}
template<class T> inline void fin(const T& t) {printl(t); exit(0);}
inline void Yes(bool a) {cout << (a ? "Yes" : "No") << '\n';}
template<class T, class U> inline void Out2(bool a, T yes, U no) {if(a) printl(yes); else printl(no);}

//functions
inline int ctoi(char c) {return c - '0';}
inline char to_char(int x) {return x + '0';}
inline bool bw(ll a, ll x, ll b) {return (a < x && x < b);}
inline bool bwe(ll a, ll x, ll b) {return (a <= x && x <= b);}
template<class... T> inline constexpr auto Emin(T... a) {return min(initializer_list<common_type_t<T...>>{a...});}
template<class... T> inline constexpr auto Emax(T... a) {return max(initializer_list<common_type_t<T...>>{a...});}
template<class T, class U> inline bool chmax(T &a, const U &b) {if (a < b) { a = b; return true;} return false;}
template<class T, class U> inline bool chmin(T &a, const U &b) {if (a > b) { a = b; return true;} return false;}
template<class T, class U> inline ll Epow(T x, U y) {ll ans = 1; for(int i = 0; i < y; i++) ans *= x; return ans;}
template<class T, class U> inline ll Eceil(T x, U y) {return (ll)ceil((ld)x / (ld)y);}
template<class T, class U> inline ll Efloor(T x, U y) {return (ll)floor((ld)x / (ld)y);}
template<class T, class U> inline bool check_bit(T tar, U bit) {return ((tar & Epow(2, bit)) != 0);}
template<class T> inline bool overflow_if_add(T a, T b) {return (std::numeric_limits<T>::max() - a) < b;}
template<class T> inline bool overflow_if_mul(T a, T b) {return (std::numeric_limits<T>::max() / a) < b;}

//pair-sort
template<class T, class U> inline bool pud(pair<T, U>& left, pair<T, U>& right) {
    if (left.first == right.first) return right.second < left.second;
    else return left.first  < right.first;
}
template<class T, class U> inline bool pdu(pair<T, U>& left, pair<T, U>& right) {
    if (left.first == right.first) return left.second < right.second;
    else return right.first < left.first;
}

namespace cincout {
    void Etising() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
}

struct exec_time {
    private:
        std::chrono::system_clock::time_point start, end;
    public:
        exec_time() : start(std::chrono::system_clock::now()) {}
        ll get_time() {
            end = std::chrono::system_clock::now();
            ll ret = (ll)std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            return ret;
        }
};

void cordp(vector<ll> &A) {
    vector<ll> sorted;
    map<ll, vector<int>> idx;
    rep(i, A.size()) {
        sorted.eb(A[i]);
        idx[A[i]].eb(i);
    }
    Sort(sorted);
    sorted.erase(unique(all(sorted)), sorted.end());
    rep(i, sorted.size()) vfor(idx[sorted[i]], x) A[x] = i;
}