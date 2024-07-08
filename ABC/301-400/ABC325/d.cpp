#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
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
int main(){
    ll n;
    cin >> n;
    vll t(n),d(n);
    rep(i,0,n)cin >> t[i] >> d[i];
    rep(i,0,n)d[i] += t[i];
    priority_queue<ll,vll,greater<ll>> q;
    vp p;
    rep(i,0,n){
        p.push_back(make_pair(t[i],i));
    }
    p.push_back(make_pair(2000000000000000000,-1));
    sort(all(p));
    
    ll ans = 0;
    ll T = 0;
    rep(i,0,n){
        T = p[i].first;
        q.push(d[p[i].second]);
        while(!q.empty() && T < p[i+1].first){
            if(q.top() < T)q.pop();
            else{
                q.pop();
                ans++;
                T++;
            }
        }
    }
    cout << ans << endl;
}