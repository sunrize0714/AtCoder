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

ll dist(ll ax,ll ay, ll bx, ll by){
    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by); 
}

int main(){
    ll n;
    cin >> n;
    ll sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    vll x(n),y(n),r(n);
    rep(i,0,n)cin >> x[i] >> y[i] >> r[i];
    UnionFind UF;
    UF.init(n+3);
    rep(i,0,n){
        if(dist(x[i],y[i],sx,sy) == r[i]*r[i]){
            UF.unite(i,n);
        }

        if(dist(x[i],y[i],gx,gy) == r[i]*r[i]){
            UF.unite(i,n+1);
        }
    }

    rep(i,0,n-1){
        rep(j,i+1,n){
            ll dis = dist(x[i],y[i],x[j],y[j]);
            ll min = (r[i]-r[j])*(r[i]-r[j]);
            ll maxi = (r[i]+r[j])*(r[i]+r[j]);
            if(min <= dis && dis <= maxi){
                UF.unite(i,j);
            }
        }
    }

    if(UF.same(n,n+1))cout << "Yes" << endl;
    else cout << "No" << endl;
}