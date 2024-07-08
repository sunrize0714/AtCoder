#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
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

int main(){
    ll n,x;
    cin >> n >> x;
    vll t(n);
    rep(i,0,n)cin >> t[i];
    ll one = t[0],ans=0;

    vll dp(x+1,0);
    dp[0] = 1;
    rep(i,0,x){
        rep(j,0,n){
            if(i+t[j] <= x){
                dp[i+t[j]] += dp[i]%mod;
                dp[i+t[j]]*=modinv(n,mod);
                dp[i+t[j]] %= mod;
            }
            if(one+i > x)ans += dp[i]*modinv(n,mod);
            ans %= mod;
        }
    }
    cout << ans;
    
}