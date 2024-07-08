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
    ll n;
    cin >> n;
    vll t(n+1),x(n+1),y(n+1);
    t[0] = 0,x[0] = 0,y[0] = 0;
    rep(i,1,n+1)cin >> t[i] >> x[i] >> y[i];
    rep(i,1,n+1){
        if((t[i]-t[i-1])%2 != abs(x[i]+y[i]-x[i-1]-y[i-1])%2 || t[i]-t[i-1] < abs(x[i]-x[i-1]) + abs(y[i] - y[i-1])){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}