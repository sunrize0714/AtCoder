#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
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


const ll inf = 1e30;
int op(int a,int b,int c){
    ll pos = a;
    pos 
}

int e(){
    return 1;
}
int main(){
    ll n,m;
    cin >>  n >> m;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll l(m),r(m),x(m);
    rep(i,0,m)cin >> l[i] >> r[i] >> x[i];
    rep(i,0,m){
        l[i]--,r[i]--;
        ll range = r[i] - l[i] + 1;
        rep(j,l[i],r[i]+1){
            a[j] *= modinv(range,mod);
            a[j] %= mod;
            a[j] *= (range-1);
            a[j] %= mod;
            a[j] += x[i]*modinv(range,mod);
            a[j] %= mod;
        }
    }
    rep(i,0,n)cout << a[i] << " ";
    cout << endl;
}