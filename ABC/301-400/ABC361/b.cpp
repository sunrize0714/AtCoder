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
#define rrep(i,a,n) for(ll i=n-1;i>=a;i--)
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
    vll a(6),b(6);
    rep(i,0,6)cin >> a[i];
    rep(i,0,6)cin >> b[i];
    vll cnt(3,0);
    if(a[0] <= b[0] && b[0] < a[3])cnt[0]++;
    if(a[0] < b[3] && b[3] <= a[3])cnt[0]++;
    if(b[0] <= a[0] && a[0] < b[3])cnt[0]++;
    if(b[0] < a[3] && a[3] <= b[3])cnt[0]++;
    if(a[1] <= b[1] && b[1] < a[4])cnt[1]++;
    if(a[1] < b[4] && b[4] <= a[4])cnt[1]++;
   if(b[1] <= a[1] && a[1] < b[4])cnt[1]++;
    if(b[1] < a[4] && a[4] <= b[4])cnt[1]++;
    if(a[2] <= b[2] && b[2] < a[5])cnt[2]++;
    if(a[2] < b[5] && b[5] <= a[5])cnt[2]++;
    if(b[2] <= a[2] && a[2] < b[5])cnt[2]++;
    if(b[2] < a[5] && a[5] <= b[5])cnt[2]++;
    rep(i,0,3){
        if(cnt[i] == 0){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}