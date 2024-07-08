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
    ll h,w,t;
    cin >> h >> w >> t;
    vs s(h);
    rep(i,0,h)cin >> s[i];
    ll st,go;
    rep(i,0,h)rep(j,0,w)if(s[i][j] == 'S')st = i*w+j;
    rep(i,0,h)rep(j,0,w)if(s[i][j] == 'G')go = i*w+j;
    ll ok = 1,ng = t;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        vector<vector<pair<ll,ll>>> g(h*w);
        rep(i,0,h){
            rep(j,1,w){
                ll pos = w*i+j,to = pos-1;
                if(s[i][j] == '#')g[to].push_back(make_pair(pos,mid));
                else g[to].push_back(make_pair(pos,1));
                if(s[i][j-1] == '#')g[pos].push_back(make_pair(to,mid));
                else g[pos].push_back(make_pair(to,1));
            }
        }

        rep(i,1,h){
            rep(j,0,w){
                ll pos = w*i+j,to = pos-w;
                if(s[i][j] == '#')g[to].push_back(make_pair(pos,mid));
                else g[to].push_back(make_pair(pos,1));
                if(s[i-1][j] == '#')g[pos].push_back(make_pair(to,mid));
                else g[pos].push_back(make_pair(to,1));
            }
        }
        vll dist(h*w,1e18);
        dist[st] = 0;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push(make_pair(0,st));
        while(!pq.empty()){
            ll pos = pq.top().second;pq.pop();
            if(dist[pos] < dist[pos])continue;
            rep(i,0,g[pos].size()){
                pair<ll,ll> to = g[pos][i];
                if(dist[to.first] > dist[pos]+to.second){
                    dist[to.first] = dist[pos]+to.second;
                    pq.push(make_pair(dist[to.first],to.first));
                }
            }
        }
        if(dist[go] <= t)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}