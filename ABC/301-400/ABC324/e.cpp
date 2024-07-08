#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<vvvll> vvvvll;
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
    string t;
    cin >> n >> t;
    vs s(n);
    rep(i,0,n)cin >> s[i];
    vll m1;
    rep(i,0,n){
        ll cnt = 0;
        rep(j,0,s[i].size()){
            if(s[i][j] == t[cnt])cnt++;
        }
        m1.push_back(cnt);
    }
    vll m2;
    reverse(all(t));
    rep(i,0,n){
        reverse(all(s[i]));
        ll cnt = 0;
        rep(j,0,s[i].size()){
            if(s[i][j] == t[cnt])cnt++;
        }
        m2.push_back(cnt);
    }
    ll ans = 0;
    sort(all(m1));
    sort(all(m2));
    rep(i,0,m1.size()){
        ll pos = t.size() - m1[i];
        auto itr = lower_bound(all(m2),pos) - m2.begin();
        ans += n - itr;
    }
    cout << ans << endl;
}