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
    ll n,l,d;
    cin >> n >> l >> d;
    double dice = 1.0/double(d);
    vector<double> p(n+d+1,0.0);
    p[0] = 1.0;
    vector<double> deal(l+d+1,0.0);
    deal[0] = 1.0;
    rep(i,0,l){
        double pos = deal[i];
        deal[i] = 0;
        rep(j,1,d+1)deal[i+j] += pos*dice;
    }
    rep(i,l,l+d+1)deal[i+1] += deal[i];
    rep(i,0,n-d/2){
        double now = p[i];
        p[i] = 0;
        rep(j,1,d+1){
            p[i+j] += dice*now;
        }
    }

    rep(i,0,n+d)p[i+1] += p[i];
    double ans = 0.0;
    ans += 1.0 - deal[n-1];
    double x = p[n-1];
    rep(i,l,n){
        double dealer = deal[i] - deal[i-1];
        ans += dealer*max(0.0,x-p[i]);
    }
    cout << ans << endl;
}