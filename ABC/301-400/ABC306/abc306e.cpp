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
    ll n,k,q;
    cin >> n >> k >> q;
    multiset<ll> lo,hi;
    rep(i,0,k)lo.insert(0);
    rep(i,k,n)hi.insert(0);
    vll a(n,0);
    ll ans = 0;
    rep(i,0,q){
        ll x,y;
        cin >> x >> y;
        x--;
        hi.insert(y);
        while(true){
            auto lomin = lo.begin(),himax = hi.end();
            himax--;
            if(*lomin >= *himax)break;
            ll A = *lomin,B = *himax;
            lo.erase(lo.find(A)),hi.erase(hi.find(B));
            lo.insert(B),hi.insert(A);
            ans += B-A;
        }
        auto itr = lo.find(a[x]);
        if(itr != lo.end()){
            ans -= a[x];
            lo.erase(lo.find(a[x]));
            auto itr2 = hi.end();itr2--;
            hi.erase(hi.find(*itr2));
            lo.insert(*itr2);
            ans += *itr2;
        }
        else hi.erase(hi.find(a[x]));
        cout << ans << endl;
        a[x] = y;
    }
}