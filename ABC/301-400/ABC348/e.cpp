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
    ll n;
    cin >> n;
    vll a(n-1),b(n-1);
    rep(i,0,n-1)cin >> a[i] >> b[i];
    vll c(n);
    rep(i,0,n)cin >> c[i];
    vvll g(n+1);
    rep(i,0,n-1){
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vll dp(n+1,0);
    rep(i,1,n+1)dp[i] = c[i-1];
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vll in(n+1,0);
    rep(i,0,n-1){
        in[a[i]]++;
        in[b[i]]++;
    }
    rep(i,1,n+1){
        if(in[i] == 1){
            pq.push(make_pair(dp[i],i));
        }
    }
    ll ans = 0;
    ll cnt = n;
    while(!pq.empty()){
        ll pos = pq.top().second;pq.pop();
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            if(dp[to] != 0){
                dp[to] += dp[pos];
                ans += dp[pos];
                dp[pos] = 0;
                in[to]--;
                cnt--;
                if(in[to] == 1){
                    pq.push(make_pair(dp[to],to));
                }
            }
        }
        if(cnt == 1)break;
    }
    cout << ans << endl;
}