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


class UnionFind{
    public:
    // parent , size 
    ll par[200009],siz[200009];
    
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
    bool f = true;
    vll divi(n,0);
    rep(i,0,m){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        divi[a]++,divi[b]++;
        if(UF.same(a,b))f = false;
        UF.unite(a,b);
    }
    rep(i,1,n){
        if(!UF.same(0,i))f = false;
    }
    ll two = n-2,one = 2;
    rep(i,0,n){
        if(divi[i] == 1)one--;
        else if(divi[i] == 2)two--;
    }
    if(one != 0 || two != 0)f = false;
    if(f)cout << "Yes" << endl;
    else cout << "No" << endl;    
}