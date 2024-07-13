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

bool in_field(ll l,ll r,ll x){
    if(l <= x && x < r)return true;
    else return false;
}

ll distance(ll ax,ll ay,ll bx, ll by){
    return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

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
            if(dist[to] > dist[pos]+a[pos]+cost){
                dist[to] = dist[pos]+a[pos]+cost;
                pq.push({dist[to],to});
            }
        }
    }
    rep(i,1,n){
        cout << dist[i]+a[i] << " ";
    }
}
