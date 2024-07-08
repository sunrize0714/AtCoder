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
#define rrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

void dfs(vvll &g,vb &visited,ll &ans,ll pos){
    ans++;
    if(ans >= 1000000)return;
    rep(i,0,g[pos].size()){
        ll to = g[pos][i];
        if(!visited[to]){
            visited[to] = true;
            dfs(g,visited,ans,to);
            if(ans >= 1000000)break;
            visited[to] = false;
        }
    }
}


int main(){
    ll n,m;
    cin >> n >> m;
    vll u(m),v(m);
    rep(i,0,m)cin >> u[i] >> v[i];
    vvll g(n);
    rep(i,0,m){
        u[i]--,v[i]--;
        g[v[i]].push_back(u[i]);
        g[u[i]].push_back(v[i]);
    }
    vb visited(n,false);
    visited[0] = true;
    ll ans = 0;
    dfs(g,visited,ans,0);
    cout << ans << endl;
}