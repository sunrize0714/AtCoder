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
    vll c(n-1),s(n-1),f(n-1);
    rep(i,0,n-1){
        cin >> c[i] >> s[i] >> f[i];
    }

    rep(i,0,n-1){
        ll ans = s[i];
        rep(j,i,n-1){
            if(ans < s[j]){
                ans = s[j];
            }
            if(ans % f[j] != 0){
                ans += f[j] - ans%f[j];
            }
            ans += c[j];
        }
        cout << ans << endl;
    }
    cout << 0 << endl;
}