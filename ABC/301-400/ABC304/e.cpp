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
    vll par,siz;
    
    // make unionfind tree, 0-indexed
    void init(ll N){
        par.resize(N,-1);
        siz.resize(N,1);
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

ll distance(ll ax,ll ay,ll bx, ll by){
    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

int main(){
    ll n,m;
    cin >> n >> m;
    UnionFind UF;
    UF.init(n);
    vll u(m),v(m);
    rep(i,0,m){
        cin >> u[i] >> v[i];
        UF.unite(u[i]-1,v[i]-1);
    }
    ll k;
    cin >> k;
    vll x(k),y(k);
    set<pair<ll,ll>> s;
    rep(i,0,k){
        cin >> x[i] >> y[i];
        x[i]--,y[i]--;
        ll xx = UF.root(x[i]),yy = UF.root(y[i]);
        if(xx > yy)swap(xx,yy);
        s.insert({xx,yy});
    }
    ll Q;
    cin >> Q;
    rep(i,0,Q){
        ll p,q;
        cin >> p >> q;
        p--,q--;
        ll pp = UF.root(p),qq = UF.root(q);
        if(pp > qq)swap(pp,qq);
        if(s.count({pp,qq}) == 1)cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}