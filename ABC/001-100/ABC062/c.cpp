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
    ll h,w;
    cin >> h >> w;
    if(h%3 == 0 || w%3 == 0){
        cout << 0 << endl;
        return 0;
    }
    
    ll ans = h*w;
    ll mass = h*w;
    rep(i,1,h){
        vll a(3);
        a[0] = i*w;

        ll h1 = h - i;
        a[1] = w*(h1/2);
        a[2] = mass - a[1] - a[0];
        sort(all(a));
        ans = min(ans,a[2]-a[0]);
        a[0] = i*w;
        a[1] = h1*(w/2);
        a[2] = mass - a[0] - a[1];
        sort(all(a));
        ans = min(ans,a[2]-a[0]);
    }
    swap(h,w);
    rep(i,1,h){
        vll a(3);
        a[0] = i*w;

        ll h1 = h - i;
        a[1] = w*(h1/2);
        a[2] = mass - a[1] - a[0];
        sort(all(a));
        ans = min(ans,a[2]-a[0]);
        a[0] = i*w;
        a[1] = h1*(w/2);
        a[2] = mass - a[0] - a[1];
        sort(all(a));
        ans = min(ans,a[2]-a[0]);
    }
    cout << ans << endl;
}