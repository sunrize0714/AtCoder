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
#define all(a) a.begin(),a.end()
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
    ll n,m,k;
    cin >> n >> m >> k;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    multiset<ll> lo,hi;
    vll b(m);
    rep(i,0,m)b[i] = a[i];
    sort(all(b));
    rep(i,0,k)lo.insert(b[i]);
    rep(i,k,m)hi.insert(b[i]);
    ll ans = 0;
    rep(i,0,k)ans += b[i];
    cout << ans << " ";
    rep(i,m,n){
        ll pos = a[i-m];
        if(lo.find(pos) != lo.end()){
            ans -= pos;
            lo.erase(lo.find(pos));
            hi.insert(a[i]);
            ll to = *hi.begin();
            hi.erase(hi.find(to));
            lo.insert(to);
            ans += to;
        }
        else{
            hi.erase(pos);
            lo.insert(a[i]);
            ans += a[i];
            ll to = *lo.rbegin();
            ans -= to;
            lo.erase(lo.find(to));
            hi.insert(to);
        }
        cout << ans << " ";
    }
    cout << endl;
}