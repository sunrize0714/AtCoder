#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

bool in_field(ll l,ll r,ll x){
    if(l <= x && x < r)return true;
    else return false;
}

ll distance(ll ax,ll ay,ll bx, ll by){
    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

ll modinv(ll a, ll m) {
    ll b=m,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=m; 
    if(u<0)u+=m;
    return u;
}

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

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

int main(){
    ll h,w;
    cin >> h >> w;
    vs c(h);
    rep(i,0,h)cin >> c[i];
    UnionFind UF;
    UF.init(w*h);
    rep(i,0,h){
        rep(j,1,w){
            if(c[i][j-1] == c[i][j] && c[i][j] == '.')UF.unite(i*w+j,i*w+j-1);
        }
    }
    rep(i,1,h){
        rep(j,0,w){
            if(c[i-1][j] == c[i][j] && c[i][j] == '.')UF.unite(i*w+j-w,i*w+j);
        }
    }
    ll x,y;
    rep(i,0,h)rep(j,0,w)if(c[i][j] == 'S')x = i,y = j;
    vll p;
    rep(cnt,0,4){
        if(in_field(0,h,x+dx4[cnt]) && in_field(0,w,y+dy4[cnt])){
            if(c[x+dx4[cnt]][y+dy4[cnt]] == '.')p.push_back({(x+dx4[cnt])*w+y+dy4[cnt]});
        }
    }
    rep(i,0,p.size()){
        rep(j,i+1,p.size()){
            if(UF.same(p[i],p[j])){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}
