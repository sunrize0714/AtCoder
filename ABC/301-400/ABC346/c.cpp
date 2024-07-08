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

int main(){
    ll n,k;
    cin >> n >> k;
    vll a(n);rep(i,0,n)cin >> a[i];
    ll ans = 0;
    if(k%2 == 0){
        ans = k;
        ans/=2;
        ans*=(k+1);
    }
    else{
        ans = k+1;
        ans/=2;
        ans*=k;
    }
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    rep(i,0,a.size()){
        if(a[i] <= k)ans -= a[i];
    }
    cout << ans << endl;
}