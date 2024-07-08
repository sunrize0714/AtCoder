#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353

int main(){
    ll n,d;
    cin >> n >> d;
    ll ans = 0;
    rep(i,0,n){
        ll x,y;
        cin >> x >> y;
        if(x*x+y*y<=d*d)ans++;
    }
    cout << ans << endl;
}