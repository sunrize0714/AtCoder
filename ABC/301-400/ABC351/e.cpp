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
#define all(a) a.begin(),a.end()

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
    vll x(n),y(n);
    rep(i,0,n)cin >> x[i] >> y[i];
    vp even,odd;
    rep(i,0,n){
        if(x[i]%2 == y[i]%2)even.push_back(make_pair(x[i],y[i]));
        else odd.push_back(make_pair(x[i],y[i])); 
    }
    multiset<ll,ll> od,ev;
    rep(i,0,odd.size())od.insert(odd[i].first-odd[i].second);
    rep(i,0,even.size())ev.insert(even[i].first-even[i].second);
    vll used;
    ll ans = 0;
    sort(all(odd)),sort(all(even));
    rep(i,0,odd.size()){
        od.erase(odd[i].first-odd[i].second);
        ll x = upper_bound(all(used),odd[i].first-odd[i].second) - used.begin();
        ans -= x*odd[i].first;
        ans -= 
        used.push_back(odd[i].first-odd[i].second);
    }
    cout << ans << endl;
}