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
    ll n,m;
    cin >> n >> m;
    vll t(m),w(m),s(m);
    rep(i,0,m)cin >> t[i] >> w[i] >> s[i];
    vll ans(n+1,0);
    set<ll> array;
    rep(i,1,n+1)array.insert(i);
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>> q;
    rep(i,0,m){
        q.push({t[i],w[i],s[i]});
    }
    while(!q.empty()){
        tuple pos = q.top();q.pop();
        if(get<1>(pos) >= 0){
            ll to = get<1>(pos);
            if(array.size()){
                auto itr = array.begin();
                ll f = *itr;
                ans[f] += to;
                q.push({get<0>(pos)+get<2>(pos),-1,f});
                array.erase(f);
            }
        }
        else{
            array.insert(get<2>(pos));
        }
    }

    rep(i,1,n+1)cout << ans[i] << endl;
}