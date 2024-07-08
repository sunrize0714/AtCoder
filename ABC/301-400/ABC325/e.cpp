#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
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

int main(){
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    vvll d(n,vll(n));
    rep(i,0,n)rep(j,0,n)cin >> d[i][j];

    vector<vector<pair<ll,ll>>> g(2*n);
    rep(i,0,n)rep(j,i+1,n){
        g[i].push_back(make_pair(j,d[i][j]*a));
        g[j].push_back(make_pair(i,d[i][j]*a));
        g[i+n].push_back(make_pair(j+n,d[i][j]*b+c));
        g[j+n].push_back(make_pair(i+n,d[i][j]*b+c));
    }
    vll dist(2*n,1e18);
    dist[0] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push(make_pair(dist[0],0));
    while(!pq.empty()){
        ll pos = pq.top().second;pq.pop();
        rep(i,0,g[pos].size()){
            ll to = g[pos][i].first;
            ll cost = g[pos][i].second;
            if(dist[to] > dist[pos] + cost){
                dist[to] = dist[pos]+cost;
                pq.push(make_pair(dist[to],to));
            }
        }
    }
    dist[2*n-1] = 0;
    pq.push(make_pair(dist[2*n-1],2*n-1));
    while(!pq.empty()){
        ll pos = pq.top().second;pq.pop();
        rep(i,0,g[pos].size()){
            ll to = g[pos][i].first;
            ll cost = g[pos][i].second;
            if(dist[to] > dist[pos] + cost){
                dist[to] = dist[pos]+cost;
                pq.push(make_pair(dist[to],to));
            }
        }
    }
    ll ans = 2e18;
    rep(i,0,n)ans = min(ans,dist[i]+dist[i+n]);
    cout << ans << endl;
}