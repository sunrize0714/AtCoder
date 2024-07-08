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
    vll a(n);
    rep(i,0,n)cin >> a[i];
    map<ll,ll> m;
    rep(i,0,n)m[a[i]]++;
    ll ans = 0;
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    if(a.size() > 1){
        rep(i,0,a.size()-1){
            rep(j,i+1,a.size()){
                ll pos = abs(a[i]-a[j]);
                pos *= pos;
                ans += pos*m[a[i]]*m[a[j]];
            }
        }
    }
    cout << ans << endl;
}