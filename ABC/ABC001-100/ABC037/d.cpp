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
    ll h,w;
    cin >> h >> w;
    vvll a(h,vll(w));
    rep(i,0,h)rep(j,0,w)cin >> a[i][j];
    vll dp(h*w,1);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
    rep(i,0,h)rep(j,0,w){
        q.push(make_pair(a[i][j],i*w+j));
    }
    while(!q.empty()){
        ll pos = q.top().second;q.pop();
        ll x = pos/w,y = pos%w;
        rep(i,0,4){
            ll tox = x + dx4[i],toy = y + dy4[i];
            if(tox >= 0 && toy >= 0 && tox < h && toy < w){
                if(a[x][y] < a[tox][toy]){
                    dp[tox*w+toy] += dp[x*w+y];
                    dp[tox*w+toy] %= m;
                }
            }
        }
    }
    ll ans = 0;
    rep(i,0,h*w){
        ans += dp[i];
        ans %= m;
    }
    cout << ans << endl;
}