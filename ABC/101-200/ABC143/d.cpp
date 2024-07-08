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
    vll l(n);
    rep(i,0,n)cin >> l[i];
    sort(all(l));
    ll ans = 0;
    rep(i,0,n-2){
        rep(j,i+1,n-1){
            rep(k,j+1,n){
                if(l[k] < l[i]+l[j])ans++;
            }
        }
    }
    cout << ans << endl;
}