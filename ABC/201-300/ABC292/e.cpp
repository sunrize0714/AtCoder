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
    vll u(m),v(m);
    rep(i,0,m)cin >> u[i] >> v[i];
    vvll g(n);
    rep(i,0,m){
        u[i]--,v[i]--;
        g[u[i]].push_back(v[i]);
    }
    ll ans = 0;
    rep(i,0,n){
        vll ok(n,false);
        ok[i] = true;
        queue<ll> q;
        rep(j,0,g[i].size()){
            q.push(g[i][j]);
            ok[g[i][j]] = true;
        }
        ll cnt = 0;
        while(!q.empty()){
            ll pos = q.front();q.pop();
            cnt++;
            rep(j,0,g[pos].size()){
                ll to = g[pos][j];
                if(!ok[to]){
                    q.push(to);
                    ok[to] = true;
                }
            }
        }
        ans += cnt;
    }
    ans -= m;
    cout << ans << endl;
}