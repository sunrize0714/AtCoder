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
    ll par[100009],siz[100009];
    
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
    ll n,m,k;
    cin >> n >> m >> k;
    vll u(m),v(m),w(m);
    rep(i,0,m)cin >> u[i] >> v[i] >> w[i];
    ll ans = k;
    vll array;
    rep(i,0,n-1){
        array.push_back(1);
    }
    rep(i,0,m-n+1){
        array.push_back(0);
    }
    sort(array.begin(),array.end());
    do{
        ll cnt = 0;
        UF.init(n+1);
        rep(i,0,array.size()){
            if(array[i] == 1){
                if(UF.same(u[i],v[i])){
                    cnt = k;
                    break;
                }
                UF.unite(u[i],v[i]);
                cnt += w[i];
            }
        }
        if(cnt != k)cnt %= k;
        ans = min(ans,cnt);
    }while(next_permutation(array.begin(),array.end()));
    cout << ans << endl;
}