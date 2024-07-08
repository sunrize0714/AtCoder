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
 
ll dx4[4] = {1,0,-1,0};
ll dy4[4] = {0,-1,0,1};
ll dx8[8] = {1,1,0,-1,-1,-1,0,1};
ll dy8[8] = {0,-1,-1,-1,0,1,1,1};

int main(){
    ll h,w;
    cin >> h >> w;
    vs s(h);
    rep(i,0,h)cin >> s[i];
    string t;
    rep(i,0,w)t += '.';
    vs ans(h,t);
    rep(i,0,h){
        rep(j,0,w){
            if(s[i][j] != '#')continue;
            bool f = true;
            rep(k,0,8){
                ll x = dx8[k]+j,y = dy8[k]+i;
                if(x < 0 || x >= w || y < 0 || y >= h)continue;
                if(s[y][x] == '.'){
                    f = false;
                    break;
                }
            }
            if(f)ans[i][j] = '#';
        }
    }

    bool ok = true;
    rep(i,0,h){
        rep(j,0,w){
            if(s[i][j] != '#')continue;
            bool f = true;
            rep(k,0,8){
                ll x = dx8[k]+j,y = dy8[k]+i;
                if(x < 0 || x >= w || y < 0 || y >= h)continue;
                if(ans[y][x] == '#'){
                    f = false;
                    break;
                }
            }
            if(ans[i][j] == '#')f = false;
            if(f)ok = false;
        }
    }
    if(!ok)cout << "impossible";
    else{
        cout << "possible" << endl;
        rep(i,0,h)cout << ans[i] << endl;
    }
}