#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll H,W,M;
    cin >> H >> W >> M;
    vll h(M),w(M);
    rep(i,0,M)cin >> h[i] >> w[i];
    vll hor(H+1),ver(W+1);
    ll tmp1 = 0,tmp2 = 0;
    rep(i,0,M){
        hor[h[i]]++;
        ver[w[i]]++;
        tmp1 = max(tmp1,hor[h[i]]);
        tmp2 = max(tmp2,ver[w[i]]);
    } 
    ll ans = tmp1 + tmp2 - 1;
    bool f = false;
    set<ll> x,y;
    rep(i,0,M){
        if(tmp1 == hor[h[i]])x.insert(h[i]);
        if(tmp2 == ver[w[i]])y.insert(w[i]);
    }
    ll cnt = 0;
    rep(i,0,M){
        if(x.count(h[i]) && y.count(w[i]))cnt++;
    }
    if(cnt != x.size()*y.size())f = true;
    cout << ans + f << endl;
}