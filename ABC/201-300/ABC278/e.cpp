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
    ll H,W,n,h,w;
    cin >> H >> W >> n >> h >> w;
    vvll a(H,vll(W));
    rep(i,0,H)rep(j,0,W)cin >> a[i][j];
    vll xmin(n,1000),xmax(n,-1),ymin(n,1000),ymax(n,-1);
    rep(i,0,H)rep(j,0,W){
        a[i][j]--;
        xmin[a[i][j]] = min(xmin[a[i][j]],j);
        xmax[a[i][j]] = max(xmax[a[i][j]],j);
        ymin[a[i][j]] = min(ymin[a[i][j]],i);
        ymax[a[i][j]] = max(ymax[a[i][j]],i);
    }
    rep(i,0,H-h+1){
        rep(j,0,W-w+1){
            ll ans = n;
            rep(k,0,n){
                if(j<=xmin[k] && xmax[k] < j+w && i <= ymin[k] && ymax[k] < i+h)ans--;
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}