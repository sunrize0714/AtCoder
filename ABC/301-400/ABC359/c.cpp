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
    string s;
    cin >> s;
    ll ans = 1;
    vll x;
    ll cnt = 0;
    while(cnt+2 < n){
        if(s[cnt] == 'A' && s[cnt+1] == 'B' && s[cnt+2] == 'A'){
            x.push_back(cnt);
            cnt+=1;
        }
        if(s[cnt] == 'B' && s[cnt+1] == 'A' && s[cnt+2] == 'B'){
            x.push_back(cnt+1);
            cnt += 2;
        }
        cnt++;
    }
    x.push_back(1e10);
    ll pos = 1;
    rep(i,0,x.size()-1){
        if(x[i] == x[i+1]-2){
            pos++;
        }
        else{
            ans *= pos+1;
            ans %= mod;
            pos = 1;
        }
    }
    rep(i,0,x.size())cout << x[i] << endl;

    if(pos != 1)ans *= pos+1;
    cout << ans%mod << endl;
}