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
    ll n;
    cin >> n;
    vll ans;
    ll pos = 11;
    while(ans.size() < n){
        ll x = pos;
        rep(i,2,sqrt(pos)+1){
            if(x%i==0){
                x /= i;
                break;
            }
        }
        if(x == pos){
            ans.push_back(pos);
        }
        pos += 5;
    }
    rep(i,0,ans.size())cout << ans[i] << " ";
}