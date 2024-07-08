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
    ll n,t;
    cin >> n >> t;
    vll a(t),b(t);
    rep(i,0,t)cin >> a[i] >> b[i];
    map<ll,ll> m;
    vll p(n,0);
    rep(i,0,n)m[0]++;
    ll ans = 1;
    rep(i,0,t){
        a[i]--;
        p[a[i]] += b[i];
        if(m[p[a[i]]] == 0)ans++;
        if(m[p[a[i]]-b[i]] == 1)ans--;
        m[p[a[i]]]++;
        m[p[a[i]]-b[i]]--;
        cout << ans << endl;
    }
}