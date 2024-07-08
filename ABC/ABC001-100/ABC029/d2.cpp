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
    string s;
    cin >> s;
    vvvll dp(s.size()+1,vvll(2,vll(10,0)));
    // dp[i][j][k] : i桁目までに1をk個含む数の個数 j==1のとき次の桁は何でもいい
    dp[0][0][0] = 1;
    rep(i,0,s.size()){
        // d:(i+1)桁目の数
        int d = s[i] - '0';
        rep(j,0,2){
            rep(k,0,10){
                rep(l,0,(j ? 10 : d+1)){
                    dp[i+1][j || (l < d)][k+(l == 1)] += dp[i][j][k];
                }
            }
        }
    }
    ll ans = 0;
    rep(i,1,10){
        ans += dp[s.size()][0][i]*i + dp[s.size()][1][i]*i;
    }
    cout << ans << endl;
}