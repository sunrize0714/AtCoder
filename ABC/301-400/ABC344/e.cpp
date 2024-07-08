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

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll n;
    cin >> n;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    ll q;
    cin >> q;
    map<ll,ll> f,b;
    b[-1] = a[0],f[-1] = -1;
    b[1e10] = -1,f[1e10] = a[n-1];
    rep(i,0,n){
        if(i == 0)f[a[0]] = -1; 
        else f[a[i]] = a[i-1];
        if(i == n-1)b[a[i]] = 1e10;
        else b[a[i]] = a[i+1];
    }
    rep(i,0,q){
        ll x;
        cin >> x;
        if(x == 1){
            ll a1,a2;
            cin >> a1 >> a2;
            ll pre = a1;
            ll suf = b[a1];
            f[a2] = a1;
            b[a2] = suf;
            b[a1] = a2;
            f[suf] = a2;
        }
        else{
            ll a1;
            cin >> a1;
            ll pre = f[a1];
            ll suf = b[a1];
            f[suf] = pre;
            b[pre] = suf;
            f[a1] = 0,b[a1] = 0;
        }
    }
    ll pos = -1;
    while(pos != 1e10){
        pos = b[pos];
        if(pos == 1e10)break;
        cout << pos << " "; 
    }
}