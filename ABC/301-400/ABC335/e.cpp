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
    ll par[1000009],siz[1000009];
    
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
    UF.init(n);
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll u(m),v(m);
    rep(i,0,m)cin >> u[i] >> v[i];

    vvll g(n);
    vll in(n,0);
    rep(i,0,m){
        u[i]--,v[i]--;
        if(a[u[i]] > a[v[i]]){
            g[v[i]].push_back(u[i]);
        }
        else if(a[u[i]] < a[v[i]]){
            g[u[i]].push_back(v[i]);
        }
        else{
            UF.unite(u[i],v[i]);
            rep(j,0,g[v[i]].size()){
                g[u[i]].push_back(UF.root(g[v[i]][j]));
            }
            
            rep(j,0,g[u[i]].size()){
                g[v[i]].push_back(UF.root(g[u[i]][j]));
            }
            
        }
    }

    rep(i,0,n){
        if(UF.root(i) != i){
            g[i].clear();
            in[i] = -1;
        }
        else{
            sort(all(g[i]));
            g[i].erase(unique(all(g[i])),g[i].end());
            rep(j,0,g[i].size()){
                ll tm = UF.root(g[i][j]);
                in[tm]++;
            }
        }
    }
    vll dp(n,0);
    ll tmp = UF.root(0);
    dp[tmp] = 1;
    queue<ll> q;
    rep(i,0,n){
        if(in[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        ll pos = q.front();q.pop();
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            dp[to] = max(dp[to],dp[pos]+1);
            in[to]--;
            if(in[to] == 0)q.push(to);
        }
    }
    
    tmp = UF.root(n-1);
    if(dp[tmp] <= 0)cout << 0 << endl;
    else cout << dp[tmp] << endl;
}