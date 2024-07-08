#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
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

ll n;
map<ll,ll> mp;
ll dp(ll N){
    if(N > n)return 0;
    if(N == n)return 1;
    if(mp.count(N))return mp[N];
    ll pos = 0;
    rep(i,2,7){
        pos+=dp(i*N);
        pos %= mod;
    }
    return mp[N] = pos * modinv(5,mod) % mod;
}

int main(){
    cin >> n;
    cout << dp(1) << endl;
}