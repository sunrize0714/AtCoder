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

int main(){
    ll n,m;
    cin >> n >> m;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll u(m),v(m),b(m);
    rep(i,0,m)cin >> u[i] >> v[i] >> b[i];
    vector<vector<pair<ll,ll>>> g(n);
    rep(i,0,m){
        u[i]--,v[i]--;
        g[u[i]].push_back({v[i],b[i]});
        g[v[i]].push_back({u[i],b[i]});
    }
    vll dist(n,1e18);
    dist[0] = 0;
    vll visited(n,0);
    visited[0] = 1;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        ll pos = pq.top().second;pq.pop();
        if(visited[pos] == 1)continue;
        visited[pos] = 1;
        rep(i,0,g[pos].size()){
            ll to = g[pos][i].first;
            ll cost = g[pos][i].second;
            if(dist[to] > dist[pos]+cost){
                dist[to] = dist[pos]+cost;
                pq.push({dist[to],to});
            }
        }
    }
    rep(i,1,n){
        cout << dist[i] << " ";
    }
}
