#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
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
    ll n,m;
    cin >> n >> m;
    vll k(m),c(m);
    vvll a(m);
    UnionFind UF;
    UF.init(n);
    rep(i,0,m){
        cin >> k[i] >> c[i];
        rep(j,0,k[i]){
            ll pos;
            cin >> pos;
            a[i].push_back(pos);
        }
        rep(j,0,k[i]-1){
            UF.unite(a[i][j],a[i][k[i]-1]);
        }
    }
    if(UF.size(0) != n){
        cout << -1 << endl;
        return 0;
    }
    UF.init(n);
    vp x;
    rep(i,0,m)x.push_back(make_pair(c[i],i));
    sort(all(x));
    ll ans = 0;
    rep(i,0,m){
        ll pos = x[i].second;
        ll cost = x[i].first;
        rep(j,0,k[pos]-1){
            if(UF.same(a[pos][j],a[pos][k[pos]-1]) == false){
                ans += cost;
                UF.unite(a[pos][j],a[pos][k[pos]-1]);
            }
        }
    }
    cout << ans << endl;
}