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

int main(){
    ll n,m;
    cin >> n >> m;
    vll x(m),y(m);
    rep(i,0,m)cin >> x[i] >> y[i];
    vvll g(n,vll(n,0));
    rep(i,0,m){
        x[i]--,y[i]--;
        g[x[i]][y[i]] = 1;
        g[y[i]][x[i]] = 1;
    }
    ll ans = 1;
    rep(i,0,(1<<n)){
        bool ok = true;
        vll c;
        rep(j,0,n+1){
            if(i & (1 << j))c.push_back(j);
        }
        if(c.size() > 1){
            rep(j,0,c.size()){
                rep(k,0,c.size()){
                    if(c[j] == c[k])continue;
                    if(g[c[j]][c[k]] == 0)ok = false;
                }
            }
        }
        ll x = c.size();
        if(ok)ans = max(ans,x);
    }
    cout << ans << endl;
}