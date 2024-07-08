#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll,ll> pll;
typedef vector<pair<ll,ll>> vp;
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define revrep(i,a,n) for(ll i=n-1;i>=a;i--)
#define mod 998244353
#define all(a) a.begin(),a.end()

ll f(ll a,ll b){
    return a*a*a+a*a*b+a*b*b+b*b*b;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 2e18;
    rep(i,0,1000001){
        ll ok = 1e6,ng = -1;
        while(abs(ok-ng)>1){
            ll mid = (ok+ng)/2;
            if(n <= f(i,mid))ok = mid;
            else ng = mid;
        }
        ans = min(ans,f(i,ok));
    }    
    cout << ans << endl;
}
