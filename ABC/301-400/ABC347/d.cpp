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
    ll a,b,c;
    cin >> a >> b >> c;
    ll cnt = 0;
    rep(i,0,61){
        if(c & 1LL<<i){
            cnt++;
        }
    }

    ll x=0,y=0;
    rep(i,0,61){
        if(c&1LL<<i){
            if(a > b){
                x += 1LL<<i;
                a--;
            }
            else{
                y += 1LL<<i;
                b--;
            }
        }
    }
    if(a != b || a < 0){
        cout << -1 << endl;
        return 0;
    }

    rep(i,0,60){
        if((x&(1LL<<i)) == 0 && (y&(1LL<<i)) == 0 && a > 0){
            x += 1LL<<i;
            y += 1LL<<i;
            a--,b--;
        }
    }
    if(a != 0){
        cout << -1 << endl;
        return 0;
    }
    cout << x << " " << y;
}