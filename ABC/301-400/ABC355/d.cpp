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
    vll l(n),r(n);
    rep(i,0,n)cin >> l[i] >> r[i];
    vp p;
    rep(i,0,n)p.push_back(make_pair(l[i],r[i]));
    sort(all(p));
    ll ans = 0;
    rep(i,0,n){
        ll st = p[i].first, go = p[i].second;
        pair<ll,ll> x = make_pair(st,st),y = make_pair(go+1,go+1);
        ll itr = lower_bound(all(p),y)-p.begin();
        ans += max(0LL,itr-i-1);
    }
    cout << ans << endl;
}