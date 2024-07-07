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
    ll t;
    cin >> t;
    rep(i,0,t){
        ll n;
        cin >> n;
        for(int j=2;j*j*j <= n;j++){
            if(n%j == 0){
                if((n/j)%j == 0){
                    cout << j << " " << n/j/j << endl;
                    break;
                }
                else{
                    cout << ll(sqrt(n/j)) << " " << j << endl;
                    break;
                }
            }
        }
    }
}