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
    ll t;
    cin >> t;
    while(t--){
        ll a,s;
        cin >> a >> s;
        ll x = 0;
        rep(i,0,60){
            if(a & 1LL << i){
                x += 1LL<<i;
                s -= (1LL<<i)*2;
            }
        }
        if(s<0){
            cout << "No" << endl;
        }
        else{
            bool ok = true;
            rep(i,0,60){
                if(s&1LL<<i){
                    if(x&1LL<<i){
                        ok = false;
                    }
                }
            }
            if(ok)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}