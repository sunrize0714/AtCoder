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
    vll a(n),b(n);
    rep(i,0,n)cin >> a[i] >> b[i];
    vll dp(1LL<<n,-1);
    dp[0] = 0;
    rep(i,1,1LL<<n){
        bool ok = false;
        rep(j,0,n){
            rep(k,j+1,n){
                if((1LL << j)& i && (1LL << k) & 1){
                    if((a[j] == a[k] || b[j] == b[k]) == dp[i ^ (1LL << j) ^ (1LL << k)] == 0){
                        ok = true;
                    }
                }
            }
        }
        if(ok)dp[i] = 1;
        else dp[i] = 0;
    }
    if(dp[0] == 1)cout << "Aoki";
    else cout << "Takahashi";
}