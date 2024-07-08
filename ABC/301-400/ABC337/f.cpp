#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
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

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vll c(n);
    rep(i,0,n)cin >> c[i];
    vll a(n);
    rep(i,0,n)a[i] = c[i];
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    vvll g(a.size());
    
    rep(i,0,n){
        ll x = lower_bound(all(a),c[i]) - a.begin();
        g[x].push_back(i);
    }
    rep(i,0,n){
        ll x = lower_bound(all(a),c[i]) - a.begin();
        g[x].push_back(i);
    }
    vll start(a.size(),0);

    rep(i,0,n){
        if(i != 1){
            ll x = lower_bound(all(a),c[i]) - a.begin();
            start[x]++;
        }
        
    }
}