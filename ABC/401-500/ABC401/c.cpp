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

bool in_field(ll l,ll r,ll x){
    if(l <= x && x < r)return true;
    else return false;
}

ll distance(ll ax,ll ay,ll bx, ll by){
    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

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
    ll n,k;
    cin >> n >> k;

    if(n < k){
        cout << 1;
        return 0;
    }
    vll dp(n+2,0),wa(n+2,0);
    rep(i,0,k)dp[i] = 1;
    rep(i,0,k)wa[i+1] = wa[i]+dp[i];
    rep(i,k,n+1){
        dp[i] = wa[i] - wa[i-k];
        if(dp[i] < 0)dp[i] += 1e9;
        dp[i] %= 1000000000;
        wa[i+1] = wa[i] + dp[i];
        wa[i+1] %= 1000000000;
    } 
    cout << dp[n];
}
