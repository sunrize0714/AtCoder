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
    ll n,m;
    cin >> n >> m;
    ll ans = 1;
    ll pos = m;
    map<ll,ll> mp;
    vll prime;
    rep(i,2,sqrt(m)+1){
        while(pos%i==0){
            prime.push_back(i);
            mp[i]++;
            pos/=i;
        }
    }
    if(pos!=1){
        mp[pos]++;
        prime.push_back(pos);
    }
    sort(all(prime));
    prime.erase(unique(all(prime)),prime.end());
    rep(i,0,prime.size()){
        ll p = mp[prime[i]];
        ll q = n-1+p;
        ll cnt = 1;
        //qCp
        rep(i,1,p+1){
            cnt *= q+1-i;
            cnt %= 1000000007;
            cnt *= modinv(i,1000000007);
            cnt %= 1000000007;
        }
        ans *= cnt;
        ans %= 1000000007;
    }
    cout << ans << endl;
}