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
    vll h(n);
    rep(i,0,n)cin >> h[i];
    vll u(m),v(m);
    rep(i,0,m)cin >> u[i] >> v[i];
    priority_queue<pair<ll,ll>,vp,greater<pair<ll,ll>>> pq;
    vector<vp> g(n);
    rep(i,0,m){
        u[i]--,v[i]--;

        if(h[u[i]] > h[v[i]]){
            g[u[i]].push_back(make_pair(v[i],0LL));
            g[v[i]].push_back(make_pair(u[i],(h[u[i]]-h[v[i]])));
        }
        else if(h[u[i]] < h[v[i]]){
            g[u[i]].push_back(make_pair(v[i],(h[v[i]]-h[u[i]])));
            g[v[i]].push_back(make_pair(u[i],0LL));
        }
        else{
            g[u[i]].push_back(make_pair(v[i],0LL));
            g[v[i]].push_back(make_pair(u[i],0LL));
        }
    }
    vll cur(n,2e18);
    vb kakutei(n,false);

    cur[0] = 0;
    pq.push(make_pair(0LL,0LL));

    ll ans = 0;

    while(!pq.empty()){
        ll pos = pq.top().second;pq.pop();
        if(kakutei[pos])continue;
        kakutei[pos] = true;
        rep(i,0,g[pos].size()){
            ll nex = g[pos][i].first;
            ll cost = g[pos][i].second;

            if(cur[nex] > cur[pos] + cost){
                cur[nex] = cur[pos] + cost;
                pq.push(make_pair(cur[nex],nex));
            }
        }
    }
    rep(i,1,n){
        ll score = h[0]-h[i]-cur[i];
        score *= -1;
        ans = min(ans,score);
    }
    cout << ans*-1 << endl;
}