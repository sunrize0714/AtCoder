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
    vll a(k);
    rep(i,0,k)cin >> a[i];
    vector<double> x(n),y(n);
    vector<double> b(k),c(k);
    rep(i,0,n){
        cin >> x[i] >> y[i];
    } 
    rep(i,0,k){
        a[i]--;
        b[i] = x[a[i]];
        c[i] = y[a[i]];
    }
    double mini = 0.0;
    rep(i,0,n){
        double pos = 1e14;
        rep(j,0,k){
            double li = (x[i]-b[j])*(x[i]-b[j]) + (y[i]-c[j])*(y[i]-c[j]);
            li = sqrt(li);
            pos = min(pos,li);
        }
        mini = max(mini,pos);
    }
    cout << setprecision(15) << mini << endl;
}