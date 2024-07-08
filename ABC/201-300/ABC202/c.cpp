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
    vll a(n),b(n),c(n);
    rep(i,0,n)cin >> a[i];
    rep(i,0,n)cin >> b[i];
    rep(i,0,n)cin >> c[i];
    map<ll,ll> m1,m2;
    rep(i,0,n)m1[a[i]]++;
    rep(i,0,n)m2[b[c[i]-1]]++;
    ll ans = 0;
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    rep(i,0,a.size())ans += m1[a[i]]*m2[a[i]];
    cout << ans << endl;
}