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

static ll par[1000009],siz[1000009];
class UnionFind{
    public:
    // parent , size 
    //ll par[1000009],siz[1000009];
    
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
    ll h,w;
    cin >> h >> w;
    vs s(h);
    rep(i,0,h)cin >> s[i];
    UnionFind UF;
    UF.init(h*w);

    rep(i,0,h)rep(j,0,w){
        if(s[i][j] != '#')continue;
        rep(k,0,4){
            ll x = i+dx4[k],y = j + dy4[k];
            if(x < 0 || x >= h || y < 0 || y >= w)continue;
            if(s[x][y] == '.')s[x][y] = 'x'; 
        }
    }


    rep(i,0,h)rep(j,1,w){
        if(s[i][j] == s[i][j-1] && s[i][j] == '.')UF.unite(i*w+j,i*w+j-1);
    }
    rep(i,1,h)rep(j,0,w){
        if(s[i][j] == s[i-1][j] && s[i-1][j] == '.')UF.unite(i*w+j,i*w+j-w);
    }
    vll ans(h*w,0);
    rep(i,0,h)rep(j,0,w){
        if(s[i][j] == 'x')ans[i*w+j]=1;
        if(UF.root(i*w+j) == i*w+j)ans[i*w+j] = UF.size(i*w+j);
    }
    rep(i,0,h)rep(j,0,w){
        if(s[i][j] != 'x')continue;
        set<ll> st;
        rep(k,0,4){
        ll x = i+dx4[k],y = j + dy4[k];
        if(x < 0 || x >= h || y < 0 || y >= w)continue;
        if(s[x][y] == '.'){
            if(st.count(UF.root(x*w+y)))continue;
            st.insert(UF.root(x*w+y));
            ans[UF.root(x*w+y)]++;
        }
        }
    }
    ll cnt = 0;
    rep(i,0,h)rep(j,0,w)cnt = max(cnt,ans[i*w+j]);
    cout << cnt << endl;
}