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
    ll n,m;
    cin >> n >> m;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    map<ll,ll> mp;
    ll pos = 0;
    mp[pos]++;
    rep(i,0,n){
        pos+=a[i];
        pos%=m;
        mp[pos]++;
    }
    a[0]%=m;
    rep(i,1,n){
        a[i]+=a[i-1];
        a[i]%=m;
    }
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    ll ans=0;
    rep(i,0,a.size())ans+=mp[a[i]]*(mp[a[i]]-1)/2;
    cout << ans << endl;
}