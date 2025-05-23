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
    ll n,m,t;
    cin >> n >> m >> t;
    vll a(n);
    rep(i,1,n)cin >> a[i];
    vll x(m),y(m);
    rep(i,0,m)cin >> x[i] >> y[i];
    ll pos = 1,cnt = 0;
    while(pos < n){
        t -= a[pos];
        if(t <= 0){
            cout << "No" << endl;
            return 0;
        }
        pos++;
        if(cnt < m){
            if(pos == x[cnt]){
                t += y[cnt];
                cnt++;
            }
        }
    }
    cout << "Yes" << endl;
}