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

int main(){
    ll n;
    cin >> n;
    vvll dp(n+1,vll(n+1,0));
    vll two(7000,1);
    two[1] = 2;
    rep(i,2,n+1){
        two[i] = two[i-1] * 2;
        two[i] %= mod; 
    }
    rep(i,1,n+1){
        rep(j,1,i+1){
            dp[i][j] = two[i+j-1];
            dp[i][j] += two[i]-1;
            dp[i][j] %= mod;
            dp[i][j] *= modinv(two[i+j-1],mod);
            dp[i][j] %= mod;
        }
    }
    rep(i,1,n+1){
        ll ans = 1;
        
    }
}