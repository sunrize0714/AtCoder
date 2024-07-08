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
    ll n;
    cin >> n;
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    vll x(n),y(n),r(n);
    rep(i,0,n)cin >> x[i] >> y[i] >> r[i];
    UnionFind UF;
    UF.init(n+2);
    rep(i,0,n){
        if(distance(sx,sy,x[i],y[i]) == r[i]*r[i])UF.unite(i,n);
        if(distance(tx,ty,x[i],y[i]) == r[i]*r[i])UF.unite(i,n+1);
    }
    rep(i,0,n){
        rep(j,i+1,n){
            ll d = distance(x[i],y[i],x[j],y[j]);
            if(d >= distance(r[i],0,r[j],0) && d <= (r[i]+r[j])*(r[i]+r[j]))UF.unite(i,j);
        }
    }
    if(UF.same(n,n+1))cout << "Yes";
    else cout << "No";

}
