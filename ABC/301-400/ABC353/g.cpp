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
    ll n,c;
    cin >> n >> c;
    ll m;
    cin >> m;
    vll t(m),p(m);
    rep(i,0,m)cin >> t[i] >> p[i];
    rep(i,0,m)t[i]--;
    vll shop(n,-1e18);
    shop[0] = 0;
    vll now;
    now.push_back(0);
    set<ll> st;
    st.insert(0);
    ll ans = 0;
    rep(i,0,m){
        rep(j,0,now.size()){
            ll pos = shop[now[j]];
            if(pos-abs(t[i]-now[j])*c+p[i] > shop[t[i]]){
                shop[t[i]] = pos-abs(t[i]-now[j])*c+p[i];
            }
        }
        if(st.count(t[i]) == 0){
            now.push_back(t[i]);
            st.insert(t[i]);
        }
    }
    rep(i,0,n)ans = max(ans,shop[i]);
    cout << ans << endl;
}