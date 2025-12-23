// Jay Swaminarayan
// TM //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define vll vector<ll>
#define endl "\n"
#define countsetbits __builtin_popcountll
const ll MOD = 1000000007;

      struct custom_hash { //to avoid TLE due to collision in unordered_map and unordered_set;
   static inline const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        return splitmix64(x + FIXED_RANDOM);
    }
    template <typename T1, typename T2>
    size_t operator()(const std::pair<T1, T2>& p) const {
        size_t h1 = operator()(static_cast<uint64_t>(p.first));
        size_t h2 = operator()(static_cast<uint64_t>(p.second));
        return h1 ^ (h2 << 1);
    }
};
vector<bool> sieve(ll N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}
bool isPowerOf2(ll x) { return x > 0 && (x & (x - 1)) == 0; }
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }
bool isPrime(ll n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
ll nCr(ll n, ll r) {
    ll ans = 1;
    for (ll i = 0; i < r; i++) {
        ans = ans * (n - i) / (i + 1);
    }
    return ans;
}
ll mod_pow(ll base, ll exp, ll m = MOD) {
    ll res = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return res;
}
ll powoftwo(ll n) { return 1LL << n; }
bool isbitSet(ll n, ll p) { return (n >> p) & 1; }
ll setbit(ll n, ll p) { return n | (1LL << p); }
ll clearbit(ll n, ll p) { return n & ~(1LL << p); }
ll togglebit(ll n, ll p) { return n ^ (1LL << p); }
ll totalbits(ll n) { ll c = 0; while (n) { n >>= 1; c++; } return c; }
ll msb(ll n) { return totalbits(n) - 1; }
ll lsb(ll n) { return n & -n; }
ll computeXOR(ll n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}
ll rangeXOR(ll l, ll r) {
return computeXOR(r) ^ computeXOR(l - 1);
}

string decimalToBinary(ll num) {
    if (num == 0) return "0";
    string res;
    while (num > 0) {
        res.push_back('0' + (num & 1));
        num >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

ll binaryToDecimal(const string& s) {
    ll res = 0;
    for (char c : s) res = (res << 1) + (c - '0');
    return res;
}

ll firstOneFromLeft(ll n) {
    return n == 0 ? -1 : 63 - __builtin_clzll(n);
}

// -------- Added Utility Functions --------
vector<ll> all_divisors(ll n) {
    vector<ll> divs;
    if (n <= 0) return divs;
    ll root = floor(sqrt((long double)n));
    for (ll i = 1; i <= root; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            ll j = n / i;
            if (j != i) divs.push_back(j);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

vll divisors_of_number(ll n) {
    vll ans;
    ll t = sqrt(n);
    for (ll i = 2; i <= t; ++i) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i) ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

void prime_factorization(ll n, map<ll, ll>& factors) {
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        factors[n]++;
    }
}
const int N = 1e6;  
vector<int> divisors[N + 1];
void precomputeDivisors() {
for (int i = 1; i <= N; i++) {
  for (int j = i; j <= N; j += i) {
      divisors[j].push_back(i);
    }
  }
}
// -----------------------------------------

void solve() 
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    ll mini=LLONG_MAX;
    for(ll i=0;i<n;i++)
    {
        mini=min(mini,v[i]);
    }
    ll temp=LLONG_MAX;
    for(ll i=0;i<n;i++)
    {
        if(v[i]>mini)
        {
            temp=min(temp,v[i]-mini);
        }
    }
    if(temp==LLONG_MAX)
    {
        temp=0;
    }
    cout<<max(temp,mini)<<endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    //t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}