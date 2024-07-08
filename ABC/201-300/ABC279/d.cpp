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

ll a,b;
double times(ll n){
    return (double)a/sqrt(n+1) + (double)b*n;
}

int main(){
    cin >> a >> b;
    ll l = 0;
    ll r = a/b;
    while(abs(l-r) > 2){
        ll m1 = (l*2+r)/3;
        ll m2 = (l+r*2)/3;
        if(times(m1) <= times(m2))r = m2;
        else l = m1;
    }
    double ans = (double)a;
    rep(i,l,r+2){
        ans = min(ans,times(i));
    }
    cout << setprecision(15) << ans << endl;
}