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

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    rep(i,1,n+1){
        ll pos = i;
        while(pos > 0){
            if(pos % 10 == 7){
                break;
            }
            pos /= 10;
        }
        if(pos != 0)continue;
        pos = i;
        while(pos > 0){
            if(pos % 8 == 7){
                break;
            }
            pos /= 8;
        }
        if(pos == 0)ans++;
    }
    cout << ans << endl;
}