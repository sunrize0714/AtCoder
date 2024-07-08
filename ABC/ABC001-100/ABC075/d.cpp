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
    ll n,k;
    cin >> n >> k;
    vll x(n),y(n);
    rep(i,0,n)cin >> x[i] >> y[i];
    vp a;
    rep(i,0,n)a.push_back(make_pair(x[i],y[i]));
    sort(a.begin(),a.end());
    ll ans = 1e18;
    rep(i,0,n-k+1){
        ll hor = x[i+k-1] - x[i];
        vll ver;
        ll v;
        rep(j,i,i+k){
            ver.push_back(a[j].second);
        }
        sort(ver.begin(),ver.end());
        v = ver[k-1] - ver[0];
        ans = min(ans,hor*v);
    }
    a.clear();
    rep(i,0,n)a.push_back(make_pair(y[i],x[i]));
    sort(a.begin(),a.end());
    rep(i,0,n-k+1){
        ll ver = y[i+k-1] - y[i];
        vll hor;
        ll h;
        rep(j,i,i+k){
            hor.push_back(a[j].second);
        }
        sort(hor.begin(),hor.end());
        h = hor[k-1] - hor[0];
        ans = min(ans,ver*h);
    }
    cout << abs(ans) << endl;
}