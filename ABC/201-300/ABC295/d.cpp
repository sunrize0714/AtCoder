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
    string s;
    cin >> s;
    map<string,ll> mp;
    string x = "0000000000";
    rep(i,0,s.size()){
        ll d = s[i] -'0';
        if(x[d]=='0')x[d]='1';
        else x[d]='0';
        mp[x]++;
    }
    ll ans=0;
    rep(i,0,1<<10){
        string y;
        rep(j,0,10){
            if(i&1<<j)y+='1';
            else y+='0';
        }
        ans += mp[y]*(mp[y]-1)/2;
    }
    cout << ans << endl;
}