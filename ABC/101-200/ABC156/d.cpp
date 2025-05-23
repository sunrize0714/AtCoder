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
    ll n,a,b;
    cin >> n >> a >> b;
    // ans = 2^n - 1 - nCa - nCb
    ll ans = 1;
    ll cnt = 4;
    if(n%2==1)ans = 2;
    ll m = 1000000007;
    rep(i,1,32){
        if(n & (1 << i)){
            ans *= cnt;
            ans %= m;
        }
        cnt *= cnt;
        cnt %= m;
    }
    cnt = 1;
    rep(i,1,a+1){
        cnt *= n-i+1;
        cnt %= m;
        cnt *= modinv(i,m);
        cnt %= m;
    }
    ans -= cnt;
    ans += m;
    ans %= m;
    rep(i,a+1,b+1){
        cnt *= n-i+1;
        cnt %= m;
        cnt *= modinv(i,m);
        cnt %= m;
    }
    ans -= cnt + 1;
    ans += m;
    ans %= m;
    cout << ans << endl;
}