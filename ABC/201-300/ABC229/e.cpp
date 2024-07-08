#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
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

class UnionFind{
    public:
    // parent , size 
    ll par[500009],siz[500009];
    
    // make unionfind tree, 0-indexed
    void init(ll N){
        for(ll i=0;i<N;i++){
            par[i] = -1;
            siz[i] = 1;
        }
    }

    // return root of x
    ll root(ll x){
        while(true){
            if(par[x] == -1)break;
            x = par[x];
        }
        return x;
    }

    // unite v and u, update tree and size
    void unite(ll u,ll v){
        ll RootU = root(u), RootV = root(v);
        if(RootU == RootV)return;
        if(siz[RootU] < siz[RootV]){
            par[RootU] = RootV;
            siz[RootV] += siz[RootU];
        }
        else{
            par[RootV] = RootU;
            siz[RootU] += siz[RootV];
        }
    }

    bool same(ll u,ll v){
        if(root(u) == root(v))return true;
        return false;
    }  
    
    ll size(ll x){
        ll pos = root(x);
        return siz[pos];
    }

};


int main(){
    UnionFind UF;
    ll n,m;
    cin >> n >> m;
    vll a(m),b(m);
    rep(i,0,m){
        cin >> a[i] >> b[i];
    }
    vvll g(n);
    rep(i,0,m){
        a[i]--,b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    ll cnt = 0;
    vll ans;
    ans.push_back(0);
    UF.init(n);
    revrep(i,0,n){
        cnt++;
        rep(j,0,g[i].size()){
            if(g[i][j] > i && !UF.same(i,g[i][j])){
                UF.unite(i,g[i][j]);
                cnt--;
            }
        }
        ans.push_back(cnt);
    }
    reverse(all(ans));
    rep(i,0,n)cout << ans[i] << endl;
}