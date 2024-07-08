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

ll modinv(ll a, ll m) {
    ll b=m,u=1,v=0;
    while(b){
        ll t=a/b;
        a-=t*b;swap(a,b);
        u-=t*v;swap(u,v);
    }
    u%=m; 
    if(u<0)u+=m;
    return u;
}

int main(){
    ll n,q;
    cin >> n >> q;
    vll x(q);
    rep(i,0,q)cin >> x[i];
    vll wa(q+1,0);
    map<ll,ll> mp;
    ll cnt = 0;
    rep(i,0,q){
        if(mp[x[i]] == 0){
            mp[x[i]] = 1;
            cnt++;
        }
        else{
            mp[x[i]] = 0;
            cnt--;
        }
        wa[i+1] = wa[i] + cnt;
    }

    vll ans(n,0);
    vll in_s(n,-1);
    rep(i,0,q){
        x[i]--;
        if(in_s[x[i]] == -1){
            in_s[x[i]] = i;
        }
        else if(x[i] == x[i-1]){
            in_s[x[i]] = -1;
            ans[x[i]] += wa[i]-wa[i-1];
        }
        else{
            ll cnt = wa[i];
            ans[x[i]] += cnt-wa[in_s[x[i]]];
            in_s[x[i]] = -1;
        }
    }
    rep(i,0,n){
        if(in_s[i] != -1){
            ans[i] += wa[q]-wa[in_s[i]];
        }
    }
    rep(i,0,n)cout << ans[i] << " ";
}