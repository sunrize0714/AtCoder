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
#define all(a) a.begin(),a.end()
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
    ll n;
    cin >> n;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    ll ans = 2e18;
    vvll dp(n+1,vll(2,1e18));
    dp[0][0] = 0;
    rep(i,0,n-1){
        dp[i+1][0] = dp[i][1];
        dp[i+1][1] = min(dp[i][0],dp[i][1]) + a[i+1];
    }
    ans = min(ans,dp[n-1][1]);
    rep(i,0,n+1)rep(j,0,2)dp[i][j] = 1e18;
    dp[0][1] = a[0];
    rep(i,0,n-1){
        dp[i+1][0] = dp[i][1];
        dp[i+1][1] = min(dp[i][0],dp[i][1]) + a[i+1];
    }
    ans = min({ans,dp[n-1][0],dp[n-1][1]});
    cout << ans << endl;
}