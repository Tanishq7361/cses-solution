// created: 22.07.2025

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
///////////////////////////////////////////////////////////////////////////////////////////////
template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// .find_by_order(k)  returns iterator to kth element starting from 0;
// .order_of_key(k) returns count of elements strictly smaller than k;

template<class T> istream& operator >> (istream &is, vector<T>& V) {
    for(auto &e : V)
        is >> e;
    return is;
}
template<typename CharT, typename Traits, typename T>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, T const &val) {
    return (out << val << " ");
}
template<typename CharT, typename Traits, typename T1, typename T2>
ostream& _containerprint(std::basic_ostream<CharT, Traits> &out, pair<T1, T2> const &val) {
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename CharT, typename Traits, template<typename, typename...> class TT, typename... Args>
ostream& operator << (std::basic_ostream<CharT, Traits> &out, TT<Args...> const &cont) {
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");
}
template<class L, class R> ostream& operator << (ostream& out, pair<L, R> const &val){
    return (out << "(" << val.first << "," << val.second << ") ");
}
template<typename L, size_t N> ostream& operator << (ostream& out, array<L, N> const &cont){
    out << "[ ";
    for(auto&& elem : cont) _containerprint(out, elem);
    return (out << "]");    
}
template<class T> ostream& operator<<(ostream &out, ordered_set<T> const& S){
    out << "{ ";
    for(const auto& s:S) out << s << " ";
    return (out << "}");
}
template<class L, class R, class chash = std::hash<L> > ostream& operator << (ostream &out, gp_hash_table<L, R, chash> const& M) {
    out << "{ ";
    for(const auto& m: M) out << "(" << m.first << ":" << m.second << ") ";
    return (out << "}");
}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){
    static priority_queue<P, Q, R> U;
    U = M;
    out << "{ ";
    while(!U.empty())
        out << U.top() << " ", U.pop();
    return (out << "}");
}
#define TRACE
#ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " : " << arg1<<" | ";
        __f(comma+1, args...);
    }
#else
    #define trace(...) 1
#endif
struct custom_hash { 
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    template<typename L, typename R>
    size_t operator()(pair<L,R> const& Y) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
    }
};
///////////////////////////////////////////////////////////////////////////////////////////////
const long long  MOD = 1e9 + 7;
const long long  MOD1 = 998244353;

#define endl '\n'
#define ll long long
#define stc static_cast
#define vll vector<ll>
#define pll pair<ll, ll>
#define pb push_back
#define ppb pop_back
#define bitcount __builtin_popcountll
#define ff first
#define ss second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define one cout << "1\n"
#define mone cout << "-1\n"
#define zro cout << "0\n"
#define ent cout << endl
#define done return
#define fr(i, l, r) for (ll i = (l); i < (r); i++)
#define frr(i, r, l) for (ll i = (r - 1); i >= l; i--)
#define sz(x) ll((x).size()) 
#define all(x) (x).begin(), (x).end()
#define srt(x) sort((x).begin(), (x).end())
#define rsrt(x) sort((x).rbegin(), (x).rend())
#define rev(x) reverse(x.begin(), x.end())
#define maxval(v) *max_element((v).begin(), (v).end())
#define minval(v) *min_element((v).begin(), (v).end())
#define maxid(v) max_element((v).begin(), (v).end()) - ((v).begin())
#define minid(v) min_element((v).begin(), (v).end()) - ((v).begin())

// rotate(v.begin(),v.begin()+v.size()-r,v.end()); for rotating vector r times right
// rotate(v.begin(),v.begin()+r,v.end()); for rotating vector r times left
// Use "set_name".max_load_factor(0.25);"set_name".reserve(512); with unordered set
// Or use gp_hash_table<X,null_type>

void solve()
{
    
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //cout << fixed << setprecision(25);
    cerr << fixed << setprecision(10);
    auto start = std::chrono::high_resolution_clock::now();
    ll tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time Taken: " << ((long double)duration.count())/((long double) 1e9) << " sec.\n";
    return 0;
}

