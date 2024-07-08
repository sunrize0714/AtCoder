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
    ll n,m;
    cin >> n >> m;
    vll a(m),b(m),c(m);
    rep(i,0,m)cin >> a[i] >> b[i] >> c[i];
    vll dist(n,1e15);
    vll ans(n,-1);
    vb kakutei(n,false);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<vector<pair<ll,ll>>> g(n);
    map<ll,map<ll,ll>> ma;
    rep(i,0,m){
        a[i]--,b[i]--;
        g[a[i]].push_back(make_pair(b[i],c[i]));
        g[b[i]].push_back(make_pair(a[i],c[i]));
        ma[min(a[i],b[i])][max(a[i],b[i])] = i+1;
    }
    dist[0] = 0;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        ll pos = pq.top().second;pq.pop();
        if(kakutei[pos])continue;
        kakutei[pos] = true;
        rep(i,0,g[pos].size()){
            ll to = g[pos][i].first;
            ll cost = g[pos][i].second;
            if(dist[to] > dist[pos] + cost){
                dist[to] = dist[pos] + cost;
                pq.push(make_pair(dist[to],to));
                ans[to] = ma[min(pos,to)][max(pos,to)];
            }
        }
    }
    rep(i,1,n)cout << ans[i] << " ";
}