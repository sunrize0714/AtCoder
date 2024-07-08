#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
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
    ll n;
    cin >> n;
    vll x(n),y(n),p(n);
    rep(i,0,n)cin >> x[i] >> y[i] >> p[i];
    ll ok = 0,ng = -1;
    ll hi = -1e10,lo = 1e10;
    rep(i,0,n){
        hi = max({hi,x[i],y[i]});
        lo = min({lo,x[i],y[i]});
    }
    ok = hi-lo;
    ok += 2;

    vvll dist(n,vll(n));
    rep(i,0,n){
        rep(j,0,n){
            if(i == j)continue;
            dist[i][j] = abs(x[i]-x[j]) + abs(y[i]-y[j]);
        }
    }
    
    while(abs(ok-ng) > 1){
        ll mid = (ok+ng)/2;
        vvll g(n);
        rep(i,0,n){
            rep(j,0,n){
                if(i == j)continue;
                if(mid*p[i] >= dist[i][j]/p[i]){
                    g[i].push_back(j);
                }
            }
        }
        bool f = false;
        rep(i,0,n){
            queue<ll> q;
            set<ll> s;
            q.push(i);
            while(!q.empty()){
                ll pos = q.front();q.pop();
                s.insert(pos);
                rep(j,0,g[pos].size()){
                    ll to = g[pos][j];
                    if(s.count(to) == 0){
                        q.push(to);
                    }
                }
            }
            if(s.size() == n){
                f = true;
            }
        }
        if(f)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}