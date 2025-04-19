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
    ll n,x;
    cin >> n >> x;
    vll c(n);
    vector<double> s(n),p(n);
    rep(i,0,n)cin >> s[i] >> c[i] >> p[i];
    vector<vector<double>> dp(1LL << n,vector<double>(x+1,0.0));
    dp[0][0] = 1.0;
    rep(i,0,1LL<<n){
        rep(j,0,x+1){
            rep(k,0,n){
                if(j+c[k] > x)continue;
                if(i & (1LL << k))continue;
                dp[i][j+c[k]] = max(dp[i][j]*(100.0-p[k])/100.0,dp[i][j+c[k]]);
                dp[i|(1LL << k)][j+c[k]] += dp[i][j]*p[k]/100.0;
            }
        }
    }

    /*rep(i,0,1LL<<n){
        rep(j,1,x+1){
            cout << dp[i][j] << "   ";
        }
        cout << endl;
    }*/

    rep(i,0,1LL<<n){
        rep(j,1,x+1)if(dp[i][j-1] > dp[i][j])dp[i][j] = dp[i][j-1];
        double pos = 0;
        rep(j,0,n)if(i & (1LL<<j))pos += s[j];
        dp[i][x]*=pos;
    }
    rep(i,2,1LL<<n)if(dp[i-1][x] > dp[i][x])dp[i][x] = dp[i-1][x];
    cout << dp[1LL<<n-1][x];
}
