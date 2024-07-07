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
    ll n;
    cin >> n;
    ll r = sqrt(n);
    ll ans = 1;
    ll up = 2;
    ll pos = 2;
    while(pos <= n){
        up++;
        pos *= 2;
    }
    pos /= 2;
    up--;
    ll cnt = 2;
    ll left = r;
    while(cnt <= up){
        ll ok = 1,ng = left+1;
        while(abs(ok-ng) > 1){
            ll mid = (ok+ng)/2;
            ll tmp = mid;
            rep(i,1,cnt){
                tmp *= mid;
                if(tmp > n){
                    ng = mid;
                    break;
                }
            }
            ok = mid;
        }
        ans += (left-ng+1)*(cnt-1);
        left = ok;
        cnt++;
    }
    set<ll> c;
    rep(i,2,sqrt(n)){
        ll pos = i;
        while(pos <= r){
            pos *= i;
        }
        pos/=i;
        while(pos >= i){
            ll to = pos;
            while(to <= n){
                if(to != pos){
                    if(c.count(to) == 0){
                        c.insert(to);
                    }
                    else ans--;
                }
                to *= pos;
            }
            pos /= i;
        }
    }
    cout << ans << endl;
    
}