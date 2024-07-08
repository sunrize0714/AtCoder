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
    ll n;
    cin >> n;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll len(n,1);
    rep(i,0,n){
        ll pos = a[i];
        while(pos>0){
            pos /= 10;
            len[i]*=10;
        }
    }
    unsigned long long ans = 0;
    vll wa(n+1,0);
    rep(i,0,n)wa[i+1] = wa[i] + a[i];
    revrep(i,1,n){
        unsigned long long cnt = wa[i];
        cnt %= mod;
        cnt *= len[i];
        cnt %= mod;

        cnt += a[i]*i;
        cnt %= mod;
        ans += cnt;
        ans %= mod;
    }
    cout << ans << endl;
}