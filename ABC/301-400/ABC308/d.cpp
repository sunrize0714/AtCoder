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
    ll h,w;
    cin >> h >> w;
    vs s(h);
    rep(i,0,h)cin >> s[i];
    string a = "snukes";

    vvll g(h*w);

    rep(i,0,h){
        rep(j,0,w){
            rep(k,0,4){
                ll x = j+dx4[k];
                ll y = i+dy4[k];
                if(x < 0 || x >= w || y < 0 || y >= h)continue;
                rep(l,0,5){
                    if(s[i][j] == a[l] && s[y][x] == a[l+1]){
                        g[i*w+j].push_back(y*w+x);
                    }
                }
            }
        }
    }

    vll dist(h*w,-1);
    dist[0] = 0;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll pos = q.front();q.pop();
        rep(i,0,g[pos].size()){
            ll to = g[pos][i];
            if(dist[to] == -1){
                q.push(to);
                dist[to] = dist[pos] + 1;
            }
        }
    }
    dist[h*w-1] == -1 ? cout << "No" << endl : cout << "Yes" << endl;
}