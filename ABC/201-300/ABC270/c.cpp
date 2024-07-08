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

int main(){
    ll n,x,y;
    cin >> n >> x >> y;
    vvll g(n+1);
    rep(i,0,n-1){
        ll u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }   
    vll dist(n+1,1e10);
    dist[x] = 0;
    queue<ll> q;
    q.push(x);
    while(!q.empty()){
        ll pos = q.front();q.pop();
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            if(dist[to] > dist[pos] + 1){
                dist[to] = dist[pos] + 1;
                q.push(to);
            }
        }
    }

    stack<ll> ans;
    ans.push(y);
    while(y != x){
        rep(i,0,g[y].size()){
            ll to = g[y][i];
            if(dist[to] == dist[y]-1){
                ans.push(to);
                y = to;
                break;
            }
        }
    }
    while(!ans.empty()){
        ll pos = ans.top();
        cout << pos << " ";
        ans.pop();
    }
}