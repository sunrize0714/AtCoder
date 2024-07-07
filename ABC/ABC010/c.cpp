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
    double sx,sy,gx,gy,t,v;
    cin >> sx >> sy >> gx >> gy >> t >> v;
    ll n;
    cin >> n;
    //double e = 1e20;
    vector<double> x(n),y(n);
    rep(i,0,n)cin >> x[i] >> y[i];
    rep(i,0,n){
        double dist = sqrt((sx-x[i])*(sx-x[i]) + (sy-y[i])*(sy-y[i]));
        double dist2 = sqrt((gx-x[i])*(gx-x[i]) + (gy-y[i])*(gy-y[i]));
        if(dist + dist2 <= t*v){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}