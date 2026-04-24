#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull long long int
#define MOD 1000000007
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define all(vec) (vec.begin(), vec.end())
#define sz(x) (int)x.size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 4;
const ll INF = 1LL << 60;

//template <typename T = ll> using pair = pair<T, T>;

namespace generator {

    // Generate a random integer
    ll gen_int(ll Lower_Limit = -100000, ll Upper_Limit = 100000, ll Bias = 0) {
        return rnd.wnext(Lower_Limit, Upper_Limit, Bias);
    }

    // Generate a random character
    char gen_char(bool Upper_Case = false, bool Digit = false, char Lower_Limit = 'a', char Upper_Limit = 'z') {
        if (Upper_Case) return 'A' + gen_int(Lower_Limit - 'A', Upper_Limit - 'A');

        if (Digit) return '0' + gen_int(Lower_Limit - '0', Upper_Limit - '0');

        return 'a' + gen_int(Lower_Limit - 'a', Upper_Limit - 'a');
    }

    // Generate a random string with both upper and lower case characters
    string gen_string(int Length = 0, char Lower_Limit = 'a', char Upper_Limit = 'z') {
        assert(Length >= 0 && Length <= 5e6);

        string str(Length, 'A');

        for (auto &ch : str) {
            bool is_upper = gen_int(0,1); // 0 - Lower Case : 1 - Upper Case

            if (is_upper) ch = 'A' + gen_int(Lower_Limit - 'a', Upper_Limit - 'a');
            else ch = 'a' + gen_int(Lower_Limit - 'a', Upper_Limit - 'a');
        }

        return str;
    }

    // Generate a Digit String;
    string gen_digit_string(int Length = 0, bool allowLeadingZero = false) {
        assert(Length >= 0 && Length <= 5e6);
        if (Length == 0) return "";

        string str(Length, '0');
        for (int i = 0; i < Length; i++) {
            if (i == 0 && !allowLeadingZero) {
                str[i] = '1' + gen_int(0, 8); // ensures first digit ∈ [1..9]
            } else {
                str[i] = '0' + gen_int(0, 9); // [0..9]
            }
        }
        return str;
    }

    // Generate a palindrome string
    string gen_palindrome(int Length = 0, bool Upper_Case = false, char Lower_Limit = 'a', char Upper_Limit = 'z') {
        assert(Length >= 0 && Length <= 5e6);

        string str(Length, (Upper_Case ? 'A' : 'a'));

        for (int Left = 0, Right = Length - 1; Left <= Right; Left++, Right--)
            str[Left] = str[Right] = str[Left] + gen_int(Lower_Limit - (Upper_Case ? 'A' : 'a'), Upper_Limit - (Upper_Case ? 'A' : 'a'));
        return str;
    }

    // Generate an array of integers
    vector<ll> gen_array(int Length = 0, ll Lower_Limit = 1, ll Upper_Limit = INF, bool Increasing = false, bool Decreasing = false) {
        assert(Length >= 0 and Length <= 5e6);

        vector<ll> vec(Length);
        ll Delta = max(Upper_Limit / Length, 1ll);

        for (auto &x : vec) x = gen_int(Lower_Limit, Upper_Limit);

        if (Increasing) {
            for (int i = 0; i < Length; i++)
                vec[i] = (i == 0 ? 0 : vec[i - 1]) + Delta;
        }

        if (Decreasing) {
            for (int i = Length - 1; i >= 0; i--)
                vec[i] = (i == Length - 1 ? 0 : vec[i + 1]) + Delta;
        }

        return vec;
    }

    // Generate a unique array of integers
    vector<ll> gen_unique_array(int Length = 0, ll Lower_Limit = -INF, ll Upper_Limit = INF, ll Bias = 0, bool Increasing = false, bool Decreasing = false) {
        assert(Length >= 0 and Length <= 5e6);

        vector<ll> vec;
        set<ll> st;

        while ( st.size() != Length) st.insert(gen_int(Lower_Limit, Upper_Limit, Bias));

        for (auto &i : st) vec.push_back(i);

        if (Increasing) return vec;

        if (Decreasing) {
            reverse(vec.begin(), vec.end());
            return vec;
        }

        shuffle(vec.begin(), vec.end());
        return vec;
    }

    // Generate a 2D array of integers
    vector<vector<ll>> gen_array_2D(int Row = 0, int Col = 0, ll Lower_Limit = -INF, ll Upper_Limit = INF) {
        assert(Row >= 0 and Row <= 5e6 && Col >= 0 && Col <= 5e6 && Row * Col <= 1e8);

        vector<vector<ll>> vec(Row);

        for (int i = 0; i < Row; i++) vec[i] = gen_array(Col, Lower_Limit, Upper_Limit);

        return vec;
    }

    // Generate a random permutation
    vector<ll> gen_permutation(int Length = 0) {
        assert(Length >= 0 && Length <= 5e6);

        vector<ll> vec(Length);
        iota(vec.begin(), vec.end(), 1);
        shuffle(vec.begin(), vec.end());

        return vec;
    }

