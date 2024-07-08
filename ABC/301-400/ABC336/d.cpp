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
    vll l(n,0),r(n,0);
    ll cnt = 1;
    rep(i,0,n){
        if(a[i] >= cnt){
            l[i] = cnt;
            cnt++;
        }
        else{
            l[i] = a[i];
            cnt = a[i] + 1;
        }
    }
    cnt = 1;
    revrep(i,0,n){
        if(a[i] >= cnt){
            r[i] = cnt;
            cnt++;
        }
        else{
            r[i] = a[i];
            cnt = a[i] + 1;
        }
    }
    ll ans = 1;
    rep(i,0,n){
        ans = max(ans,min(r[i],l[i]));
    }
    cout << ans << endl;
}