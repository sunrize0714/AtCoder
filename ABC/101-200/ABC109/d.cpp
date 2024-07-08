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
    ll h,w;
    cin >> h >> w;
    vvll a(h,vll(w));
    rep(i,0,h)rep(j,0,w)cin>>a[i][j];
    vector<tuple<ll,ll,ll,ll>> ans;
    rep(i,0,h){
        rep(j,0,w-1){
            if(a[i][j]%2==1){
                a[i][j]--,a[i][j+1]++;
                ans.push_back(make_tuple(i+1,j+1,i+1,j+2));
            }
        }
    }
    rep(i,0,h-1){
        if(a[i][w-1]%2==1){
            a[i][w-1]--,a[i+1][w-1]++;
            ans.push_back(make_tuple(i+1,w,i+2,w));
        }
    }
    cout << ans.size() << endl;
    rep(i,0,ans.size())cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << " " << get<3>(ans[i]) << endl;
}