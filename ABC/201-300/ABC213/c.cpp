#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll h,w,n;
    cin >> h >> w >> n;
    vll a(n),b(n);
    vll x,y;
    rep(i,0,n){
        cin >> a[i] >> b[i];
        y.push_back(a[i]);
        x.push_back(b[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    x.erase(unique(x.begin(),x.end()),x.end());
    y.erase(unique(y.begin(),y.end()),y.end());

    rep(i,0,n){
        auto itr = lower_bound(y.begin(),y.end(),a[i]) - y.begin();
        auto itr2 = lower_bound(x.begin(),x.end(),b[i]) - x.begin();
        cout << itr + 1 << " " << itr2 + 1 << endl;
    }
}