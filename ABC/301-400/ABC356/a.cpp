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
    ll n,l,r;
    cin >> n >> l >> r;
    vll a(n);
    rep(i,0,n)a[i] = i+1;
    reverse(a.begin()+l-1,a.begin()+r);
    rep(i,0,n)cout << a[i] << " ";
}