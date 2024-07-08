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
    UnionFind UF;
    UF.init(n);
    vll a(m),b(m),c(m);
    rep(i,0,m)cin >> a[i] >> b[i] >> c[i];
    vp p;
    rep(i,0,m){
        a[i]--,b[i]--;
        ll pos = a[i]*1000000 + b[i];
        p.push_back(make_pair(c[i],pos));
    }
    sort(all(p));
    ll ans = 0;
    rep(i,0,m){
        ll x = p[i].second/1000000, y = p[i].second%1000000;
        if(UF.same(x,y) == false){
            UF.unite(x,y);
        }
        else ans += max(p[i].first,0LL);
    }
    cout << ans << endl;
}