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
    ll a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<vector<bool>> dp(3001,vb(3001,false));
    ll x = a*100,y = 0;
    double kosa = 0.0;
    dp[0][0] = true;
    rep(i,1,f+1){
        rep(j,0,i+1){
            if(100*a <= i){
                if(dp[i-100*a][j])dp[i][j] = true;
            }
            if(100*b <= i){
                if(dp[i-100*b][j])dp[i][j] = true;
            }
            if(i >= c && j >= c){
                if(dp[i-c][j-c])dp[i][j] = true;
            }
            if(i >= d && j >= d){
                if(dp[i-d][j-d])dp[i][j] = true;
            }
            if(dp[i][j]){
                if(j > 0 && 100*j <= (i-j)*e){
                    double tmp = 100.0*j/i;
                    if(kosa < tmp){
                        kosa = tmp;
                        x = i;
                        y = j;
                    }
                }
            }
        }
    }
    cout << x << " " << y;
}