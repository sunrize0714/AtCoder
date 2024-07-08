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
    ll n,m,l,q;
    cin >> n;
    vll a(n);
    rep(i,0,n)cin >> a[i];;
    cin >> m;
    vll b(m);
    rep(i,0,m)cin >> b[i];
    cin >> l;
    vll c(l);
    rep(i,0,l)cin >> c[i];
    cin >> q;
    vll x(q);
    rep(i,0,q)cin >> x[i];
    sort(all(a)),sort(all(b)),sort(all(c));
    map<ll,ll> mp;
    rep(i,0,n)rep(j,0,m)rep(k,0,l)mp[a[i]+b[j]+c[k]]++;
    rep(i,0,q){
        if(mp[x[i]] == 0)cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}