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
    ll b=m,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=m; 
    if(u<0)u+=m;
    return u;
}

int main(){
    ll n;
    cin >> n;
    ll p = 1;
    ll x = n;
    ll y = 0;
    while(x > 0){
        x /= 10;
        p *= 10;
        y++;
    }
    ll pos = 1LL;
    ll tmp = p;
    tmp %= mod;
    y*= n;
    rep(i,0,62){
        if(y & (1LL<<i)){
            pos *= tmp;
            pos %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
    }
    pos--;
    pos *= modinv(p-1,mod);
    pos %= mod;
    pos *= n;
    cout << pos % mod;
}