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
    ll n;
    cin >> n;
    vll a(n),b(n);
    rep(i,0,n)cin >> a[i] >> b[i];
    vvll dp(n+1,vll(2,0));
    dp[1][0] = 1,dp[1][1] = 1;
    rep(i,1,n){
        if(a[i] != a[i-1])dp[i+1][0] += dp[i][0];
        if(a[i] != b[i-1])dp[i+1][0] += dp[i][1];
        if(b[i] != a[i-1])dp[i+1][1] += dp[i][0];
        if(b[i] != b[i-1])dp[i+1][1] += dp[i][1];
        dp[i+1][0] %= mod;
        dp[i+1][1] %= mod;
    }
    cout << (dp[n][0] + dp[n][1])% mod << endl;
}