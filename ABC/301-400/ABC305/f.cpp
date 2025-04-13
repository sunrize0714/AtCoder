#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using mint = static_modint<998244353>;

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

vll visited(101,0);
void dfs(vll &visited,ll pos,ll pre,ll n){
    if(pos == n){
        exit(0);
    }
    ll k;
    cin >> k;
    if(k == -1){
        exit(0);
    }
    vll v(k);
    rep(i,0,k)cin >> v[i];

    visited[pos] = 1;

    rep(i,0,k){
        if(visited[v[i]] == 0){
            cout << v[i] << endl;
            dfs(visited,v[i],pos,n);
            ll kk;
            cin >> kk;
            ll x;
            rep(i,0,kk)cin >> x;
        }
    }
    cout << pre << endl;
    
}

int main(){
    ll n,m;
    cin >> n >> m;
    dfs(visited,1,1,n);
    return 0;
}
