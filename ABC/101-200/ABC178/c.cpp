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
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if(u < 0) u += m;
    return u;
}

int main(){
    ll n;
    cin >> n;
    n--;
    ll ans = 10;
    ll zero = 9;
    ll both = 8;
    ll m = 1000000007;
    while(n--){
        ans *= 10;
        zero *= 9;
        both *= 8;
        ans %= m;
        zero %= m;
        both %= m;
    }
    ans += both - 2*zero;
    ans += 2*m;
    cout << ans % m << endl;
}