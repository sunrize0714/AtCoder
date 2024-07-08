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
    vll w(n),x(n);
    rep(i,0,n)cin >> w[i] >> x[i];
    vll ans(60,0);
    rep(i,0,n){
        ans[(x[i]+9)] += w[i];
        ans[(x[i]+18)] -= w[i];
        if(x[i]+33 <= 48)ans[x[i]+33] += w[i];
        if(x[i]+42 <= 48)ans[x[i]+42] -= w[i];
    }
    ll a = ans[0];
    rep(i,1,49){
        ans[i] += ans[i-1];
        a = max(a,ans[i]);
    }
    cout << a;
}