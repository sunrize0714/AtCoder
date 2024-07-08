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

int main(){
    ll n;
    cin >> n;
    vll a(n),b(n),c(n);
    rep(i,0,n)cin >> a[i];
    rep(i,0,n)cin >> b[i];
    rep(i,0,n)cin >> c[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    vll wa(n+1,0);
    rep(i,0,n){
        auto itr = upper_bound(c.begin(),c.end(),b[i]) - c.begin();
        wa[i+1] = wa[i] + n - itr;
    }
    ll ans = 0;
    rep(i,0,n){
        auto itr = upper_bound(b.begin(),b.end(),a[i]) - b.begin();
        ans += wa[n] - wa[itr];
    }
    cout << ans << endl;
}