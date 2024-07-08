#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
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
    ll n,k;
    cin >> n >> k;
    vll s(n);
    rep(i,0,n)cin >> s[i];
    rep(i,0,n){
        if(s[i] == 0){
            cout << n << endl;
            return 0;
        }
    }
    if(k == 0){
        cout << 0 << endl;
        return 0;
    }
    ll l = 0,r = 1;
    ll pos = 1;
    ll ans = 0;
    while(l <= n && r <= n){
        while(pos*s[r-1] <= k && r <= n){
            pos *= s[r-1];
            r++;
        }
        ans = max(ans,r-l-1);
        if(l != r-1)pos /= s[l];
        l++;
        if(r == l)r++;
    }
    cout << ans << endl;
}