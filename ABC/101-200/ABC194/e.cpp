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
    ll n,m;
    cin >> n >> m;
    vll a(n);
    rep(i,0,n)cin >> a[i];
    vvll ans(n+1);
    rep(i,0,n+1)ans[i].push_back(0);
    rep(i,0,n){
        ans[a[i]].push_back(i+1);
    }
    rep(i,0,n+1)ans[i].push_back(n+1);
    rep(i,0,n+1){
        bool ok = true;
        rep(j,1,ans[i].size()){
            if(ans[i][j]-ans[i][j-1] > m)ok = false;
        }
        if(!ok){
            cout << i << endl;
            return 0;
        }
    }
}
