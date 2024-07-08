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
    ll n,m;
    cin >> n >> m;
    vll p(n),l(m),d(m);
    rep(i,0,n)cin >> p[i];
    rep(i,0,m)cin >> l[i];
    rep(i,0,m)cin >> d[i];
    ll ans = 0;
    rep(i,0,n)ans += p[i];
    vp coop;
    rep(i,0,n)coop.push_back(make_pair(p[i],1e15));
    rep(i,0,m)coop.push_back(make_pair(l[i],d[i]));
    priority_queue<ll> q;
    sort(all(coop));
    rep(i,0,coop.size()){
        if(coop[i].second == 1e15){
            if(!q.empty()){
                ll pos = q.top();
                ans -= pos;
                q.pop();
            }
        }
        else{
            q.push(coop[i].second);
        }
        
    }
    cout << ans << endl;
}