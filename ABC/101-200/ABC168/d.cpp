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
    vvll g(n);
    rep(i,0,m){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vll dist(n,1e18);
    vll ans(n,0);
    dist[0] = 0;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll pos = q.front();q.pop();
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            if(dist[to] > dist[pos]+1){
                dist[to] = dist[pos]+1;
                ans[to] = pos;
                q.push(to);
            }
        }
    } 
    cout << "Yes" << endl;
    rep(i,1,n)cout << ans[i]+1 << endl;
}