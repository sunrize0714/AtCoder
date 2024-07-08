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
    ll n;
    cin >> n;
    vll a(n+2,0);
    rep(i,1,n+1)cin >> a[i];
    ll ans = 0;
    rep(i,0,n+1){
        ans += abs(a[i+1]-a[i]);
    }
    rep(i,0,n){
        ll cnt = ans;
        if((a[i+1]-a[i])*(a[i+2]-a[i+1]) < 0){
            cnt -= abs(a[i+1]-a[i]) + abs(a[i+2]-a[i+1]) - abs(a[i+2]-a[i]);
        }
        cout << cnt << endl;
    }
}