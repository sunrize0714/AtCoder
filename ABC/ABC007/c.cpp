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
    ll r,c,sy,sx,gy,gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--,sx--,gy--,gx--;
    vs s(r);
    rep(i,0,r)cin >> s[i];
    vll dist(r*c,-1);
    vvll g(r*c);

    rep(i,0,r){
        rep(j,1,c){
            if(s[i][j] == '.' && s[i][j-1] == '.'){
                g[i*c+j].push_back(i*c+j-1);
                g[i*c+j-1].push_back(i*c+j);
            }
        }
    }

    rep(i,1,r){
        rep(j,0,c){
            if(s[i][j] == '.' && s[i-1][j] == '.'){
                g[i*c+j].push_back(i*c+j-c);
                g[i*c+j-c].push_back(i*c+j);
            }
        }
    }

    queue<ll> q;
    q.push(sy*c + sx);
    dist[sy*c + sx] = 0;
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
    cout << dist[gy*c+gx] << endl;
}