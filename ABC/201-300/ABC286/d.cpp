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

int main(){
    ll n,x;
    cin >> n >> x;
    vll a(n),b(n);
    rep(i,0,n)cin >> a[i] >> b[i];
    vll coin;
    rep(i,0,n){
        rep(j,1,b[i]+1){
            coin.push_back(a[i]);
        }
    }
    vector<vb> dp(coin.size()+1,vb(x+1,false));
    rep(i,0,coin.size()+1){
        dp[i][0] = true;
    } 

    rep(i,0,coin.size()){
        rep(j,0,coin[i]){
            dp[i+1][j] = dp[i][j];
        }
        rep(j,coin[i],x+1){
            if(dp[i][j-coin[i]] || dp[i][j])dp[i+1][j] = true;
        }
    }
    dp[coin.size()][x] ? cout << "Yes" << endl:cout << "No" << endl;
}