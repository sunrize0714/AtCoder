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
    ll n;
    cin >> n;
    ll ans = 0;
    ll pos = 10;
    rep(i,0,19){
        ll l = pos / 10;
        if(l <= min(n,pos-1)){
            ll add = min(n,pos-1)-l+1;
            add %= mod;
            add *= add+1;
            add %= mod;
            add *= modinv(2,mod);
            add %= mod;
            ans += add;
        }
        pos *= 10;
    }
    cout << ans << endl;
}