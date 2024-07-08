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

int main(){
    ll h,w;
    cin >> h >> w;
    vvll c(10,vll(10));
    vvll a(h,vll(w));
    rep(i,0,10)rep(j,0,10)cin >> c[i][j];
    rep(i,0,h)rep(j,0,w)cin >> a[i][j];
    vll cnt(10,0);
    rep(i,0,h)rep(j,0,w)if(a[i][j]!=-1)cnt[a[i][j]]++;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vll dist(10,0);
    dist[1] = 0;
    rep(i,0,10){
        vll x(10,1e15);
        if(i == 1)continue;
        x[i] = 0;
        pq.push(make_pair(0,i));
        while(!pq.empty()){
            ll pos = pq.top().second;
            pq.pop();
            rep(j,0,10){
                if(pos == j)continue;
                ll to = j;
                ll cost = c[pos][to];
                if(x[to] > x[pos] + cost){
                    x[to] = x[pos] + cost;
                    pq.push(make_pair(x[to],to));
                }
            }
        }
        dist[i] = x[1];
    }
    ll ans = 0;
    rep(i,0,10){
        ans += dist[i]*cnt[i];
    }
    cout << ans << endl;
}