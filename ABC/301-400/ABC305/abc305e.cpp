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
    ll n,m,k;
    cin >> n >> m >> k;
    vll a(m),b(m),p(k),h(k);
    rep(i,0,m)cin >> a[i] >> b[i];
    rep(i,0,k)cin >> p[i] >> h[i];
    vvll g(n);
    rep(i,0,m){
        a[i]--,b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    vll dist(n,-1);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,less<pair<ll,ll>>> pq;
    rep(i,0,k){
        p[i]--;
        dist[p[i]] = h[i];
        pq.push(make_pair(h[i],p[i]));
    }
    while(!pq.empty()){
        ll pos = pq.top().second;pq.pop();
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            if(dist[to] < dist[pos]-1){
                pq.push(make_pair(dist[pos]-1,to));
                dist[to] = dist[pos]-1;
            }
        }
    }
    ll cnt = 0;
    rep(i,0,n)if(dist[i] >= 0)cnt++;
    cout << cnt << endl;
    rep(i,0,n){
        if(dist[i] >= 0)cout << i+1 << " ";
    }
    cout << endl;
}