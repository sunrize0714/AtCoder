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
    sort(all(a));
    rep(i,0,n){
        if(a[i] == 0)continue;
        rep(j,2,1001){
            ll pos = j*j;
            if(a[i] % pos == 0){
                while(a[i]%pos == 0){
                    a[i] /= pos;
                }
            }
        }
    }
    sort(all(a));
    map<ll,ll> s;
    vll x;
    rep(i,0,n){
        s[a[i]]++;
        x.push_back(a[i]);
    }
    sort(all(x));
    x.erase(unique(all(x)),x.end());
    ll ans = 0;
    rep(i,0,s.size()){
        if(x[i] == 0){
            ans += s[0] * (n-s[0]);
        }
        ans += s[x[i]]*(s[x[i]]-1)/2;
    }
    cout << ans << endl;
}