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
    ll n;
    cin >> n;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    ll cnt = 0;
    ll s = 0;
    ll to = 1;
    rep(i,0,n){
        s += a[i];
        if(s*to <= 0){
            cnt += abs(s)+1;
            s = to;
        }
        to *= -1;
    }
    ll cnt2 = 0;
    s = 0,to = -1;
    rep(i,0,n){
        s += a[i];
        if(s*to<=0){
            cnt2 += abs(s)+1;
            s = to;
        }
        to *= -1;
    }
    cout << min(cnt,cnt2) << endl;
}