    // Generate a big integer string
    string gen_big_int(int Length = 0, char Lower_Limit = '0', char Upper_Limit = '9') {
        assert(Length >= 0 && Length <= 5e6);

        string str(Length, '0');

        for (char &ch : str) ch += gen_int(Lower_Limit - '0', Upper_Limit - '0');

        if (str.front() == '0') str.front() += gen_int(Lower_Limit - '0' + 1, Upper_Limit - '0');

        return str;
    }

    // Generate an array of pairs
    // vector<pair<ll,ll>> gen_array_of_pairs(int Length = 0, ll Lower_Limit = -INF, ll Upper_Limit = INF, bool Interval = false) {
    //     assert(Length >= 0 and Length <= 5e6);

    //     vector<pair<ll,ll>> vec(Length);

    //     for (auto &[a, b] : vec) a = gen_int(Lower_Limit, Upper_Limit), b = gen_int((Interval ? a : Lower_Limit), Upper_Limit);

    //     return vec;
    // }

    // Generate a tree structure
    vector<pair<ll,ll>> gen_tree(ll Nodes = 0) {
        assert(Nodes >= 0);

        vector<pair<ll,ll>> res(Nodes ? Nodes - 1 : 0);
        vector<ll> permutation(Nodes + 1);

        iota(permutation.begin() + 1, permutation.begin() + Nodes + 1, 0);
        shuffle(permutation.begin() + 1, permutation.begin() + Nodes + 1);

        for (int i = 2; i <= Nodes; ++i) {
            ll u = i, v = gen_int(1, i - 1);
            u = permutation[u], v = permutation[v];
            res[i - 2] = minmax(u, v); // u < v
        }

        shuffle(res.begin(), res.end());
        return res;
    }

    // Generate a simple graph
    vector<pair<ll,ll>> gen_simple_graph(ll Nodes = 0, ll Edges = 0) {
        assert(Nodes > 0 && Edges >= Nodes);

        ll Max_Edges = Nodes * (Nodes - 1) / 2;
        assert(Edges <= Max_Edges);

        vector<pair<ll,ll>> res = gen_tree(Nodes);
        set<pair<ll,ll>> edge(res.begin(), res.end());

        for (int i = Nodes; i <= Edges; ++i) {
            while (true) {
                ll u = gen_int(1, Nodes), v = gen_int(1, Nodes);
                if (u == v) continue;
                auto it = edge.insert(minmax(u, v));
                if (it.second) break;
            }
        }

        res.assign(edge.begin(), edge.end());
        return res;
    }

}

using namespace generator;

//Overloaded output operator for vector of pairs
// template <typename T = int> ostream &operator<<(ostream &other, const vector< pair<T,T> > &v) {
//     for (const auto &x : v)
//         other << x.first << ' ' << x.second << '\n';
//     return other;
// }

// Function to make the name of the text file
string made_txt(int t) {
    string Test_Case = "Tests/test";
    Test_Case += to_string(t);
    Test_Case += ".txt";
    return Test_Case;
}

// Use the generator in Codeforces Polygon
/*
    <#list begin..end as s>
        Name_of_Generator_file ${s} > $
    </#list>
*/

/*

==-> This code has been modified By HarMit :) 

==-> In case of any modification, kindly check in above Functions
    
gen_int(Lower_Limit, Upper_Limit, Bias) ---> ll
gen_char(Upper_Case, Digit) ---> char   
gen_string(Length) ---> string
gen_palindrome(Length, Upper_Case) ---> string
gen_array(Length,Lower_Limit, Upper_Limit, Increasing, Decreasing) ---> vector<ll>
gen_unique_array(Length, Lower_Limit, Upper_Limit, Bias, Increasing, Decreasing) ---> vector<ll>
gen_array_2D(Row, Col, Lower_Limit , Upper_Limit) ---> vector<vector<ll,ll>>
gen_permutation(Length) ---> vector<ll>
gen_big_int(Length) ---> string
gen_array_of_pairs(Length, Lower_Limit, Upper_Limit, Interval) ---> vector<pair<ll,ll>>
gen_tree(Number_Of_Nodes) ---> vector<pair<ll,ll>>
gen_simple_graph(Number_Of_Nodes, Number_Of_Edges) ---> vector<pair<ll,ll>>

*/

// Complete this function according to the requirements

void Generate_tests() {
    int tt = gen_int(1, 100);
    cout << tt << endl;

    while (tt--) {
        int n = gen_int(3, 200000);
        cout << n << endl;

        string s(n, 'a');
        for (int i = 0; i < n; i++) {
            s[i] = 'a' + gen_int(0, 25);
        }

        cout << s << endl;
    }
}


// Driver Code
int main(int argc, char* argv[]) {

    registerGen(argc, argv, 1);

    ios_base::sync_with_stdio(0);cin.tie(0);

    char a, b;
    char Test[12] = "Test_01.txt";
    char Result[14] = "Result_01.txt";
    
    int Test_Cnt = 1; // Number of Test Files

    for (int i = 1; i <= Test_Cnt; i++) {
        
        Test[6] = '0' + (i % 10);
        Test[5] = '0' + (i / 10);

        Result[8] = '0' + (i % 10);
        Result[7] = '0' + (i / 10);

        // freopen(Test, "w", stdout);

        Generate_tests();

        // cout << endl;
    }
}

