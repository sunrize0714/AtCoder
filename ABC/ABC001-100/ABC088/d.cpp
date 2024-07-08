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
    ll h,w;
    cin >> h >> w;
    vs s(h);
    rep(i,0,h)cin >> s[i];
    ll ans = 0;
    rep(i,0,h)rep(j,0,w)if(s[i][j] == '.')ans++;
    vvll g(h*w);
    vll dist(h*w,-1);
    
    rep(i,0,h){
        rep(j,1,w){
            if(s[i][j] == '.' && s[i][j-1] == '.'){
                g[i*w+j].push_back(i*w+j-1);
                g[i*w+j-1].push_back(i*w+j);
            }
        }
    }

    rep(i,1,h){
        rep(j,0,w){
            if(s[i][j] == '.' && s[i-1][j] == '.'){
                g[i*w+j].push_back((i-1)*w+j);
                g[(i-1)*w+j].push_back(i*w+j);
            }
        }
    }

    queue<ll> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        ll pos = q.front();q.pop();
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            if(dist[to] == -1){
                dist[to] = dist[pos] + 1;
                q.push(to);
            }
        }
    }

    if(dist[h*w-1] == -1){
        cout << -1 << endl;
        return 0;
    }
    else cout << ans - dist[h*w-1] - 1 << endl;
}