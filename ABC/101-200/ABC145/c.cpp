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
    vector<long double> x(n),y(n);
    rep(i,0,n)cin >> x[i] >> y[i];
    vll array(n);
    rep(i,0,n)array[i] = i;
    long double ans = 0.0;
    long double cnt = 0.0;
    do{
        rep(i,1,n){
            ll to = array[i-1],pos = array[i];
            long double dist = (x[pos]-x[to])*(x[pos]-x[to]) + (y[pos]-y[to])*(y[pos]-y[to]);
            ans += sqrt(dist);
        }
        cnt += 1;
    }while(next_permutation(array.begin(),array.end()));
    cout << setprecision(20) << ans/cnt << endl;
}