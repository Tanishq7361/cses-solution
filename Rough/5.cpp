#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--)
    {string m;
    cin >> m;
    const char c[3] = {'r','g','b'};
    if (m == "first") {
        int T; cin >> T;
        while (T--) {
            int n,e; cin >> n >> e;
            vector<vector<int>> g(n+1);
            for (int i=0;i<e;++i){int a,b;cin>>a>>b;g[a].push_back(b);g[b].push_back(a);}
            vector<int> d(n+1,-1);
            queue<int> q;
            d[1]=0; q.push(1);
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int v:g[u]) if(d[v]==-1){d[v]=d[u]+1; q.push(v);}
            }
            string s; s.resize(n);
            for (int i=1;i<=n;++i){
                int msk = ((d[i]%3)+3)%3;
                s[i-1]=c[msk];
            }
            cout << s << '\n';
        }
    } else if (m == "second") {
        int T; cin >> T;
        while (T--) {
            int Q; cin >> Q;
            while (Q--) {
                int D; cin >> D;
                string S; cin >> S;
                bool p[3] = {0,0,0};
                auto id = [&](char ch)->int{ if(ch=='r') return 0; if(ch=='g') return 1; return 2; };
                for (char ch : S) p[id(ch)] = true;
                int cnt = p[0] + p[1] + p[2];
                char tgt = 'r';
                if (cnt == 1) {
                    for (int i=0;i<3;++i) if (p[i]) { tgt = c[i]; break; }
                } else {
                    int miss = -1;
                    for (int i=0;i<3;++i) if (!p[i]) miss = i;
                    int closer = (miss + 2) % 3;
                    tgt = c[closer];
                }
                int ans = 1;
                for (int i=0;i<D;++i) if (S[i]==tgt){ ans = i+1; break; }
                cout << ans << '\n';
            }
        }
    }}
    return 0;
}
