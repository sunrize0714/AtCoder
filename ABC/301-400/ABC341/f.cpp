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

int main(){
    ll n,m;
    cin >> n >> m;
    vll u(m),v(m);
    vll w(n),a(n);
    rep(i,0,m)cin >> u[i] >> v[i];
    rep(i,0,n)cin >> w[i];
    rep(i,0,n)cin >> a[i];
    vvll g(n);
    vll in(n,0);
    rep(i,0,m){
        u[i]--,v[i]--;
        if(w[u[i]] < w[v[i]]){
            g[u[i]].push_back(v[i]);
            in[v[i]]++;
        }
        else if(w[u[i]] > w[v[i]]){
            g[v[i]].push_back(u[i]);
            in[u[i]]++;
        }
    }
    vll turn(n,0);
    queue<ll> q;
    rep(i,0,n){
        if(in[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        ll pos = q.front();q.pop();
        turn[pos] += 1;
        vll use(g[pos].size(),0);
        vvll dp(g[pos].size()+1,vll(w[pos]+1,-1e10));
        dp[0][0] = 0;
        rep(j,0,g[pos].size()){
            rep(k,w[pos],w[pos]-w[g[pos][j]])dp[j+1][k] = max(dp[j][k],dp[j][k-w[pos]]);
            rep(k,0,w[pos])dp[j+1][k] = dp[j][k];
        }
        ll ans = 0;
        rep(j,0,w[pos])ans = max(ans,dp[g[pos].size()][j]);
        revrep(i,0,g[pos].size()){
            if(dp[i] != dp)
        }
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            turn[to] += turn[pos];
            in[to]--;
            if(in[to] == 0){
                q.push(to);
            }
        }
    }
    ll ans = 0;
    rep(i,0,n)ans += a[i]*turn[i];
    cout << ans << endl;
}