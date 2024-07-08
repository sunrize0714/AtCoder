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
    ll n,m,Q;
    cin >> n >> m >> Q;
    vvll t(n+1,vll(n+1,0));
    rep(i,0,m){
        ll l,r;
        cin >> l >> r;
        t[l][r]++;
    }
    rep(i,0,n+1)rep(j,1,n+1)t[i][j] += t[i][j-1];
    rep(i,1,n+1)rep(j,0,n+1)t[i][j] += t[i-1][j];
    rep(i,0,Q){
        ll p,q;
        cin >> p >> q;
        ll ans = t[p-1][p-1] + t[q][q] - t[p-1][q] - t[q][p-1];
        cout << ans << endl;
    }
}