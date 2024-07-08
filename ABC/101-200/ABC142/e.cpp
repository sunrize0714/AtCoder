#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll modinv(ll a, ll m) {
    ll b=m,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=m; 
    if(u<0)u+=m;
    return u;
}
 
ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n,m;
    cin >> n >> m;
    vll a(m),b(m);
    vll open(m,0);
    rep(i,0,m){
        cin >> a[i] >> b[i];
        rep(j,0,b[i]){
            ll x;
            cin >> x;
            x--;
            open[i] |= (1 << x);
        }
    }
    

    vvll dp(m+1,vll(1<<n,1e18));
    dp[0][0] = 0;
    rep(i,0,m){
        rep(j,0,1<<n){
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            dp[i+1][j|open[i]] = min(dp[i+1][j|open[i]],dp[i][j]+a[i]);
        }
    }

    if(dp[m][(1<<n)-1] == 1e18)dp[m][(1<<n)-1] = -1;
    cout << dp[m][(1<<n)-1];
}