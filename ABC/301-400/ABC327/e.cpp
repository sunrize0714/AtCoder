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

int main(){
    ll n;
    cin >> n;
    vector<double> p(n);
    rep(i,0,n)cin >> p[i];
    reverse(all(p));
    vector<vector<double>> tab(n,vector<double>(n,0.0));
    rep(i,0,n){
        double pos = 1.0;
        rep(j,0,i+1){
            tab[i][j] = p[i]*pos;
            pos *= 0.9;
        }
    }
    vector<vector<double>> dp(n+1,vector<double>(n+1,0.0));
    rep(i,0,n){
        rep(j,0,i+1){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j] + tab[i][j]); 
        }
    }
    double ans = -1e18;
    double base = 1.0;
    double x = 0.9;
    rep(i,1,n+1){
        double l = double(i);
        double y = 1200.0/sqrt(l);
        rep(j,1,n+1){
            double score = (double)dp[j][i]/base;
            ans = max(ans,score-y);
        }
        base += x;
        x*=0.9;
    }
    cout << setprecision(10) << ans;
}