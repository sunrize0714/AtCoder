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
    vll wa(n+1,0);
    rep(i,0,n)wa[i+1] = wa[i] + a[i];
    ll ans = wa[n];
    rep(y,2,n-1){
        ll ok = 0,ng = y;
        while(abs(ok-ng) > 1){
            ll mid = (ok+ng)/2;
            ll left = wa[mid]-wa[0];
            ll right = wa[y]-wa[mid];
            if(left > right)ng = mid;
            else ok = mid;
        }
        ll x = ok;
        if(x+1 != y){
            ll lo = abs(wa[y]-wa[x]*2);
            ll hi = abs(wa[y]-wa[x+1]*2);
            if(lo > hi)x++;
        }
        ok = y,ng = n;
        while(abs(ok-ng) > 1){
            ll mid = (ok+ng)/2;
            ll left = wa[mid]-wa[y];
            ll right = wa[n]-wa[mid];
            if(left > right)ng = mid;
            else ok = mid;
        }
        ll z = ok;
        if(z+1 != n){
            ll lo = abs(wa[n]-wa[z]-wa[z]+wa[y]);
            ll hi = abs(wa[n]-wa[z+1]*2+wa[y]);
            if(lo > hi)z++;
        }
        ans = min(ans,max({wa[x]-wa[0],wa[y]-wa[x],wa[z]-wa[y],wa[n]-wa[z]})-min({wa[x]-wa[0],wa[y]-wa[x],wa[z]-wa[y],wa[n]-wa[z]}));
    }
    cout << ans << endl;
}