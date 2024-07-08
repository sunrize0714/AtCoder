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
    ll n,m;
    cin >> n >> m;
    vll c(m);
    vvll a(m);
    rep(i,0,m){
        cin >> c[i];
        rep(j,0,c[i]){
            ll to;
            cin >> to;
            a[i].push_back(to);
        }
    }

    ll ans = 0;
    rep(i,0,1<<m){
        set<ll> se;
        rep(j,0,m){
            if(i & (1 << j)){
                rep(k,0,c[j])
                se.insert(a[j][k]);
            }
        }
        if(se.size() == n)ans++;
    }
    cout << ans << endl;
}