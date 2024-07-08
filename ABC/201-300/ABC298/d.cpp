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
    ll q;
    cin >> q;
    deque<ll> a;
    a.push_back(1);
    ll ans = 1;
    ll pow = 1;
    while(q--){
        ll x;
        cin >> x;
        if(x == 1){
            ll i;
            cin >> i;
            ans *= 10;
            ans += i;
            ans %= mod;
            a.push_back(i);
            pow *= 10;
            pow %= mod;
        }
        if(x == 2){
            ll pos = a[0];
            pos *= pow;
            pos %= mod;
            ans -= pos;
            ans += mod;
            ans %= mod;
            pow *= modinv(10,mod);
            ans += mod;
            ans %= mod;
            pow %= mod;
            a.pop_front();
        }
        if(x == 3){
            cout << ans << endl;
        }
    }
}