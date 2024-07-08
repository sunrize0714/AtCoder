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
    ll n,h;
    cin >> n >> h;
    vll a(n),b(n);
    rep(i,0,n)cin >> a[i] >> b[i];
    vp pow;
    rep(i,0,n)pow.push_back(make_pair(a[i],1));
    rep(i,0,n)pow.push_back(make_pair(b[i],0));
    sort(pow.begin(),pow.end(),greater());
    ll ans = 0;
    rep(i,0,n+1){
        if(pow[i].second == 1){
            ans += (h+pow[i].first-1)/pow[i].first;
            cout << ans << endl;
            return 0;
        }
        else{
            ans += 1;
            h -= pow[i].first;
            if(h <= 0){
                cout << ans << endl;
                return 0;
            }
        }
    }
}