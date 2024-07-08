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
    ll n;
    cin >> n;
    vll prime;
    rep(i,2,300004){
        ll pos = i;
        if(prime.size()!=0){
            rep(j,0,prime.size()){
                if(pos%prime[j]==0){
                    pos = 0;
                    break;
                }
                if(pos==0)break;
            }
        }
        if(pos == i)prime.push_back(pos);
    }

    ll ans = 0;
    rep(i,0,prime.size()){
        rep(j,i+1,prime.size()){
            rep(k,j+1,prime.size()){
                ll pos = prime[i]*prime[j]*prime[i];
                if(pos > n)break;
                if(pos <= n/(prime[k]*prime[k]))ans++;
                else break;
            }
        }
    }
    cout << ans << endl;
}