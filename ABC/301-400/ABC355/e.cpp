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

int main(){
    ll n,l,r;
    cin >> n >> l >> r;
    vp ans;
    while(l != r){
        ll i = 0;
        while(l%(1LL<<(i+1)) == 0 && l+(1LL<<i+1) <= r)i++;
        ans.push_back(make_pair(l,l/(1LL<<i)));
        l += 1LL<<i;
    }
    rep(i,0,ans.size())cout << ans[i].first;
    ll cnt = 0;
    rep(i,0,ans.size()){
        ll x = ans[i].first;
        rep(j,0,19)if(1LL<<j == x)x = j;
        ll y = ans[i].second;
        cout << "? " << x << " " << ans[i].first/(1LL<<x) << endl;
        ll pos;
        cin >> pos;
        cnt += pos;
    }
    cout << "! " << cnt%100 << endl;
    return 0;
}