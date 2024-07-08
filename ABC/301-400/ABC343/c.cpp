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
    ll n;
    cin >> n;
    ll ans = 0;
    rep(i,1,1000001){
        if(i*i*i > n)break;
        else{
            ll pos = i*i*i;
            ll pos2 = pos;
            vll x;
            while(pos > 0){
                x.push_back(pos%10);
                pos /= 10;
            }
            ll s = x.size();
            ll cnt = 0;
            bool f = true;
            while(cnt < s-cnt-1){
                if(x[cnt] != x[s-cnt-1]){
                    f = false;
                    break;
                }
                cnt++;
            }
            if(f)ans = pos2;
        }
    }
    cout << ans << endl;
}