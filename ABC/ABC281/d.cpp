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
#define rrep(i,a,n) for(ll i=n-1;i>=a;i--)
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

int main(){
    ll n,k,d;
    cin >> n >> k >> d;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vvvll dp(n+1,vvll(k+1,vll(d,-1)));
    dp[0][0][0] = 0;
    rep(i,0,n){
        rep(j,0,k+1){
            rep(l,0,d){
                if(dp[i][j][l] == -1)continue;
                dp[i+1][j][l] = max(dp[i+1][j][l],dp[i][j][l]);
                if(j!=k)dp[i+1][j+1][(l+a[i])%d] = max(dp[i+1][j+1][(l+a[i])%d],dp[i][j][l] + a[i]);
            }
        }
    }
    cout << dp[n][k][0];
}