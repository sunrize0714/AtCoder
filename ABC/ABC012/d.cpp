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
    ll n,m;
    cin >> n >> m;
    vll a(m),b(m),t(m);
    vector<vector<pair<ll,ll>>> g(n);
    ll ans = 1e18;
    rep(i,0,m)cin >> a[i] >> b[i] >> t[i];
    rep(i,0,m){
        a[i]--,b[i]--;
        g[a[i]].push_back(make_pair(b[i],t[i]));
        g[b[i]].push_back(make_pair(a[i],t[i]));
    }
    rep(i,0,n){
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vll dist(n,1e18);
        dist[i] = 0;
        pq.push(make_pair(0,i));
        while(!pq.empty()){
            ll pos = pq.top().second;pq.pop();
            rep(i,0,g[pos].size()){
                pair<ll,ll> to = g[pos][i];
                if(dist[to.first] > dist[pos]+to.second){
                    dist[to.first] = dist[pos]+to.second;
                    pq.push(make_pair(dist[to.first],to.first));
                }
            }
        }
        ll cnt = 0;
        rep(j,0,n)cnt = max(cnt,dist[j]);
        ans = min(ans,cnt);
    }
    cout << ans << endl;
}