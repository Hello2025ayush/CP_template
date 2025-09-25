#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define ff first
#define ss second
#define endl '\n'
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define popc(x) __builtin_popcountll(x)
#define dbg(x) cerr << #x << " = " << x << endl;
#define debug(v) cerr << #v << " = ["; for(auto x : v) cerr << x << " "; cerr << "]\n";
#define debug_p(v) cerr << #v << " = ["; for (auto &p : v) cerr << "(" << p.first << "," << p.second << ") "; cerr << "]\n";
#define debug_vv(v) do { cerr << #v << " = {"; bool f = 1; for (auto &r : v) { cerr << (f ? "{" : "    {"); f = 0; for (size_t i = 0; i < r.size(); ++i) cerr << r[i] << (i+1 < r.size() ? ", " : ""); cerr << "}\n"; } cerr << "}\n"; } while(0)
const long long LLong_MAX = 9223372036854775807;
const ll mod = 1e9 + 7;
/*---------------------------------------------------------------------------------------------------------------------------*/
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll m) {return expo(a, m - 2, m);}   // m is prime
ll ceil_div(ll a, ll b) { return (a + b - 1) / b;}
ll combination(ll n, ll r, ll m, ll fact[], ll ifact[]) { return (((fact[n] * ifact[n - r]) % m) * ifact[r]) % m; }
bool isInteger(double lol) { return fabs(lol - round(lol)) < 1e-9; }
bool isPrime(ll n) { if (n < 2) return false; if (n == 2 || n == 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (ll i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
vector<ll> sieve(ll n) { ll*arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
vector<ll> divisor(ll n) { std::vector<ll> d; for (ll i = 1; i * i <= n; i++) if (n % i == 0) { d.push_back(i); if (i != n / i) d.push_back(n / i); } std::sort(d.begin(), d.end()); return d; }
/*---------------------------------------------------------------------------------------------------------------------------*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        
    }
}

