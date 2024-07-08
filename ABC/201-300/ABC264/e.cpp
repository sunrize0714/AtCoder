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
    long long int par[300009],siz[300009];
    
    // make unionfind tree
    void init(long long int N){
        for(long long int i=0;i<N;i++){
            par[i] = -1;
            siz[i] = 1;
        }
    }

    // return root of x
    long long int root(long long int x){
        while(true){
            if(par[x] == -1)break;
            x = par[x];
        }
        return x;
    }

    // unite v and u, update tree and size
    void unite(long long int u,long long int v){
        long long int RootU = root(u), RootV = root(v);
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

    bool same(long long int u,long long int v){
        if(root(u) == root(v))return true;
        return false;
    }  

    long long int size(long long int u){
        long long int x = root(u);
        return siz[x];
    }
};

int main(){
    UnionFind UF;
    ll n,m,e;
    cin >> n >> m >> e;
    vll u(e),v(e);
    rep(i,0,e){
        cin >> u[i] >> v[i];
        u[i]--,v[i]--;
    }
    ll q;
    cin >> q;
    vll x(q);
    vll event(q);
    rep(i,0,q){
        cin >> x[i];
        x[i]--;
        event[i] = x[i];
    }

    vll ans;
    UF.init(n+m+1);
    sort(event.begin(),event.end());
    set<ll> t;
    rep(i,0,q)t.insert(event[i]);
    rep(i,0,e){
        if(t.count(i) == 1)continue;
        UF.unite(min(u[i],n),min(v[i],n));
    }

    ans.push_back(UF.size(n)-1);
    revrep(i,0,q){
        ll pos = x[i];
        UF.unite(min(u[pos],n),min(v[pos],n));
        if(i!=0)ans.push_back(UF.size(n)-1);
    }
    reverse(ans.begin(),ans.end());
    rep(i,0,ans.size()){
        cout << ans[i] << endl;
    }
}