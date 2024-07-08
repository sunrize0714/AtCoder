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
    ll N,C;
    cin >> N >> C;
    vll s(N),t(N),c(N);
    rep(i,0,N)cin >> s[i] >> t[i] >> c[i];

    vvvll ch(C+1,vvll(2));
    rep(i,0,N){
        ch[c[i]-1][0].push_back(s[i]);
        ch[c[i]-1][1].push_back(t[i]);
    }
    vvll dp(C,vll(110000,0));
    rep(i,0,C){
        sort(all(ch[i][0]));
        sort(all(ch[i][1]));
        if(ch[i][0].size() == 0)continue;
        ll now = ch[i][0][0];
        if(ch[i][0].size() > 1){
            rep(j,0,ch[i][0].size()-1){
                if(ch[i][1][j] != ch[i][0][j+1]){
                    ll a = ch[i][1][j];
                    dp[i][now-1]++;
                    dp[i][a]--;
                    now = ch[i][0][j+1];
                }
            }
        }
        ll b = ch[i][1][ch[i][1].size()-1];
        dp[i][now-1]++;
        dp[i][b]--;
    }
    rep(i,0,C){
        rep(j,0,100099){
            dp[i][j+1] += dp[i][j];
        }
    }
    ll ans = 0;
    
    rep(j,0,100009){
        ll cnt = 0;
        rep(i,0,C)cnt += dp[i][j];
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}