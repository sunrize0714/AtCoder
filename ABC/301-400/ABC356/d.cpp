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

int main(){
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    rep(i,0,61){
        if(m & (1LL<<i)){
            ll cnt = 0;
            ll pos = n+1;
            ll now = 1LL << (i+1);
            ll x = pos/now;
            ll add = pos%now;
            add = max(0LL,add-now/2);
            ans += x*now/2 + add;
            ans %= mod;
        }
    }
    cout << ans << endl;
}