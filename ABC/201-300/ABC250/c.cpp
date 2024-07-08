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
    vll ans(n+1),pos(n+1);
    rep(i,1,n+1){
        ans[i] = i;
        pos[i] = i;
    }
    rep(i,0,q){
        ll x;
        cin >> x;
        if(pos[x] != n){
            ll l = pos[x],r = pos[x]+1;
            swap(ans[l],ans[r]);
            swap(pos[ans[l]],pos[ans[r]]);
        }
        else{
            ll l = pos[x],r = pos[x]-1;
            swap(ans[l],ans[r]);
            swap(pos[ans[l]],pos[ans[r]]);
        }
    }
    rep(i,1,n+1)cout << ans[i] << " ";
}