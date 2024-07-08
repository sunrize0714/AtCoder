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
    ll h,w;
    cin >> h >> w;
    vs a(h);
    rep(i,0,h){
        cin >> a[i];
    }
    vvll dp(h,vll(w,0));
    revrep(i,0,h){
        revrep(j,0,w){
            if((i+j)% 2 == 0)dp[i][j] = -1e10;
            else dp[i][j] = 1e10;
            if(i == h-1 && j == w-1)dp[i][j] = 0;
            if(i != h-1){
                if((i+j)%2 == 0){
                    dp[i][j] = max(dp[i+1][j]+(a[i+1][j] == '+' ? 1:-1),dp[i][j]);
                }
                else{
                    dp[i][j] = min(dp[i+1][j]-(a[i+1][j] == '+' ? 1:-1),dp[i][j]);
                }
            }
            if(j != w-1){
                if((i+j)%2 == 0){
                    dp[i][j] = max(dp[i][j+1]+(a[i][j+1] == '+' ? 1:-1),dp[i][j]);
                }
                else{
                    dp[i][j] = min(dp[i][j+1]-(a[i][j+1] == '+' ? 1:-1),dp[i][j]);
                }
            }
        }
    }
    /*rep(i,0,h){
        rep(j,0,w){
            cout << dp[i][j] << " ";
        }    
        cout << endl;
    }*/

    if(dp[0][0] == 0)cout << "Draw" << endl;
    else if(dp[0][0] > 0)cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
}