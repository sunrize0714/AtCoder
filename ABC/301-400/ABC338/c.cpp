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

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n;
    cin >> n;
    vll q(n),a(n),b(n);
    rep(i,0,n)cin >> q[i];
    rep(i,0,n)cin >> a[i];
    rep(i,0,n)cin >> b[i];
    ll ans = 0;
    rep(i,0,1000009){
        vll cnt(n);
        rep(j,0,n){
            cnt[j] = q[j] - i*a[j];
        }
        bool ok = true;
        ll maxi = 1e10;
        rep(j,0,n){
            if(cnt[j] < 0)ok = false;
            if(b[j]==0)continue;
            maxi = min(maxi,(cnt[j]/b[j]));
        }
        if(ok)ans = max(ans,i+maxi);
        else break;
    }
    cout << ans << endl;
}