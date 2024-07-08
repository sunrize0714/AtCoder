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
    vll x(m);
    rep(i,0,m)cin >> x[i];
    rep(i,0,m)x[i]--;
    vll imos(n,0);
    ll ans = 0;
    rep(i,1,m){
        ll from = x[i-1],to = x[i];
        if(from > to)swap(from,to);
        ll dist1 = to - from;
        ll dist2 = n - dist1;
        ans += dist1;
        imos[from] += dist2-dist1;
        imos[to] -= dist2-dist1;
    }
    ll cnt = imos[0];
    rep(i,1,n){
        imos[i] += imos[i-1];
        cnt = min(cnt,imos[i]);
    }
    cout << cnt + ans << endl;
}