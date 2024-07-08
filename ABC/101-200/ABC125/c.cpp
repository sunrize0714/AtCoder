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
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll left_gcd(n),right_gcd(n);
    left_gcd[0] = a[0];
    rep(i,1,n){
        left_gcd[i] = gcd(left_gcd[i-1],a[i]);
    }
    right_gcd[n-1] = a[n-1];
    revrep(i,0,n-1){
        right_gcd[i] = gcd(right_gcd[i+1],a[i]);
    }
    ll ans = 0;
    rep(i,1,n-1){
        ll cnt = gcd(left_gcd[i-1],right_gcd[i+1]);
        ans = max(ans,cnt);
    }
    cout << max({ans,right_gcd[1],left_gcd[n-2]});
}