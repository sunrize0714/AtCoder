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
    ll n;
    cin >> n;
    vll event;
    map<ll,ll> buy;
    rep(i,0,n){
        ll a,b;
        cin >> a >> b;
        buy[a]++,buy[b+1]--;
        event.push_back(a);
        event.push_back(b+1);
    }
    sort(event.begin(),event.end());
    event.erase(unique(event.begin(),event.end()),event.end());
    ll ans = 0;
    ll cnt = 0;
    ll pos = 0;
    while(cnt < event.size()){
        pos += buy[event[cnt]];
        ans = max(ans,pos);
        cnt++;
    }
    cout << ans << endl;
}