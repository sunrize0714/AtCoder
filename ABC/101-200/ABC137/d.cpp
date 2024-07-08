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
    ll n,m;
    cin >> n >> m;
    vll a(n),b(n);
    rep(i,0,n)cin >> a[i] >> b[i];
    vvll day(m+1);
    rep(i,0,n){
        if(a[i] <= m){
            day[a[i]].push_back(b[i]);
        }
    }
    ll now = 0;
    ll ans = 0;
    priority_queue<ll,vll,less<ll>> q;
    rep(i,1,m+1){
        rep(j,0,day[i].size())q.push(day[i][j]);
        if(!q.empty()){
            ll pos = q.top();q.pop();
            ans += pos;
        }
    }
    cout << ans << endl;
}