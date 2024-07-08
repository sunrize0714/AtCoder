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
    string t;
    cin >> t;
    ll n;
    cin >> n;
    vll a(n);
    vector<vector<string>> s(n);
    rep(i,0,n){
        cin >> a[i];
        rep(j,0,a[i]){
            string x;
            cin >> x;
            s[i].push_back(x);
        }
    }
    vvll dp(n+1,vll(t.size()+1,1e15));
    dp[0][0] = 0;
    rep(i,0,n){
        rep(j,0,t.size()+1){
            dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
            rep(k,0,a[i]){
                ll z = s[i][k].size();
                if(j+z <= t.size()){
                    if(s[i][k] == t.substr(j,z)){
                        dp[i+1][j+z] = min(dp[i][j]+1,dp[i+1][j+z]);
                    }
                }
            }
        }
    }
    ll ans = 1e15;
    rep(i,0,n+1){
        ans = min(ans,dp[i][t.size()]);
    }
    if(ans == 1e15)ans = -1;
    cout << ans;
}