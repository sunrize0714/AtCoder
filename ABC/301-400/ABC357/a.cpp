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

int main(){
    ll n,m;
    cin >> n >> m;
    vll h(n);
    rep(i,0,n)cin >> h[i];
    rep(i,1,n)h[i] += h[i-1];
    ll itr = upper_bound(all(h),m)-h.begin();
    cout << itr << endl;
}