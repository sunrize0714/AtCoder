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
    vvll g(h*w);
    vs s(h);
    rep(i,0,h)cin >> s[i];

    vll start;
    rep(i,0,h){
        rep(j,0,w){
            if(s[i][j] == '.'){
                start.push_back(i*w+j);
            }
        }
    }

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
                g[(i-1)*w+j].push_back(i*w+j);
                g[i*w+j].push_back((i-1)*w+j);
            }
        }
    }
    ll maxdist = 0;
    rep(i,0,start.size()){
        vll dist(h*w,-1);
        dist[start[i]] = 0;
        queue<ll> q;
        q.push(start[i]);
        while(!q.empty()){
            ll pos = q.front();q.pop();
            rep(i,0,g[pos].size()){
                ll to = g[pos][i];
                if(dist[to] == -1){
                    dist[to] = dist[pos] + 1;
                    maxdist = max(maxdist,dist[to]);
                    q.push(to);
                }
            }
        }
    }

    cout << maxdist << endl;
}