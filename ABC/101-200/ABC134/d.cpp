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
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vll ans;
    map<ll,ll> mp;
    revrep(i,0,n){
        ll pos = i+1;
        if(mp[pos]%2 != a[i]){
            ans.push_back(pos);
            rep(j,1,sqrt(pos)+1){
                if(pos%j==0)mp[j]++;
            }
        }
    }
    cout << ans.size() << endl;
    rep(i,0,ans.size())cout << ans[i] << " ";
}