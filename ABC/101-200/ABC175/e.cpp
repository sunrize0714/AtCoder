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
    ll R,C,k;
    cin >> R >> C >> k;
    vll r(k),c(k),v(k);
    rep(i,0,k)cin >> r[i] >> c[i] >> v[i];
    vll st((R+1)*(C+1),0);
    rep(i,0,k){
        st[r[i]*C+c[i]-C] = v[i];
    }
    vvvll dp(R+1,vvll(C+1,vll(4,-1e18)));
    dp[1][1][0] = 0;
    rep(i,1,R+1){
        rep(j,1,C+1){
            ll add = st[i*C+j-C];
            rep(l,0,4){
                dp[i][j][0] = max(dp[i-1][j][l],dp[i][j][0]);
                dp[i][j][l] = max(dp[i][j][l],dp[i][j-1][l]);
            }
            revrep(l,1,4){
                dp[i][j][l] = max(dp[i][j][l],dp[i][j][l-1]+add);
            }
        }
    }
    ll ans = -1e18;
    rep(i,0,4)ans = max(ans,dp[R][C][i]);
    cout << ans;
}