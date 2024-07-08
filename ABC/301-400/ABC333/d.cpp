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

int main(){
    ll n;
    cin >> n;
    vll u(n-1),v(n-1);
    rep(i,0,n-1)cin >> u[i] >> v[i];
    vvll g(n);
    rep(i,0,n-1){
        u[i]--,v[i]--;
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    if(g[0].size() == 1){
        cout << 1 << endl;
        return 0;
    }
    vll group(n,-1);
    group[0] = 0;
    map<ll,ll> m;
    rep(i,0,g[0].size()){
        ll col = i+1;
        queue<ll> q;
        q.push(g[0][i]);
        while(!q.empty()){
            ll pos = q.front();q.pop();
            group[pos] = col;
            m[col]++;
            rep(j,0,g[pos].size()){
                ll to = g[pos][j];
                if(group[to] == -1){
                    q.push(to);
                }
            }
        }
    }
    ll ans = 0;
    rep(i,0,g[0].size()){
        ans = max(ans,m[i+1]);
    }
    cout << n - ans << endl;
}