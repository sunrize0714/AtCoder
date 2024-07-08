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
    ll x,y;
    cin >> x >> y;
    ll m = 1000000007;
    if(x*2 < y || x > y*2){
        cout << 0 << endl;
        return 0;
    }
    if(x > y)swap(x,y);
    if((x+y)%3 != 0){
        cout << 0 << endl;
        return 0;
    }
    ll cnt = (x+y)/3;
    ll ans = 1;
    rep(i,1,cnt+1){
        ans *= i;
        ans %= m;
    }
    ll sa = abs(x-y);
    cnt -= sa;
    cnt /= 2;
    rep(i,1,cnt+1){
        ans *= modinv(i,m);
        ans %= m;
    }
    rep(i,1,cnt+sa+1){
        ans *= modinv(i,m);
        ans %= m;
    }
    cout << ans << endl;
}