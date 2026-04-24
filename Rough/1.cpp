//----------------------------------String Algo-------------------------------------//

vector<ll>z_f(string s){//Z[i] = length of longest substring starting at i that matches prefix
    int n=s.size();
    vector<ll>z(n);
    ll l=0,r=0;
    for(ll i=1;i<n;i++){
        if(i<r){
            z[i]=min(r-i,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}

vector<ll>prefix_f(string s){
    //pi[i] is the length of the longest proper prefix of the substring s[0..i] which is also a suffix of this substring.
    ll n=s.size();
    vector<ll>pi(n);
    for(ll i=1;i<n;i++){
        ll j=pi[i-1];
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}

string min_cycle(string s){
    s+=s;
    ll n=s.size();
    ll low=0,ans=0;
    while(low<n/2){
        ans=low;
        ll high=low+1,k=low;
        while(high<n && s[k]<=s[high]){
            if(s[k]<s[high]) k=low;
            else k++;
            high++;
        }
        while(low<=k) low+=high-k;
    }
    return s.substr(ans,n/2);
}

string maxpalin(string s){//Manacher’s Algorithm
    string t="#";
    for(char c:s){
        t+=c;
        t+="#";
    }
    ll n=t.size();
    vector<ll>p(n);
    ll low=0,high=0;
    ll mx=0,inx=0;
    for(ll i=0;i<n;i++){
        if (i<high) p[i]=min(high-i,p[low+high-i]);
        // kholvanu
        while(i-p[i]-1>=0 && i+p[i]+1<n && t[i-p[i]-1]==t[i+p[i]+1]){ p[i]++;}
        // update
        if(i+p[i]>high){
            low=i-p[i];
            high=i+p[i];
        }
        // track answer
        if(p[i]>mx){
            mx=p[i],inx=i;
        }
    }
    ll dia=(inx-mx)/2;
    return s.substr(dia,mx);
}

struct Hashing{
    string s; int n;
    ll p1=331,m1=999999937;
    ll p2=379,m2=1e9 + 87;
    vll p_pow1,p_pow2,h1,h2,inv_pow1,inv_pow2;
    Hashing(const string& str) : s(str){
        n=s.length(); p_pow1.resize(n); p_pow2.resize(n);
        h1.resize(n+1);
        h2.resize(n+1);
        inv_pow1.resize(n);
        inv_pow2.resize(n);
        p_pow1[0]=1; p_pow2[0]=1; inv_pow1[0]=1; inv_pow2[0]=1;
        ll inv_p1=modinv(p1,m1); ll inv_p2=modinv(p2,m2);
        for(int i=1;i<n;i++){
            p_pow1[i]=(p_pow1[i-1]*p1) % m1; p_pow2[i]=(p_pow2[i-1]*p2)%m2;
            inv_pow1[i]=(inv_pow1[i-1]*inv_p1) % m1; inv_pow2[i]=(inv_pow2[i-1]*inv_p2)%m2;
        }
        for(int i=0;i<n;i++){
            h1[i+1]=(h1[i]+(s[i] - 'a' +1)*p_pow1[i])%m1;
            h2[i+1]=(h2[i]+(s[i] - 'a' +1)*p_pow2[i])%m2;
        }
    }
    pll get_hash(int l,int r){
        ll res1=(h1[r+1]-h1[l]+m1)%m1; ll res2=(h2[r+1]-h2[l]+m2)%m2;
        res1=(res1*inv_pow1[l])%m1; res2=(res2*inv_pow2[l])%m2;
        return make_pair(res1,res2);
    }
};
    // set hash ((a+k)^h +(b+k)^h + (c+k)^h )%m 
    // k is large upto 10^9 and  60<h<small

//----------------------------------------------------------------------------------//