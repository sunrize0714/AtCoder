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
    ll d,g;
    cin >> d >> g;
    g /= 100;
    vll p(d+1),c(d+1);
    rep(i,1,d+1)cin >> p[i] >> c[i];
    vvll dp(d+1,vll(110000,1e10));
    dp[0][0] = 0;
    rep(i,1,d+1){
        rep(j,0,110000){
            dp[i][j] = min(dp[i][j],dp[i-1][j]);
        }
        vll a(p[i]);
        rep(j,0,p[i])a[j] = i*(j+1);
        a[p[i]-1] += c[i]/100;

        rep(j,0,p[i]){
            rep(k,a[j],110000){
                dp[i][k] = min(dp[i][k],dp[i-1][k-a[j]]+j+1);
            }
        }
    }
    ll ans = 1e10;
    rep(i,g,110000)ans = min(ans,dp[d][i]);
    cout << ans << endl;
}