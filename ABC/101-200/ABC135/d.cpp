#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
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
    ll m = 1000000007;
    string s;
    cin >> s;
    //dp[i][k][l] i桁目,13で割った余りがk,i桁目がl
    // のときの数の個数
    vvvll dp(s.size()+1,vvll(13,vll(10,0)));
    dp[0][0][0] = 1;
    rep(i,0,s.size()){
        rep(j,0,13){
            if(s[i] == '?'){
                rep(k,0,10){
                    rep(l,0,10){
                        dp[i+1][(j*10+k)%13][k] += dp[i][j][l];
                        dp[i+1][(j*10+k)%13][k] %= m;
                    }
                }
            }
            else{
                rep(k,0,10){
                    rep(l,0,10){
                    if(s[i]-'0' == k){
                        dp[i+1][(10*j+k)%13][k] += dp[i][j][l];
                        dp[i+1][(j*10+k)%13][k] %= m;
                    }
                    }
                }
            }
        }
        
    }
    ll ans = 0;
    rep(i,0,10){
        ans += dp[s.size()][5][i];
        ans %= m;
    }
    cout << ans << endl;
}