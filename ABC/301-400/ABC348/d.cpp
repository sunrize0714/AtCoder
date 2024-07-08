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
    ll h,w;
    cin >> h >> w;
    vs a(h);
    rep(i,0,h)cin >> a[i];
    ll n;
    cin >> n;
    vll r(n),c(n),e(n);
    rep(i,0,n)cin >> r[i] >> c[i] >> e[i];
    rep(i,0,n)r[i]--,c[i]--;
    vvll g(h*w);
    rep(i,0,h){
        rep(j,1,w){
            if(a[i][j] != '#' && a[i][j-1] != '#'){
                g[w*i+j].push_back(w*i+j-1);
                g[w*i+j-1].push_back(w*i+j);
            }
        }
    }
    rep(i,1,h){
        rep(j,0,w){
            if(a[i][j] != '#' && a[i-1][j] != '#'){
                g[w*i+j].push_back(w*i+j-w);
                g[w*i+j-w].push_back(w*i+j);
            }
        }
    }
    ll st,go;
    rep(i,0,h){
        rep(j,0,w){
            if(a[i][j] == 'S')st = i*w+j;
            if(a[i][j] == 'T')go = i*w+j;
        }
    }
    vll dist(h*w,-1e10);
    dist[st] = 0;
    queue<ll> q;
    q.push(st);
    while(!q.empty()){
        ll pos = q.front();q.pop();
        rep(i,0,n){
            if(r[i]*w+c[i] == pos){
                if(dist[pos] <= e[i]){
                    dist[pos] = e[i];
                    e[i] = 0;
                }
            }
        }
        if(dist[pos] > 0){
            rep(i,0,g[pos].size()){
                ll to = g[pos][i];
                if(dist[to] < dist[pos]-1){
                    dist[to] = dist[pos] -1;
                    q.push(to);
                }
            }
        }
    }
    if(dist[go] >= 0)cout << "Yes";
    else cout << "No";
}