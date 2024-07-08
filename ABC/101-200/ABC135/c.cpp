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
    vll a(n+1),b(n);
    rep(i,0,n+1)cin >> a[i];
    rep(i,0,n)cin >> b[i];
    ll ans = 0;
    revrep(i,0,n){
        if(a[i+1] > 0 && b[i] > 0){
            ll pos = min(a[i+1],b[i]);
            ans += pos;
            a[i+1] -= pos;
            b[i] -= pos;
        }
        if(a[i] > 0 && b[i] > 0){
            ll pos2 = min(a[i],b[i]);
            ans += pos2;
            a[i] -= pos2;
            b[i] -= pos2;
        }
    }
    cout << ans << endl;
}