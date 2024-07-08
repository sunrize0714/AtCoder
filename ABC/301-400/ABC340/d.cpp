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
    ll n;
    cin >> n;
    vll a(n-1),b(n-1),x(n-1);
    rep(i,0,n-1)cin >> a[i] >> b[i] >> x[i];
    vector<vector<pair<ll,ll>>> g(n+1);
    vll dist(n+1,1e15);
    vb k(n,false);
    rep(i,0,n-1){
        g[i].push_back(make_pair(i+1,a[i]));
        g[i].push_back(make_pair(x[i]-1,b[i]));
    }
    dist[0] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        ll pos = pq.top().second;pq.pop();
        if(k[pos])continue;
        k[pos] = true;
        rep(i,0,g[pos].size()){
            ll to = g[pos][i].first;
            ll cost = g[pos][i].second;
            if(dist[to] > dist[pos] + cost){
                dist[to] = dist[pos] + cost;
                pq.push(make_pair(dist[to],to));
            } 
        }
    }
    cout << dist[n-1] << endl;
}