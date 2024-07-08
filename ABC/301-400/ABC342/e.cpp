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
    ll n,m;
    cin >> n >> m;
    vll l(m),d(m),k(m),c(m),a(m),b(m);
    rep(i,0,m){
        cin >> l[i] >> d[i] >> k[i] >> c[i] >> a[i] >> b[i];
    }
    vector<vector<pair<ll,ll>>> rail(n);
    rep(i,0,m){
        a[i]--,b[i]--;
        rail[a[i]].push_back(make_pair(b[i],c[i]));
    }
    // last[x]: nにたどり着けるとき、駅xを出る時間
    vll last(n,-1e18);
    
}