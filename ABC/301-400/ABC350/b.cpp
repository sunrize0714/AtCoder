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
    ll n,q;
    cin >> n >> q;
    vll t(q);
    rep(i,0,q)cin >> t[i];
    vll x(n,1);
    rep(i,0,q){
        t[i]--;
        if(x[t[i]] == 1)x[t[i]]--;
        else x[t[i]]++;
    }
    ll ans = 0;
    rep(i,0,n)ans += x[i];
    cout << ans << endl;
}