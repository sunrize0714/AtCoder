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
    string n;
    cin >> n;
    // dp[i][j][k][l] i桁目まで,桁和j,総桁和とのmodがkであるような数の個数
    ll ans = 0;
    rep(cnt,1,150){
        vvvvll dp(n.size()+1,vvvll(cnt+1,vvll(cnt,vll(2,0LL))));
        dp[0][0][0][1] = 1;
        rep(i,0,n.size()){
            rep(j,0,cnt+1){
                rep(k,0,cnt){
                    rep(l,0,2){
                        rep(t,0,10){
                            if(j+t > cnt)continue;
                            if(l == 1 && n[i]-'0' < t)continue;

                            dp[i+1][j+t][(k*10+t)%cnt][l == 1 & n[i]-'0' == t] += dp[i][j][k][l];
                        }
                    }
                }
            }
        }
        ans += dp[n.size()][cnt][0][0] + dp[n.size()][cnt][0][1];
    }
    cout << ans << endl;
}