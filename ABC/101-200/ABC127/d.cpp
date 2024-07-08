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
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if(u < 0) u += m;
    return u;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll b(m),c(m);
    rep(i,0,m)cin >> b[i] >> c[i];
    map<ll,ll> d;
    vll ans;
    rep(i,0,n){
        d[a[i]]++;
        ans.push_back(a[i]);
    }
    rep(i,0,m){
        d[c[i]]+=b[i];
        ans.push_back(c[i]);
    }
    sort(all(ans));
    ans.erase(unique(all(ans)),ans.end());
    reverse(all(ans));
    ll cnt = n,val = 0,pos = 0;
    while(cnt){
        ll add = ans[pos];
        if(d[add] >= cnt){
            val += cnt*add;
            cout << val << endl;
            return 0;
        }
        else{
            val += add*d[add];
            cnt -= d[add];
        }
        pos++;
    }
}